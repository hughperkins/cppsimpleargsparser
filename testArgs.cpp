#include "args.h"

int main( int argc, char *argv[] ) {
    int n, iterations, threads;
    Args( argc, argv ).arg( "n", &n ).arg( "iterations", &iterations ).arg( "threads", &threads ).go();
    // that's it!

    // rest of program here.

    return 0;
}
