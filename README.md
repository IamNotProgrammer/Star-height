# Star-hegiht


## Installation

To install program download from the [latest release](https://github.com/IamNotProgrammer/Star-height/releases) `star-height` and `Data.tar.gz` files. `star-height` is already compiled program for processor x86_64 (so idk if it will work for you) so all you need to do with it is to move it. Go to the directory where files where downloaded and then run these commands

    $ sudo mv ./star-height /usr/local/bin/
    $ tar -xvzf ./Data.tar.gz

Moving binary file to `/usr/local/bin/` will assure that you can run program form any other place in file system. After extracting Data directory it's time to move it to it's position

    $ sudo mv ./Data/ /usr/local/

It's very important to move it to this position otherwise program won't work. Now you can just remove compressed file

    $ rm ./Data.tar.gz

You can enjoy program by running

    $ star-height

***
There's other method by compiling it yourself. First make sure you have installed qmake and git. On Ubuntu or Linux Mint run

    $ sudo apt-get install qt5-default
    $ sudo apt-get install git

On Manjaro or Arch use pacman

   $ sudo pacman -S qt5-base
   $ sudo pacman -S git

On Gentoo you don't need instructions

Then download code files and run installing script

   $ git clone https://github.com/IamNotProgrammer/Star-height.git
   $ cd ./Star-height/
   $ ./star_install.sh 

Installation script should automatically build and install program. After script is done that's everything you needed to do, you can check out program now.

## What even is Star-height?

Star-height is program for planning astronomical observations.
In given time in position it calculates local sidereal time,
horizontal coordinates (elevation and azimuth) and galactic coordinates and more.

It is tool designed for astronomers but it can also be used for amatours to find out when it's the best time
to observe object in the sky.

It features:

* Local sidereal time
* Horizontal coordinates
* Galactic coordinates
* Highest elevation and time to it
* Current ekevation
* Set current time button
* Searching object (over 10 million objects available)
* List of observatories
* Including refraction in calculations

## Why should I use this instead stellarium?

That's great question. Stellarium doesn't show local sidereal time which is the only imperfection in stellarium unlike my program where LST is the only perfect thing

## Screenshots


Calculate everything you need

 ![alt text](https://raw.githubusercontent.com/IamNotProgrammer/Star-height/master/screenshots/Screenshot_20200219_190134.png)
 
 Include refraction
 
 ![alt text](https://raw.githubusercontent.com/IamNotProgrammer/Star-height/master/screenshots/Screenshot_20200219_190246.png)
 
 Find your object
 
 ![alt text](https://raw.githubusercontent.com/IamNotProgrammer/Star-height/master/screenshots/Screenshot_20200219_190337.png)
