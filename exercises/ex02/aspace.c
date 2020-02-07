/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void addrPrint();

int main ()
{
    int var2 = 5;
    void *p = malloc(25);
    void *m = malloc(25);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("m points to %p\n", m);
    printf ("s points to %p\n", s);

    addrPrint();

    return 0;
}

void addrPrint(){
	int varMe = 8;
	printf("Address of varMe is %p\n", &varMe);
}