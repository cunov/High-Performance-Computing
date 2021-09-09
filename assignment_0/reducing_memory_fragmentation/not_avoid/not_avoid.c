#include <stdio.h>
#include <stdlib.h>

// NOT AVOIDING MEMORY FRAGMENTATION

void
main(int argc, char *argv[]){

	int size = 10;

	int **as = (int**) malloc(sizeof(int*) * size);
	// this computes the number of bytes that (size) int-pointers can occupy, then requests that many bytes from malloc
	//   and assigns the result to the pointer-to-pointer-to-int as
 

	for ( size_t ix = 0; ix < size; ++ix )
  		as[ix] = (int*) malloc(sizeof(int) * size);
	// ix is iter
	// this computes the number of bytes (size) ints can occupy, then requests that many bytes from malloc
	//   and assigns the result to as[ix], which is a pointer-to-int
	// each call to malloc (likely) does not result in a contiguous memory space for each row of as

	for ( size_t ix = 0; ix < size; ++ix )
  		for ( size_t jx = 0; jx < size; ++jx )
    			as[ix][jx] = 0;
	// jx is iter
	// this assigns 0 to each element of as


	printf("%d\n", as[0][0]);

	for ( size_t ix = 0; ix < size; ++ix )
    		free(as[ix]);
	free(as);
	// since as is not contiguously allocated, we must loop over each segment and free them individually
}
