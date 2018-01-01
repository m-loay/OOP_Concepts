##Tut5_Constref Vs ref

 Object Oriented Programming 

This tutorial shows hthe difference in sending objects by value and by reference.
Also , which passing mechanism requires calling the copy constructor.   
1)To understand passing object to function mechanisms.
2)Send object by value requires calling the default copy constructor.
3)Send object by reference will not require calling the copy constructor  and it allows modifying the object.
4)Send the object by constant reference , will disallow modifying the object.

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
2. Make a build directory: `mkdir Debug && cd Debug`
3. Compile: cmake .. && make --> (Linuex OS) or
            cmake .. -G "MinGW Makefiles" & make --> (Windows OS)