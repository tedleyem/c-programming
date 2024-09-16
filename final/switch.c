#include <stdio.h>
// determines if user input is a 1 or 2 or something else
int main(int argc, char *argv[])
{
    int x;
    scanf("%d", &x);

    switch (x)
    {
        case 0:
            printf("Thats a zero\n");
            break;
        case 1:
            printf("Thats a one\n");
            break;
        case 2:
            printf("Thats a two\n");
            break;
        default:
            printf("I dont know what this is?");
            break;
    }
    return 0;
}

