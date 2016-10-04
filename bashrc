areumlee@ubuntu:~$ cat .bashrc
# ~/.bashrc: 비로그인 셸들은 bash(1)에 의해 실행된다.
# /usr/share/doc/bash/examples/startup-files을 봐라 (bash-doc패키지의)
# 예를 들면
# 쌍방향으로 실행되지 않는다면, 아무것도 하지 마라.
case $- in
    *i*) ;;
      *) return;;
esac
# 중복되는 라인이나 공백으로 시작되는 라인을 히스토리에 넣지 마라.
# 더 많은 옵션은 bash(1)에서 확인해라.
HISTCONTROL=ignoreboth
# 히스토리 파일에 덧붙이되, 덮어쓰지는 마라.
shopt -s histappend
# 히스토리 길이를 설정하려면 bash(1)에 있는 HISTSIZE와 HISTFILESIZE를 보아라.
HISTSIZE=1000
HISTFILESIZE=2000
# 각 명령 뒤에 윈도우 사이즈를 확인하고 필요하다면,
# 행과 열의 값을 업데이트해라.
shopt -s checkwinsize
# 설정했다면, 패스네임 확장 문맥에 사용된 “**” 패턴은
# 모든 파일과 0개 혹은 그 이상의 디렉토리, 서브디렉토리와 일치할 것이다.
#shopt -s globstar
# 비 텍스트 입력 파일에 대해 더욱 덜 친근하게 만들고, lesspipe(1)을 보아라.
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"
# 당신이 사용하는 chroot를 식별하는 변수를 설정한다 (프롬프트 하에서 사용되는)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi
# 화려한 프롬프트를 설정한다 (우리가 색을 “원하지”않는 이상 색이 아닌 부분을 말한다))
case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac
# 터미널이 가능하다면, 색이 있는 프롬프트의 주석처리를 지운다.
# 사용자에게 혼란을 주지 않기 위해 디폴트 값을 해제하라. 터미널 창은
# 프롬프트가 아닌, 명령의 결과에 초점이 맞추어 있어야한다.
#force_color_prompt=yes
if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
    # 우리는 컬러 지원이 가능하다. Ecma-48를 따른다고 가정하자
    # (ISO/IEC-6429). (이러한 지원의 부족은 극히 드물고, 이러한
    # 케이스는 setaf보다 setf를 지원하는 게 대부분이다.
    color_prompt=yes
    else
    color_prompt=
    fi
fi
if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt
# 만약 이것이 xterm이라면, 제목을 user@host:dir로 설정해라.
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac
# ls의 색 지원을 가능하게 하고, 또한 간편한 별명들을 추가하라
 if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'
    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi
# colored GCC warnings and errors
#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'
# 더 많은 ls 별명들
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'
# 장기간 실행되는 명령어를 위해 “alert”별명을 더해라. 다음과 같이 사용한다:
#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
# 별명 정의
# 부가적인 것 모두를 분리된 파일로 넣기를 원할지도 모른다. 
# ~/.bash_aliases이 위치에 직접 추가하는 대신
# /usr/share/doc/bash-doc/examples bash-doc 패키지 안의 다음 경로를 보아라
if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi
# 사용가능하며 프로그램 가능한 완료 특징들
# (그것이 이미 /etc/bash.bashrc 와 /etc/profile에서 사용가능하게 설정되어 있다면 당신이 이것을 사용 가능하게 할 필요는 없다)
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi
 

