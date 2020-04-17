/* Program for ragged question */
#include <stdio.h>
#include <stdlib.h>
// add other #includes as needed

// TODO: create two global variables: 
//   1. lengths. Type: pointer-to-int
int *lengths;
//   2. data. Type: pointer-to-pointer-to-int.
int **data;
// ADD A GOOD COMMENT HERE.  Explain exactly what the
// main function does.
// This main function takes in the argument and sets lengths to be the 
// the value of the argument provided. It will increment by one each time
// and only print out the numbers up to the size of length then move to a new
// line. It prints a jagged array. 
// The argc is used to evaluate how many times you should loop through the
// arguments provided.
int main(int argc, char **argv) {
    lengths = (int*) malloc((argc-1) * sizeof(int));
    data = (int**) malloc((argc-1) * sizeof(int));
    
    int count = 0;
    for (int i=0; i<argc; i++){
	    lengths[i] = atoi (argv[i]);
	    data[i] = (int*)malloc(lengths[i]*sizeof(int));
	    for (int j=0; j<lengths[i];j++){
	    	data[i][j] = count;
		count++;
		}
	}

    for (int i=1; i<argc;i++){
	for (int j=0; j <lengths[i];j++){
	     printf("%d ", data[i][j]);
	}
	printf("\n");
    }
    printf("\n");
	
    for (int i=1; i<argc;i++){
    	free(data[i]);
    }

    free(data);
    free(lengths);

  return 0;
}
