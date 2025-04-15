#include <stdio.h>
/* This creates a structure used to print out the 
 * age of the person TED and the income. 
 * it usesd the %d for integer decimal placement
 */

struct Person {
    int age;
    int height;
    short income;
};

int main (int argc, char *arg[]) {
    struct Person TED;
    
    TED.age = 64;
    TED.income = 100;

    printf("%d\n", TED.age + TED.income);
}

