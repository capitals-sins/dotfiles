#!/bin/bash
# changeVolume

# Arbitrary but unique message id
msgId="991039"

# Change the volume using alsa(might differ if you use pulseaudio)
amixer -c 0 set Master "$@" > /dev/null

# Query amixer for the current volume and whether or not the speaker is muted
volume=" $(amixer get Master | grep '%' | head -n 1 | cut -d '[' -f 2 | cut -d '%' -f 1) "
mute="$(amixer -c 0 get Master | tail -1 | awk '{print $6}' | sed 's/[^a-z]*//g')"
if [[ $volume == 0 || "$mute" == "off" ]]; then
    # Show the sound muted notification
    dunstify -i /home/marko/.icons/AD-Kiwi-Suru/apps/32/sirikali.svg -r "$msgId" "Volume muted" 
else
    # Show the volume notification
    dunstify -i /home/marko/.icons/AD-Kiwi-Suru/apps/32/audio.svg -r "$msgId" \
    "${volume}%" "$(getProgressString 10 "<b> </b>" " " $volume)"
fi

# Play the volume changed sound
#canberra-gtk-play -i audio-volume-change -d "changeVolume"
