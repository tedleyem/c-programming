#include <stdio.h>
// you can pass variables into functions 

int g;

int function_two(int param)
{
    param += 1;
    return param;
}

int main (int argc, char **argv)
{
    int a, b;

    a = 10;
    a = function_two(a);

    printf( "value of a = %d\n", a);
    return 0;
}