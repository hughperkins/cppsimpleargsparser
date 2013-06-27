// Copyright Hugh Perkins 2013, hughperkins -at- gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// usage:
// int N, its;
// arg( "N", &N );
// arg( "its", &its );
// args( argc, argv );

class Arg {
public:
    virtual void assign( const char *argvalue ) = 0;
    virtual void print( std::ostream &os ) const = 0;
};
std::ostream &operator<<( std::ostream &os, const Arg &arg ) {
    arg.print( os );
    return os;
}

class IntArg : public Arg {
public:
    int *argptr;
    IntArg( int *_argptr ) : argptr(_argptr ) {
    }
    void assign( const char *argvalue ) {
        *argptr = atoi( argvalue );
    }
    void print( std::ostream &os ) const {
        os << (*argptr );
    }
};

std::vector<std::string> argnames;
std::vector<Arg *> argptrs;

void arg_usage(std::string cmd) {
    std::cout << "Usage: " << cmd;
    for( int i = 0; i < argnames.size(); i++ ) {
        std::cout << " [" << argnames[i] << "]";
    }
    std::cout << std::endl;
    exit(1);
}

void arg( std::string name, int *p_value ) {
    argnames.push_back(name);
    argptrs.push_back( new IntArg( p_value ) );
}

void args( int argc, char *argv[] ) {
    if( argc - 1 != argnames.size() ) {
        arg_usage(argv[0]);
    }
    for( int i = 0; i < argnames.size(); i++ ) {
        argptrs[i]->assign( argv[i+1] );
        std::cout << argnames[i] << ": " << (*argptrs[i]) << std::endl;
    }
}

class Args {
public:
    int argc;
    char **argv;
    Args( int _argc, char *_argv[] ) : argc(_argc), argv(_argv) {
    }
    void go() {
        args( argc, argv );
    }
    Args &_( std::string name, int *pvalue ) {
        ::arg( name, pvalue );
        return *this;
    }
    Args &arg( std::string name, int *pvalue ) {
        ::arg( name, pvalue );
        return *this;
    }
};


