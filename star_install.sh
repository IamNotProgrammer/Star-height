#!/bin/bash

# Compile program

mkdir build
qmake -o ./build/ ./GUI/GUI.pro
make -C ./build/

# Touching file ( ͡° ͜ʖ ͡°)

touch ./Data/saved.txt

# Giving permissions so program can open files

sudo chmod 755 ./build/star-height
sudo chmod -R 755 ./Data/
sudo chown -R $USER ./Data/

sudo chown root:root ./build/star-height

# Moving files to the right place
# ./Data/ must be in fixed place

sudo mv ./build/star-height /usr/local/bin/
sudo cp -r ./Data/ /usr/local/

