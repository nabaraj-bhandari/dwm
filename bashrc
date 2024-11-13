[[ $- != *i* ]] && return
PS1="\[$(tput setaf 10)\]\u@\h \[$(tput setaf 255)\]| \[$(tput setaf 14)\]\d \[$(tput setaf 255)\]| \[$(tput setaf 14)\]$(date +'%H:%M') \[$(tput setaf 255)\]: \[$(tput setaf 12)\]\w \[$(tput setaf 255)\]\$ "

alias ls='ls --color=auto'
alias ll='ls -la --color=auto'
alias grep='grep --color=auto'
alias x='clear && exit'
alias bs='sudo systemctl restart bluetooth'
alias ns='systemctl restart NetworkManager'
alias zz='shutdown now'
alias rs='reboot'
alias nf='neofetch'
alias bc="bluetoothctl connect $(echo $(bluetoothctl devices) | awk '{print $2}')"
alias bx='bluetoothctl disconnect'

# YouTube
alias z='ytfzf'
alias za='ytfzf -a'
alias zs='ytfzf -a -m'
alias vd='cd && cd Videos && ytfzf -d'
alias sd='cd && cd Music && ytfzf -d -m'
alias pvd='cd && cd Videos && yt-dlp --ignore-errors --format 251+137 --output "%(title)s.%(ext)s" --yes-playlist --playlist-start'
alias psd='cd && cd Music && yt-dlp --ignore-errors --format 251 --extract-audio --output "%(title)s.%(ext)s" --yes-playlist --playlist-start'

# Pacman
alias i='sudo pacman -S'
alias pl='pacman -Q | less'
alias rem='sudo pacman -Rs $(pacman -Qqtd)'
alias u='sudo pacman -Syyuu'

# Music
alias m='cd && mpv --shuffle --loop-playlist Music'
#alias m='cd && mpv --shuffle -loop-playlist --no-audio-display Music'
alias ms='cd && cd Music && mpv --no-video-aspect-override --loop-playlist'
#alias ms='cd && cd Music mpv --loop-playlist --no-audio-display'
alias v='cd && cd Videos && mpv *.m*'