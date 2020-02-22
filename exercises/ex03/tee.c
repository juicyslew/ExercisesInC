#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Reflection:
	I felt really good about how I went about doing this homework
One thing that went really well is that after writing my first pass code,
I tested each part separately before seeing if the whole thing would work
together. This helped me hone in on errors really fast, and be confident
that each part was working correctly.
	To further break it down I probably should have coded functionality in
pieces, potentially with multiple functions as supposed to just one. This
would have taken longer but also would allow for high level error spotting
earlier.  Moreover, making psuedocode could have been helpful were this a
bit harder of a problem.
*/

/* Comparison to Professional Code
	The professional code appeared to have more checking for errors and of
course more capabilities in the form of other arguments that appear to
require a further knowledge of C and operating systems than I currently 
have in order to implement.
	Another important difference is that the professional implementation
examples tend to utilize all sorts of functions I've never seen.  This
implies that one important difference between a novice and a professional
is in depth knowledge of what tools are available to utilize.  For example,
I utilized a conditional expression to determine arguments.  Contrarily,
the professional implementations use switch statements and getopt to pull
argument information.
*/



/*
This is an implementation of the tee function in the common UNIX environment
The function reads from stdin and writes that information to stdout and a file.
*/

int main(int argc, char *argv[]){

	int append = 0;

	// Logic for arguments 
	// (if adding more arguments, change the break to a continue)
	for (int i = 1; i < argc-1; i++){
		if (!strcmp(argv[i], "--append") ){
			append = 1;
			break;
		}else if (!strcmp(argv[i], "-a")){
			append = 1;
			break;
		}
	}

	// Set write mode based on arguments
	char *writeMode = append ? "a" : "w";

	// Open File to be written to
	FILE *file = fopen (argv[argc-1], writeMode);

	// Write stdin to file and stdout iteratively
	char buffer[10];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL){
		fputs( buffer, file);
		printf("%s",buffer);
	}

	// Close the file
	fclose(file);

	// Finish the program
	return 0;
}

