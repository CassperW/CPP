#include<stdio.h>
int main()
{
    int a[]={2,4,6,8,10},y=1,*p;
    p=&a[1];
    printf("a = %p\np = %p\n",a, p);
    for(int i = 0; i < 3; i++)
        y += *(p+i); // 1 + 4 + 6 + 8 = 19
    printf("y = %d\n\n",y);
    int b[5]={1,2,3,4,5};
    int *ptr=(int*)(&b+1); //跳过整个数组，加4*5=20
    printf("b = %p\nb+4 = %p\nptr = %p\n",b,b+4,ptr);
    printf("%d,%d\n",*(b+1),*(ptr-1)); //b[1] = 2, ptr-1 = b[4] = 5
    return 0;
}