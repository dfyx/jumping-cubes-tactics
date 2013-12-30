# Jumping Cubes Tactics
This is a proof of concept implementation of a game codenamed *Jumping Cubes
Tactics*.

## Dependencies
To build this project, you need [CMake](http://www.cmake.org/) and
[SFML](http://www.sfml-dev.org/). You can install both through your favorite
package manager.

### On Mac OS X
```bash
brew install cmake sfml
```

### On Debian/Ubuntu
```bash
sudo apt-get install libsfml-dev cmake
```

## Compiling
This project uses CMake as its build system. The easiest way to build and run
it is the following:

```bash
mkdir build
cd build
cmake ..
make
./jct_sfml
```

On Windows you should probably use the graphical CMake frontend to generate a
Visual Studio project.

## TODO
* A better way to indicate who is next
* Scrolling/zooming
* Nicer graphics
* Sound
* Networking
* AI
* Main menu
* A short introduction how to play (both in the game and in the readme)

## Contributing
If you want to help with this project, feel free to fork it or send a message
to @dfyx.