/* Example code for Software Systems at Olin College.

Instructions:

1) Fill in the body of endswith so it passes the tests.

You can use any of the functions in string.h
https://www.tutorialspoint.com/c_standard_library/string_h.htm

2) Remove the TODO comment.

Copyright 2017 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* endswith: Checks whether s ends with suffix.

s: string
suffix: string
returns: 1 if true, 0 otherwise
*/
int endswith(char *s, char *suffix)
{
    // Get final inds
    int i = strlen(s)-1;
    int j = strlen(suffix)-1;

    //Iterate from the back and check matching
    while (i >= 0 && j >= 0 && s[i] == suffix[j]){
        i--;
        j--;
    }

    // If j == -1 the suffix matched the end of the string entirely
    // If j is larger then either the string is longer than the suffix, or they didn't match
    return j == -1;
}


/* test_endswith
*/
void test_endswith(char *s1, char *s2, int expected) {
    int got = endswith(s1, s2);
    printf("%s\n%s\n%d\n\n",s1,s2,got);
    assert(got == expected);
}


int main (int argc, char *argv[])
{
    test_endswith("endswith", "swith", 1);
    test_endswith("endswith", "ends", 0);
    test_endswith("endswith", "offendswith", 0);

    // what's the right answer?
    test_endswith("endswith", "", 1);

    printf("All tests passed\n");
}
