#!/bin/bash

mkdir build
qmake -o ./build/ ./GUI/GUI.pro
make -C ./build/

sudo chmod +x ./build/star-height
sudo chmod 666 ./Data/object.txt

sudo mv ./build/star-height /usr/local/bin/
sudo mv ./Data/ /usr/local/
