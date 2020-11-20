## Tut3_HandlingExcep_stackWinding

 Object Oriented Programming 

The purpose of the tutorial to learn about stack unwinding
  1.When local object is created inside function , and this function throws an exception.
    The stack of this function properly destroyes(Stack unwinded) and the destructor of local object
    will be called.
  2.When object allocated in heap inside a function, and this function throw an exception.
    The stack of this function properly destroyes(Stack unwinded) and the destructor of local object
    will nor be called casing memory leak.

  3.To solve the previous issue , smart pointers should be used instead raw pointers,
    vector instead pointer arrays and strings instead pointer arrays char type.

# Other Important Dependencies
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
2. Make a build directory: `mkdir Debug && cd Debug`
3. Compile: cmake .. && make --> (Linuex OS) or
            cmake .. -G "MinGW Makefiles" & mingw32-make --> (Windows OS)			