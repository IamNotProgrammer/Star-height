#!/bin/bash

mkdir build
qmake -o ./build/ ./GUI/GUI.pro
make -C ./build/

sudo chmod 755 ./build/star-height
sudo chmod -R 755 ./Data/

sudo chown root:root ./build/star-height

sudo mv ./build/star-height /usr/local/bin/
sudo cp -r ./Data/ /usr/local/

