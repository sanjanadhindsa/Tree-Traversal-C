# Project 2

__Due date: October 23 at 11:55pm.__

---
**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own.
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

## Makefile and Testing

The `Makefile` provided with this project compiles and builds all of the required programs. __Your code will be compiled using this `Makefile` by the graders and it is your responsibility to make sure that your code can be compiled successfully on `crackle1`!__

To compile and build all of the programs run:

    make all

To compile and build individual problems run:

    make problem1
    make problem2

To run simple tests  on each program you can execute

    make run_problem1
    make run_problem2

(You should test your code much more extensively than these simple test cases provided with the assignment do.)



To remove all previously compiled and built files, run

    make clean

## Building and compiling with multiple files.

Majority of the programs you write consist of more than a single file. The organization of
programs with multiple files in C follows somewhat different rules than in Java.

In general the goal is to separate declaration of functions and definitions of functions.
The declarations are written in the header files (the ones with a .h extension) and the corresponding
definitions are provided in the source code files (the ones with a .c extension).

In order to create an actual program we need to make sure that the compiler proper
knows about the locations of the header files and that the linker knows where the
definitions are. This requires something called _separate compilation_. You can find a detailed tutorial
on the topic at
_[A Tutorial on Separate Compilation in C/C++](http://www.compsci.hunter.cuny.edu/~sweiss/resources/separateCompilation.pdf)_ by Stewart Weiss or any C programming textbook.

For the purpose of this assignment here are a few facts you need to know about.

- All function declarations are provided for you in the header files. You should add to those files
declarations for any other functions that you create.

- The content of the header file is surrounded by header guards. These are preprocessor
directives that prevent the declarations to be included multiple times within a single program
(this confuses the linker). Here is an example of a header guard:

      #ifndef FILENAME_H_
      #define FILENAME_H_
        //content of the file  
      #endif

- There are a few ways to compile your programs (although you should just use the
  provided `Makefile` to do so). Assume that the program consists of three source code
  files `f1.c`, `f2.c` and `main.c` and two header files `f1.h` and `f2.h`.
    - Compile everything together (not a good idea if you have a lot of code):

          gcc f1.c f2.c main.c -o progname

    - Compile each file separately and combine them into a sinlge program (this way
      if changes are made to the source code of one file, only that one file needs to
      be recompiled):

          gcc -c f1.c
          gcc -c f2.c
          gcc -c main.c
      (this produced three object files called `f1.o`, `f2.o` and `main.o`)

          gcc f1.o f2.o main.o -o progname

- __Dos and don'ts__ of separate compilation
    - NEVER use the `#include` directive to include a file with the `.c` extension.
    You should include the corresponding header file instead.
    - NEVER include the list of the header files when compiling the code using
    `gcc`. The header files are brought in by the preprocessor when it scans your code.


## Compiling with a math library

In order to use any functions declared in the `math.h` header file, you need to link
your programs with the math library. To do so, you need to add `-lm` flag during the
execution of gcc. For example:

```
gcc problem2.c -lm -o problem2
```

(`-l` option specifies that what follows is the library name. `m` is the name of the math library.)


## Programming requirements:

- __The programs should be leak-free: any memory that is allocated should be freed before the program terminates.__
- The programs have to be documented! Any file that you edit should have preamble
 including your name as the author, description of the purpose of the program and
 inline comments in the functions that you implement. All functions except for `main()` should
 have descriptions of function parameters, returned value and a summary of what the function does.
- The code has to build correctly using the provided `Makefile`.
- The code has to follow C programming conventions.
- The code has to be formatted properly.  


## Problem 1 (10 points)

This program performs basic operations on a binary search tree.
It reads a sequence of instructions from the standard input stream
and outputs the results to the standard output stream.

The program accepts the following instructions:

- `a value` and the `value` to the tree
- `s` remove the smallest value stored in the current tree (should have no effect
  if the current tree is empty)
- `l` remove the largest value stored in the current tree (should have no effect
  if the current tree is empty)
- `p` print the values stored in the current tree in order of the inorder traversal

The `main` function in `problem1.c` reads and parses the input stream and calls
appropriate functions to perform the instructions. __Your task is to implement
those functions so that the output produced is correct.__


__Example__

__Input:__
```
a park
a snow
a zoo
a car
a dinner
p
s
l
p
a crab
a rank
a herb
a rabbit
a sand
p
l
s
p
s
s
l
l
p
l
s
p
s
p
```

__Output:__
```
car dinner park snow zoo
dinner park snow
crab dinner herb park rabbit rank sand snow
dinner herb park rabbit rank sand
park rabbit


```
(notice that the last two lines of the output are blanks!).



__Deliverables:__
Implementation of the functions in `bst.c` file. You may add
declarations to the file `bst.h` (you have to upload the modified
  file if you do so).





## Problem 2 (10 points)


This program performs basic operations on floating point numbers to illustrate
how they are encoded using the IEEE754 standard.
It reads a sequence of floating point numbers from the standard input stream
and outputs the results to the standard output stream.
The input is terminated by a zero.


Recall the IEEE754 encoding for the floating point numbers represented using
32 bits (`float` type in C).

Your task is to _disassemble_ a floating point number into three separate components:
- `s` sign (either 1 or -1)
- `E` exponent
- `M` mantissa/significand

The floating point number should then be equal to the product of s * M * 2^(E).

The `main` function in `problem2.c` reads and parses the input stream and calls
appropriate functions to perform the _disassembly_. __Your task is to implement
those functions so that the output produced is correct.__


__Example__

|__Input:__|__Output:__ |
|:---|:---|
|1024|1 10 1.00000000000000000000<br>1024.00000000000000000000000000000000000000000000000000|
|-1024|-1 10 1.00000000000000000000<br>-1024.00000000000000000000000000000000000000000000000000|
|1023|1 9 1.99804687500000000000<br>1023.00000000000000000000000000000000000000000000000000|
|1025|1 10 1.00097656250000000000<br>1025.00000000000000000000000000000000000000000000000000|
|0.1|1 -4 1.60000002384185791016<br>0.10000000149011611938476562500000000000000000000000|
|0.5|1 -1 1.00000000000000000000<br>0.50000000000000000000000000000000000000000000000000|
|8388608|1 23 1.00000000000000000000<br>8388608.00000000000000000000000000000000000000000000000000|
|8388609|1 23 1.00000011920928955078<br>8388609.00000000000000000000000000000000000000000000000000|
|33554432|1 25 1.00000000000000000000<br>33554432.00000000000000000000000000000000000000000000000000|
|33554432|1 25 1.00000000000000000000<br>33554432.00000000000000000000000000000000000000000000000000|
|1000000000000000.1|1 49 1.77635681629180908203<br>999999986991104.00000000000000000000000000000000000000000000000000|
|1e-40|1 -126 0.00850701332092285156<br>0.00000000000000000000000000000000000000009999946101|
|-1e-40|-1 -126 0.00850701332092285156<br>-0.00000000000000000000000000000000000000009999946101|
|nan|1 255 0.50000000000000000000<br>nan|
|-nan|-1 255 0.50000000000000000000<br>nan|
|inf|1 255 0.00000000000000000000<br>inf|
|-inf|-1 255 0.00000000000000000000<br>-inf|
|0| |




__Deliverables:__
Implementation of the functions in `float.c` file. You may add
declarations to the file `float.h` (you have to upload the modified
  file if you do so).
