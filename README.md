cppsimpleargsparser
===================

Simple C++ args parser.  Easy to use.  Automatically provides checking and usage printout.

Let's say we want to accept three integers on our commandline: n, iterations, and threads.

In our program, we put:

    #include "args.h"

    int main( int argc, char *argv[] ) {
        int n, iterations, threads;
        Args( argc, argv ).arg( "n", &n ).arg( "iterations", &iterations ).arg( "threads", &threads ).go();
        // that's it!

        // rest of program here.

        return 0;
    }

If we run the program with no arguments, we get:

    > ./testArgs
    Usage: ./testArgs [n] [iterations] [threads]

We can try this usage:

    > ./testArgs 4 3 12
    n: 4
    iterations: 3
    threads: 12

Requirements
============

- C++
- C++ standard library
- nothing else!

License
=======

MPL 2.0

This means you can use it in your own program without needing to 
use any special license on your own program.  You must keep
the copyright notice on the args.h file, and the license 
header.


