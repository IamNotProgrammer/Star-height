# Star-hegiht


## Instalation

#### Downloading program

---

To download Star-hegiht you can simply download latest version from this site
https://github.com/IamNotProgrammer/Star-height/releases

It's working really good and doesn't need to be compiled. After downloading file find directory where it was downloaded,
then use command
```sh
$ sudo mv /path/to/directory /usr/local/bin/
```
And it's done. You can enjoy program by simply opening it with terminal
```sh
$ Star-heit
```
This version of program is stable but it may not contain most recent features



#### Compiling program

---

Clone repository
```sh
$ git clone https://github.com/IamNotProgrammer/Star-height.git
```
Go to `./Star-height/` directory, create `build` directory and go there
```sh
$ cd ./Star-hegiht/
$ mkdir build
$ cd ./build/
```
Make there 'Makefile'
```sh
$ qmake ../GUI/GUI.pro
```
Compile it
```sh
$ make
```
Now when it's compiled we can move program and Data directory where it should be in order to work properly

```sh
$ sudo mv ./GUI /usr/local/bin/Star-height
$ cd ..
$ sudo mv ./Data /usr/local/
```

## What even is Star-height?

Star-height is program for planning astronomical observations. In given time in position it calculates local sidereal time, horizontal coordinates (elevation and azimuth) and galactic coordinates and more.
It is tool designed for astronomers but it can also be used for amatours to find out when it's the best time to observe object in the sky.

