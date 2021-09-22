#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const size_t sz = 1000000;
const size_t size_jump = 1000;
const double a = 1.2;
const int NUM_BENCH = 1000;

void rand_vec(size_t size, double* x){
	for (size_t i=0; i<size; i++){
		if (rand() % 10000 < 1000){
			x[i] = rand() % 1000;
		} else {
			x[i] = 0;
		};
	};
};

void zero_vec(size_t size, double* x){
	for (size_t i=0; i<size; i++){
		x[i] = 0.;
	};
};

int
main(int argc, char *argv[]){
	srand(time(0));
	double *x = (double*) malloc(sizeof(double) * sz);
	double *y = (double*) malloc(sizeof(double) * sz);
	size_t *p1 = (size_t*) malloc(sizeof(size_t) * sz);
	size_t *p2 = (size_t*) malloc(sizeof(size_t) * sz);

	struct timespec p1_start;
	struct timespec p2_start;
	struct timespec p1_stop;
	struct timespec p2_stop; 
	struct timespec base_start;
	struct timespec base_stop;

	
	for (size_t i=0; i<sz; i++){
		p1[i] = i;
	};
	for (size_t j=0, k=0; j<size_jump; ++j){
		for (size_t i=j; i<sz; i+=size_jump, k++){
			p2[i] = k;
		};
	};

	rand_vec(sz, x);
	zero_vec(sz, y);
	timespec_get(&base_start, TIME_UTC);
	for (int k=0; k<NUM_BENCH; k++){
		for (size_t i=0; i<sz; i++){
			y[i] += a * x[i];
		};
	};
	timespec_get(&base_stop, TIME_UTC);

	rand_vec(sz, x);
	zero_vec(sz, y);
	timespec_get(&p1_start, TIME_UTC);
	for (int k=0; k<NUM_BENCH; k++){
		for (size_t i=0; i<sz; i++){
			size_t j = p1[i];
			y[j] += a * x[j];
		};
	};
	timespec_get(&p1_stop, TIME_UTC);

	rand_vec(sz, x);
	zero_vec(sz, y);
	timespec_get(&p2_start, TIME_UTC);
	for (int k=0; k<NUM_BENCH; k++){
		for (size_t i=0; i<sz; i++){
			size_t j = p2[i];
			y[j] += a * x[j];
		};
	};
	timespec_get(&p2_stop, TIME_UTC);


	double diff_base = difftime(base_stop.tv_sec, base_start.tv_sec) * 1000000 +
                (base_stop.tv_nsec - base_start.tv_nsec) / NUM_BENCH;
	double diff_p1 = difftime(p1_stop.tv_sec, p1_start.tv_sec) *       1000000 +
		(p1_stop.tv_nsec - p1_start.tv_nsec) / NUM_BENCH;
	double diff_p2 = difftime(p2_stop.tv_sec, p2_start.tv_sec) *       1000000 +
		(p2_stop.tv_nsec - p2_start.tv_nsec) / NUM_BENCH;

	printf("Averages for %zi iterations...\n", NUM_BENCH);
	printf("[BASE]\t%f micro seconds\n", diff_base);
	printf("[p1]\t%f micro seconds\n", diff_p1);
	printf("[p2]\t%f micro seconds\n", diff_p2);

	size_t r = rand() % sz;
	printf("\n(garbage)\t%f,%f\n", x[r], y[r]);
};
