#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]){
	FILE *file = fopen("test_file.dat", "rb");
	
	if (file == NULL){
		printf("error opening file\n");
		return -1;
	};
		

	int *asentries = (int*) malloc(sizeof(int)*10*10);
	int **mat = (int**) malloc(sizeof(int*) * 10);

	for (size_t i=0, j=0; i<10; ++i, ++j){
		mat[i] = asentries + j;
		fread(mat[i], sizeof(mat[i][0]), 10, file);
		for (size_t j=0; j<10; ++j){
			if (mat[i][j] == i*j) {
				printf("0\t");
			} else {
				printf("X\t");
			};
		};
		printf("\n");
	};

	fclose(file);
}
