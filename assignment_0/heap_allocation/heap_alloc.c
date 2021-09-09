#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]){
	char *a = argv[1];
	int size = atoi(a);

	int * as = (int*) malloc(sizeof(int) * size);
	for (int ix = 0; ix < size; ++ix) {
		as[ix] = 0;
	}
	
	free(as);
}

