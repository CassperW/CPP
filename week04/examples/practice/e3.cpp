#include <stdio.h> //p2.c
#include <iostream>
#include <string.h>
using namespace std;
union data{
    int n;
    char ch;
    short m;
};
int main() {
    union data a;
    printf("%ld, %ld\n", sizeof(a), sizeof(union data) );
    a.n = 0x40; //0x40000000
    printf("%X, %c, %hX\n", a.n, a.ch, a.m); 
    a.ch = '9'; //0x39000000
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.m = 0x2059; //0x5920000
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.n = 0x3E25AD54; //0x54AD253E
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    cout << hex;
    cout << +'Y' << endl;
    cout << +'T' << endl;
    return 0;
} 