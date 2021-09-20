#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NUM_BENCH = 5000;
const int nrs = 1000;
const int ncs = 1000;


void
row_sums(double *sums, const double **matrix, size_t nrs, size_t ncs){
	for (size_t i=0; i<nrs; i++){
		double sum = 0.;
		for (size_t j=0; j<ncs; j++){
			sum += matrix[i][j];
		};
		sums[i] = sum;
	};
};

void
row_sums_unrolled2(double *sums, const double **matrix, size_t nrs, size_t ncs){
	for (size_t i=0; i<nrs; i++){
		double sum0 = 0.;
		double sum1 = 0.;
		for (size_t j=0; j<ncs; j+=2){
			sum0 += matrix[i][j];
			sum1 += matrix[i][j+1];
		};
		sums[i] = sum0 + sum1;
	};
};
void
row_sums_unrolled4(double *sums, const double **matrix, size_t nrs, size_t ncs){
	for (size_t i=0; i<nrs; i++){
		double sum0 = 0.;
		double sum1 = 0.;
		double sum2 = 0.;
		double sum3 = 0.;
		for (size_t j=0; j<ncs; j+=4){
			sum0 += matrix[i][j];
			sum1 += matrix[i][j+1];
			sum2 += matrix[i][j+2];
			sum3 += matrix[i][j+3];
		};
		sums[i] = sum0 + sum1 + sum2 + sum3;
	};
};

void
row_sums_unrolled8(double *sums, const double **matrix, size_t nrs, size_t ncs){
	for (size_t i=0; i<nrs; i++){
		double sum0 = 0.;
		double sum1 = 0.;
		double sum2 = 0.;
		double sum3 = 0.;
		double sum4 = 0.;
		double sum5 = 0.;
		double sum6 = 0.;
		double sum7 = 0.;
		for (size_t j=0; j<ncs; j+=8){
			sum0 += matrix[i][j];
			sum1 += matrix[i][j+1];
			sum2 += matrix[i][j+2];
			sum3 += matrix[i][j+3];
			sum4 += matrix[i][j+4];
			sum5 += matrix[i][j+5];
			sum6 += matrix[i][j+6];
			sum7 += matrix[i][j+7];
		};
		sums[i] = sum0 + sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7;
	};
};

void
row_sums_unrolled4_arr(double *sums, const double **matrix, size_t nrs, size_t ncs){
	for (size_t i=0; i<nrs; i++){
		double sum[4] = {0., 0., 0., 0.};
		for (size_t j=0; j<ncs; j+=4){
			sum[0] += matrix[i][j];
			sum[1] += matrix[i][j+1];
			sum[2] += matrix[i][j+2];
			sum[3] += matrix[i][j+3];
		};
		sums[i] = sum[0] + sum[1] + sum[2] + sum[3];
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
	struct timespec start_row_sums;
	struct timespec start_unrolled2;
	struct timespec start_unrolled4;
	struct timespec start_unrolled8;
	struct timespec start_unrolled4_arr;

	struct timespec stop_row_sums;
	struct timespec stop_unrolled2;
	struct timespec stop_unrolled4;
	struct timespec stop_unrolled8;
	struct timespec stop_unrolled4_arr;

	double diff_row_sums;
	double diff_unrolled2;
	double diff_unrolled4;
	double diff_unrolled8;
	double diff_unrolled4_arr;

	double **matrix = generate_mat(nrs, ncs);
	
	timespec_get(&start_row_sums, TIME_UTC);
	for (int i=0; i<NUM_BENCH; i++){
		static double r_sum[1000]; // initialize to zero
		double *r_sum_ptr = r_sum;
		row_sums(r_sum_ptr, (const double**) matrix, nrs, ncs);
	};
	timespec_get(&stop_row_sums, TIME_UTC);
	timespec_get(&start_unrolled2, TIME_UTC);
	for (int i=0; i<NUM_BENCH; i++){
		static double r_sum[1000];
 		double *r_sum_ptr = r_sum;
 		row_sums_unrolled2(r_sum_ptr, (const double**) matrix, nrs, ncs);
 	};
	timespec_get(&stop_unrolled2, TIME_UTC);
	timespec_get(&start_unrolled4, TIME_UTC);
	for (int i=0; i<NUM_BENCH; i++){
		static double r_sum[1000];
		double *r_sum_ptr = r_sum;
		row_sums_unrolled4(r_sum_ptr, (const double**) matrix, nrs, ncs);
	};
	timespec_get(&stop_unrolled4, TIME_UTC);
	timespec_get(&start_unrolled8, TIME_UTC);
	for (int i=0; i<NUM_BENCH; i++){
		static double r_sum[1000];
		double *r_sum_ptr = r_sum;
		row_sums_unrolled8(r_sum_ptr, (const double**) matrix, nrs, ncs);
	};
	timespec_get(&stop_unrolled8, TIME_UTC);
	timespec_get(&start_unrolled4_arr, TIME_UTC);
	for (int i=0; i<NUM_BENCH; i++){
		static double r_sum[1000];
		double *r_sum_ptr = r_sum;
		row_sums_unrolled4_arr(r_sum_ptr, (const double**) matrix, nrs, ncs);
	};
	timespec_get(&stop_unrolled4_arr, TIME_UTC);

	diff_row_sums = difftime(stop_row_sums.tv_sec, start_row_sums.tv_sec) * 1000000 +
                (stop_row_sums.tv_nsec - start_row_sums.tv_nsec) / NUM_BENCH;
	diff_unrolled2 = difftime(stop_unrolled2.tv_sec, start_unrolled2.tv_sec) * 1000000 +
		(stop_unrolled2.tv_nsec - start_unrolled2.tv_nsec) / NUM_BENCH;
	diff_unrolled4 = difftime(stop_unrolled4.tv_sec, start_unrolled4.tv_sec) * 1000000 + 
		(stop_unrolled4.tv_nsec - start_unrolled4.tv_nsec) / NUM_BENCH;
	diff_unrolled8 = difftime(stop_unrolled8.tv_sec, start_unrolled8.tv_sec) * 1000000 +
		(stop_unrolled8.tv_nsec - start_unrolled8.tv_nsec) / NUM_BENCH;
	diff_unrolled4_arr = difftime(stop_unrolled4_arr.tv_sec, start_unrolled4_arr.tv_sec) * 1000000 +
		(stop_unrolled4_arr.tv_nsec - start_unrolled4_arr.tv_nsec) / NUM_BENCH;

        printf("[ROW_SUMS]\t %i iterations took (%f) micro seconds on avg\n", 
		NUM_BENCH, diff_row_sums);
	printf("[UNROLLED 2]\t %i iterations took (%f) micro seconds on avg\n",
		NUM_BENCH, diff_unrolled2);
	printf("[UNROLLED 4]\t %i iterations took (%f) micro seconds on avg\n",
		NUM_BENCH, diff_unrolled4);
	printf("[UNROLLED 8]\t %i iterations took (%f) micro seconds on avg\n",
		NUM_BENCH, diff_unrolled8);
	printf("[UNROLLED 4 arr] %i iterations took (%f) micro seconds on avg\n",
		NUM_BENCH, diff_unrolled4_arr);
};
