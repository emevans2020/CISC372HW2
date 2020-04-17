/* Driver for evens libary */
#include "evens_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// add other #includes as needed

// ADD A GOOD COMMENT HERE.  Explain exactly what the
// main function does.
// This program will take in the users arguments on a list of ints and only print out
// the even ones.
int *num_evens;
int *originalArr;
int *evensArr;

int main(int argc, char *argv[]) {
  // TODO: this is a stub.  Implement me.
  originalArr = (int*) malloc((argc-1)*sizeof(int));
  num_evens = (int*) malloc(sizeof(int));

  for (int i=1;i<argc;i++){
     originalArr[i-1] = atoi(argv[i]);
  }

  evensArr = find_evens(originalArr,(argc-1),num_evens);
  print_array(evensArr,*num_evens);

  free(evensArr);
  free(originalArr);
  free(num_evens);

  return 0;
}
