#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NUM_BENCH = 5000;
const int nrs = 1000;
const int ncs = 1000;


void row_sums(double *sums, const double **matrix, size_t nrs, size_t ncs){
	for (size_t i=0; i<nrs; i++){
		//double sum = 0.;
		for (size_t j=0; j<ncs; j++){
			sums[i] += matrix[i][j];
		};
	};
};

void col_sums(double *sums, const double **matrix, size_t nrs, size_t ncs){
	for (size_t i=0; i<ncs; i++){
		//double sum = 0.;
		for (size_t j=0; j<nrs; j++){
			sums[j] += matrix[i][j];
		};
	};
};

double** generate_mat(int nrs, int ncs){
	double **mat = (double**) malloc(sizeof(double*) * nrs);
	double *mat_entries = (double*) malloc(sizeof(double) * ncs * nrs);

	for (int i=0, j=0; i<nrs; i++, j+=ncs){
		mat[i] = mat_entries + j;
	};
	for (int i=0; i<nrs; i++){
		for (int j=0; j<ncs; j++){
			mat[i][j] = rand() % 10000;
		};
	};
	return mat;
};

void main(int argc, char *argv[]){
        srand(time(0));
	struct timespec bench_start_time;
        struct timespec bench_stop_time;
        double bench_diff_time;

	double **matrix = generate_mat(nrs, ncs);
	
	timespec_get(&bench_start_time, TIME_UTC);
	for (int i=0; i<NUM_BENCH; i++){
		static double r_sum[1000];
		static double c_sum[1000]; // initialize to zero
		double *r_sum_ptr = r_sum;
		double *c_sum_ptr = c_sum;
		row_sums(r_sum_ptr, (const double**) matrix, nrs, ncs);
		col_sums(c_sum_ptr, (const double**) matrix, nrs, ncs);		
	};
	timespec_get(&bench_stop_time, TIME_UTC);

	bench_diff_time = difftime(bench_stop_time.tv_sec, bench_start_time.tv_sec) * 1000000 +
                (bench_stop_time.tv_nsec - bench_start_time.tv_nsec) / NUM_BENCH;

        printf("%i iterations took (%f) micro seconds on avg\n", NUM_BENCH, bench_diff_time);
};
