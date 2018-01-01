## Tut16_Derived_Class Member Function Calls Via Base Class Pointers

 Object Oriented Programming 

1)The base class object pointer can be assigned to derived object,
but can only invoke base class functionality in the derived object.

2)In inheritance , the derived class can overridden a definition of
a member function of base class

3)A member function of base class can be called in derived class
baseClassName::function name , as it appears in earning member function.

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