#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]){
	char *a = argv[1];
	int size = atoi(a);

	printf("Attempting to allocate size = %d...", size);
	int as[size];
	for (size_t ix = 0; ix < size; ++ix) { 
		as[ix] = 0;
	};
	printf("Success\n");
	// seg fault at  10,000,000
}

