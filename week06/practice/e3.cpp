#include <iostream>

int add1(int a, int b) {
    int sum = (a++) + (b++);
    return sum;
}

int add2(int *x, int *y) {
    int sum = ((*x)++) + ((*y)++);
    x = NULL;
    y = NULL;
    return sum;
}

int add3(int &a, int &b) {
    int sum = (a++) + (b++);
    return sum;
}

int add3_x(int &c, int &d) {
    int sum = (c++) + (d++);
    int *e = (int *)malloc(sizeof(int));
    *e = 1;
    c = *e;
    d = *e;
    sum = (++c) + (++d);
    return sum;
}

int main() {
    int i = 0, j = 0;
    scanf("%d", &i);
    scanf("%d", &j);
    printf("i_address:%p,j_address:%p\n", &i, &j);
    int sum = add1(i, j);
    printf("%d+%d=%d\n", i, j, sum);
    sum = add2(&i, &j);
    printf("%d+%d=%d\n", i, j, sum);
    sum = add3(i, j);
    printf("%d+%d=%d\n", i, j, sum);
    sum = add3_x(i,j);
    printf("%d+%d=%d\n", i, j, sum);
    return 0;
}