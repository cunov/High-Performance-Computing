#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include <math.h>

#define LINE_SZ 24

int
get_num_threads(char* args[]){
	int arg_len = strlen(args[1]);
	char char_threads[arg_len-2];
	for (int i=2; i<arg_len; i++){
		char_threads[i-2] = args[1][i];
	};
	return atoi(char_threads);
};

double
get_distance(char* line_i_buffer, char* line_j_buffer){
	double line_i_coord;
	double line_j_coord;
	double distance;
	char *line_i_token = strtok(line_i_buffer, " ");
	char *line_j_token = strtok(line_j_buffer, " ");
	for (int k=0; k<2; k++){
		line_i_coord = atof(line_i_token);
		line_j_coord = atof(line_j_token);
		distance += pow(line_i_coord - line_j_coord, 2);
		line_i_token = strtok(NULL, " ");
		line_j_token = strtok(NULL, " ");
	};
	return sqrt(distance);
};
		

void
main(int argc, char* argv[]){
	int num_threads = get_num_threads(argv);
	if (num_threads > 0){
		printf("Setting [%i] threads\n", num_threads);
		omp_set_num_threads(num_threads);
	} else {
		printf("Negative thread value supplied. Exiting...\n");
		exit(1);
	};

	FILE *fp = fopen("dat.txt", "r");
	if (fp == NULL) {
		printf("Unable to open dat.txt\n");
		exit(1);
	};

	fseek(fp, 0L, SEEK_END);
	unsigned long int num_cells = (int) ftell(fp) / LINE_SZ;
	rewind(fp);
	printf("num cells = %i\n",num_cells);
		
	char *line_i_buffer = (char*) malloc(sizeof(char) * (LINE_SZ-1));
	char *line_j_buffer = (char*) malloc(sizeof(char) * (LINE_SZ-1));
	for (size_t i=0; i<num_cells; i++){
		fseek(fp, i*LINE_SZ, SEEK_SET);
		fread(line_i_buffer, sizeof(char), LINE_SZ-1, fp);
		for (size_t j=0; j<num_cells; j++){
			if (i != j){
				fseek(fp, j*LINE_SZ, SEEK_SET);
				fread(line_j_buffer, sizeof(char), LINE_SZ-1, fp);
			};
		};
	};

	printf("%s\n",line_i_buffer);
	printf("%s\n",line_j_buffer);
	double x = get_distance(line_i_buffer, line_j_buffer);	


};
