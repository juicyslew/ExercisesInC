/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 6

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches",
    "1234 Baby!"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Print the error returned from the regular expression library
// Based on Application Usage at: https://pubs.opengroup.org/onlinepubs/7908799/xsh/regcomp.html
//
// Print the error
void print_reg_error(int code ,regex_t * preg){
    // Get the error's length
    size_t errsize = regerror(code, preg, (char *)NULL, (size_t)0);

    char *err = malloc(errsize * sizeof(char));
    regerror(code, preg, err, errsize);
    printf("%s\n", err);
}

// Determine whether a string matches a pattern 
// From Example at: https://pubs.opengroup.org/onlinepubs/7908799/xsh/regcomp.html
// 
// return 1 if completed successfully and 0 for an error
int match(const char *string, char *pattern)
{
    int      status;
    regex_t      re;


    if ((status = regcomp(&re, pattern, 0)) != 0) {
        print_reg_error(status, &re);
        exit(1);
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    if (status != 0) { //If status is match
        if (status != 1){ //If status is no match
            print_reg_error(status, &re);
            regfree(&re);
            exit(1);
        }
        regfree(&re);
        return (0);
    }
    regfree(&re);
    return(1);
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (match(tracks[i], pattern)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
