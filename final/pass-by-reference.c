#include <stdio.h>
/* This is an example of how to write a function 
that makes use of a structure (because you cant pass
structures by value)

*/
struct Person { 
    int age;
    int height;
};

/* set the functions parameters to the pointer 
to the structure instead of passing the structure by 
itself. 
*/
void zero_person(struct Person *p)
{
    p->age = 4;
    p->height = 0;

    return;
}

int main (int argc, char **argv)
{
    struct Person me; // define a struct
    me.age = 100; // set the age variable in the int function

    zero_person(&me); 
    /* confirm variable is set to age var in pointer and 
    not the previous var of 100
    */
    printf("%d\n", me.age);

    return 0; // always return something from main
}