#include <stdio.h>
/*
 * Setup values in an array with a for loop
 * then read the loop up to 100 and print each 
 * multiple of 2 while doing that.
 */
int main (int argc, char *argv[])
{
    short arr[100];

    int i;
    for (i = 0; i < 100; i++)
    {
        arr[i] = i;
    }

    i = 0;
    while(i < 100)
    {
        printf("%d: %d\n", i, arr[i]);
        i++;
    }

    i = 0;
    do
    {
        arr[i] = i*2;
        i++;
    } while (i < 100);

    i = 0;
    while (i < 100)
    {
        printf("%d: %d\n", i, arr[i]);
        i++;
    }
}
