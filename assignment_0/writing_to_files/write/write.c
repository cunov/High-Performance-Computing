#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]){
	FILE *file = fopen("../read/test_file.dat", "wb");
	
	if (file == NULL){
		printf("error opening test_file.dat\n");
		return -1;
	};

	int *asentries = (int*) malloc(sizeof(int) * 10 * 10);
	int **mat = (int**) malloc(sizeof(int*) * 10);
	for (size_t i=0, j=0; i<10; ++i, ++j){
		mat[i] = asentries + j;
	};

	for (size_t i=0; i<10; ++i){
		for (size_t j=0; j<10; ++j){
			mat[i][j] = i * j;
		};
		fwrite(mat[i], sizeof(mat[i][0]), 10, file);
	};
	
	fclose(file);
}
