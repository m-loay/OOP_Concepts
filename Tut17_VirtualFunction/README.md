#Tut17_VirtualFunction
Object Oriented Programming 

The purpose of the tutorial
when using base pointer to derived object , it called the base functionality
in the object only.

So Using virtual functions and base pointer to derived object , the compiler
construct a v-table(According to inheritance hierarchy) and call the member function
associated with the object being pointed not the type of the pointer.

1. mkdir Debug
2. cd Debug
3. cmake .. -G "MinGW Makefiles" (Windows OS)
   or cmake ..  (Linuex OS)
4. make



## Other Important Dependencies
* cmake >= 3.5

  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
 
* gcc/g++ >= 4.8
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: cmake .. && make --> (Linuex OS) or
            cmake .. -G "MinGW Makefiles" & make --> (Windows OS)
