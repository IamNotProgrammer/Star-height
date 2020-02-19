# Star-hegiht


## Instalation

#### Downloading program

---

To download program star-hegiht you can simply download latest version of star-height from this site
with Data.tar.gz (it's important if you want to find object)
https://github.com/IamNotProgrammer/Star-height/releases

It's working really good and doesn't need to be compiled. After downloading file find directory where it was downloaded
and go there
```sh
$ cd /path/to/directory
```
Then untar Data.tar.gz
```sh
$ tar -xvf Data.tar.gz
```

Move binary file and Data directory
```sh
$ sudo mv ./star-height /usr/local/bin/
$ sudo mv ./Data/ /usr/local/
```

Give permissions
```
$ sudo chmod +x /usr/local/bin/star-height
$ sudo chmod 666 /usr/local/Data/object.txt
```
And it's done. You can enjoy program by simply opening it with terminal
```sh
$ star-heit
```
This version of program is stable but it may not contain most recent features



#### Compiling program

---

qmake is required to compile files. If you don't have it installed install it

1. On Ubuntu
```sh
$ sudo apt-get install build-essential
$ sudo apt-get install qt5-default
```

2. On Arch, the superior distro
```sh
$ sudo pacman -S qt
```


Then clone repository
```sh
$ git clone https://github.com/IamNotProgrammer/Star-height.git
```
Go to `./Star-height/` directory, give permission to execute install file
```sh
$ cd ./Star-hegiht/
$ sudo chmod +x ./star_install.sh
$ ./star_install.sh
```

Bash script will automatically install program and move all files to the right place.
Run program to check if everything is working.

```sh
$ star-height
```

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
* Searching object
* List of observatories
* Including refraction in calculations

##Screenshots

 ![alt text](https://raw.githubusercontent.com/IamNotProgrammer/Star-height/master/screenshots/Screenshot_20200219_190134.png)
 
 ![alt text](https://raw.githubusercontent.com/IamNotProgrammer/Star-height/master/screenshots/Screenshot_20200219_190246.png)
 
 ![alt text](https://raw.githubusercontent.com/IamNotProgrammer/Star-height/master/screenshots/Screenshot_20200219_190337.png)
