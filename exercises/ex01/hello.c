#include <stdio.h>

int main() {
	int x = 5;
	int y = x + 1;
    printf("%i",y);
    return 0;
}

// The optimization removed the explicit steps to add together x and y and save those values as variables.
// Without the optimization there were more addition steps and the assembly language was longer.
// With it the code related to that addition was gone and precomputed to determine the printf output.
// It seems the optmization would precompute deterministic parts of the code for increased efficiency
