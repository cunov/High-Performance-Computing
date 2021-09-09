#include <stdio.h>
#include <stdlib.h>

// AVOIDING MEMORY FRAGMENTATION

void
main(int argc, char *argv[]){
	int size = 10;

	int * asentries = (int*) malloc(sizeof(int) * size*size);
	// this calculates the memory required by (size * size) ints and requests that many bytes from malloc
	//   and assigns the result to the pointer-to-int asentries
	// now, asentries points to the memory occupied by a (size * size) matrix of ints
	
	int ** as = (int**) malloc(sizeof(int*) * size);
	// this calculates the memory required by (size) pointer-to-ints and requests that many bytes from malloc
	//   and assigns the result to the pointer-to-pointer-to-int as

	for ( size_t ix = 0, jx = 0; ix < size; ++ix, jx+=size ) {
  		as[ix] = asentries + jx;
	};
	// by using jx here we are iterating over the (size * size) block of asentries, 
	//   as is one contiguous block of memory
	// here, jx increments by size, i.e. 0, size, 2*size, ...

	for ( size_t ix = 0; ix < size; ++ix ) {
  		for ( size_t jx = 0; jx < size; ++jx ) {
    			as[ix][jx] = 0;
		};
	};
	// this assigns 0 to each element of as
	
	printf("%d\n", as[0][0]);

	free(as);
	free(asentries);
	// since as and asentries are contiguous, we do not need to loop over them to free them
}
