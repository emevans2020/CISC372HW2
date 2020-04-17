/* Implementation of the evens library. */
#include <stdio.h>
#include <stdlib.h>
#include "evens_lib.h"
// add other #includes as needed

int *evens;

int * find_evens(int * p, int n, int * num_evens) {
  
  int num = 0;
  for (int i=0; i<n; i++){
	  if ((p[i]%2)==0){
		  num++;
	  }
  }
  *num_evens = num;

  int j = 0;
  evens = (int*)malloc(num*sizeof(int));
  
  for (int i=0; i<n; i++){
      if ((p[i] %2) == 0){
          evens[j]=p[i];
	  j++;
      }
  }

  if (num == 0){
      return NULL;
  }

  return evens;
}

void print_array(int * p, int n) {
  printf("The even numbers are: ");
  for (int i = 0; i < n; i++)
    printf("%d ", p[i]);
  printf("\n");
  fflush(stdout);
}
