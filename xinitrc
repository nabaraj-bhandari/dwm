# Pipewire
/usr/bin/pipewire &
/usr/bin/pipewire-pulse &
/usr/bin/pipewire-media-session &

# Keyboard Layout
setxkbmap us &

# Display Resolution
xrandr --output eDP-1 --mode 1920x1080 &

# Compositor
picom -f &

# Wallpaper
nitrogen --restore &

# Status Bar
slstatus &

# Loop
while true; do
	dwm >/dev/null 2>&1
done

# Execute DWM
exec dwm
