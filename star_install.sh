#!/bin/bash

mkdir build
qmake -o ./build/ ./GUI/GUI.pro
make -C ./build/

sudo chmod +x ./build/star-height
sudo chmod -R 666 ./Data/
sudo chmod 755 ./Data/
sudo chmod 755 ./Data/Observatories/
sudo chmod 755 ./Data/Images/
sudo chmod 755 ./Data/Plot.gnu

sudo chown root:root ./build/star-height
sudo chown $USER:$USER ./Data/Observatories/
sudo chown $USER:$USER ./Data/Observatories/*

sudo mv ./build/star-height /usr/local/bin/
sudo cp -r ./Data/ /usr/local/
