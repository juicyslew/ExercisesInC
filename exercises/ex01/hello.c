#include <stdio.h>

int mood(int a);
char * swerve(char * avoid);

int main() {
	int a = 3;
	int b = 4;
	int c = a + b;
	int m = c%2;
	switch(m){
		case 0:
        	printf("c is even\n");
        case 1:
        	printf("c is odd\n");
	}
    return 0;
}

char * swerve(char * avoid){
	printf("%s has been swerved.", avoid);
}

// The optimization removed the explicit steps to add together x and y and save those values as variables.
// Without the optimization there were more addition steps and the assembly language was longer.
// With it the code related to that addition was gone and precomputed to determine the printf output.
// It seems the optmization would precompute deterministic parts of the code for increased efficiency
