## Tut4_Async_basics

 Object Oriented Programming 

The purpose of the tutorial to learn basics of async.
By showing two examples problem & solution.
In problem the main task is blocked by Download taks and has to
wait until download finishes.

In solution the main task will execute first then the Download taks.

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