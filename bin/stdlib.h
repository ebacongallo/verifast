#ifndef STDLIB_H
#define STDLIB_H

#include <stdbool.h>
#include <malloc.h>

void abort();
    //@ requires true;
    //@ ensures false;

void exit(int status);
/*@ requires true;
  @*/
/*@ ensures false;
  @*/

#endif
