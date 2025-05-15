#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main() {
    int *p = NULL;
    p = (int *) malloc(4 * sizeof(int));
    p = (int *) malloc(4 * sizeof(int));
    free(p);
}