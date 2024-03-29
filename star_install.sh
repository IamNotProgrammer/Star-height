#!/bin/bash

# Compile program

mkdir build
qmake -o ./build/ ./GUI/GUI.pro
make -C ./build/

# Touching file ( ͡° ͜ʖ ͡°)

sudo touch ./Data/saved.txt

# Giving permissions so program can open files

sudo chmod 755 ./build/star-height
sudo chmod -R 755 ./Data/
sudo chmod -R 766 ./Data/Images

#sudo chown root:root ./build/star-height

# Moving files to the right place
# ./Data/ must be in fixed place

sudo mv ./build/star-height /usr/local/bin/
sudo mv ./Data/ /usr/local/

