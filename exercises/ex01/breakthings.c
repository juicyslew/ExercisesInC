#include <stdio.h>

int main() {
	char x = 'S';
	char *p = &x;
	for (int i = 0; i < 1000; i++){
		printf("%c", *p);
		p++;
	}

	int a = 3;
	int b = 4;
	int c = a + b;
	int m = c%2;
	char * s;
	switch(m){
		case 0:
        	s = "c is even\n";
        case 1:
        	s = "c is odd\n";
	}
    return 0;
}

// The optimization removed the explicit steps to add together x and y and save those values as variables.
// Without the optimization there were more addition steps and the assembly language was longer.
// With it the code related to that addition was gone and precomputed to determine the printf output.
// It seems the optmization would precompute deterministic parts of the code for increased efficiency
