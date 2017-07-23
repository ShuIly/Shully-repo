#!/usr/bin/env bash
 
image=$(mktemp).png
 
param=(--textcolor=ffffff00 --insidecolor=faddc500 --ringcolor=fafafa00 \
    --linecolor=2d283e00 --keyhlcolor=000000aa --ringvercolor=fadd5caa \
    --separatorcolor=22222200 \
    --insidevercolor=fadd5c00 \
    --ringwrongcolor=f13459aa --insidewrongcolor=f1345900)
 
ffmpeg -loglevel quiet -y -s 1920x1080 -f x11grab -i $DISPLAY -vframes 1 -vf "gblur=sigma=16" "$image"
 
# seems to work 0.2s faster than mogrify
convert "$image" ~/Pictures/overlay.png -gravity center -composite "$image"
 
i3lock "${param[@]}" -i "$image"
