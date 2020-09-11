#!/bin/sh
if [ -d /etc/X11/xinit/xinitrc.d ] ; then
    for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
        [ -x "$f" ] && . "$f"
    done
    unset f
fi

killall dunst &
/usr/bin/dunst &
xrdb -merge ~/.Xresources &
feh --bg-fill $HOME/Imágenes/black-dragon.jpg &
$HOME/1999/./dwmstatus.sh &
setxkbmap latam &
wmname "LG3D" &
paplay $HOME/Música/shake.wav &
exec dbus-run-session dwm
