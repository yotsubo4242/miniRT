#!/bin/bash

FILES=($(find scenes -type f -exec basename {} \;))

for file in "${FILES[@]}"
do
    echo "$file"
    ./miniRT ./scenes/"$file" &
	./miniRT ./scenes/ok/"$file" &
	./miniRT ./scenes/ng/"$file" &
    read -p "Press Enter to display the next file: " 
done