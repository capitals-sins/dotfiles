#!/bin/sh

  brightness=$(xbacklight -get | cut -d '.' -f 1) 
  # Make the bar with the special character ─ (it's not dash -)
  # https://en.wikipedia.org/wiki/Box-drawing_character
  bar=$(seq -s "─" 0 $((brightness / 5)) | sed 's/[0-9]//g')
  # Send the notification
  dunstify -i /home/marko/.icons/AD-Kiwi-Suru/apps/32/pushy.svg -r 5555 -u normal "$bar"

#canberra-gtk-play -i audio-volume-change -d "changeVolume"
