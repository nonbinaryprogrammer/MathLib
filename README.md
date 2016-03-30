# BigInt Math Library

## About This Project
This is a math library implemented in C++ (but mostly written in the style of
C). It was created for my use on Project Euler problems, which require the use
of very long numbers. In order to complete those problems, I needed a way to
store numbers much larger than can be stored in a standard data type.

## About BigInt
BigInt is a class that has a count of digits, and an array of digits. The math
library is primarily operator overrides for use with BigInts, along with a few
other functions. The method of storing BigInts is the most interesting thing
about this class. Instead of storing them with the most significant bit (MSB) on
the left and least significant bit (LSB) on the right, this stores the MSB on
the right (at index digits-1 of the array) and the LSB on the left (at index 0
of the array). This allows for easily making the number larger (or smaller)
without having to move the whole thing over.

## About Operator Overrides
The development of operator overrides for BigInts is an ongoing process. Many
have already been implemented but could be made much more efficient. The goal of
implementing all these operator overrides is to make the use of these BigInts as
intuitive and readable as possible. The operators take BigInts on the left and
int, long, string, or BigInt on the right.

## About Testing
The tests are contained within math.cpp. That file gives a pretty good example
of usage of the library. The tests are fairly thorough with testing, but
extensive testing of different numbers could be added as an improvement.

## About Using The Math Library
This math library can be downloaded from Github and stored locally. The
mathlib.h file can then be referenced in a .cpp file as demonstrated in
math.cpp. The library can also be used in a C file, but the g++ compiler must be
used since classes are not valid in the gcc compiler.

## About Contributing
Feel free to use this repo, and to fork it if you want to adapt it for some
other purpose. I welcome contributions. Please create a branch/issue/pull
request! Please comment any code that you wish to add, or I probably won't
review it...

### Helena Bales
