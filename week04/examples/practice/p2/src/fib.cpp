//fib.cpp
#include "functions.h"
int fib(int n) {
    if(1==n) return 1;
    else return n * fib(n-1);
}
