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
Go to ./Star-height/ and make 'build' directory and go there
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
