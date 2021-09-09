#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
	const double sz = 1000000000;
	const long int bench_iter = 10;
	struct timespec bench_start_time;
	struct timespec bench_stop_time;
	double bench_diff_time;

	double *b = (double*) malloc(sz * sizeof(double));

	// heat up
	for (size_t i=0; i<bench_iter; ++i){
		b[i] = 0;
		for (size_t j=0; j<sz; ++j){
			b[i] += j;
		};
		b[i] = 0; // reset b's to zero
	};

	// run benchmark
	timespec_get(&bench_start_time, TIME_UTC);
	for (size_t i=0; i<bench_iter; ++i){
		for (size_t j=0; j<sz; ++j){
			b[i] += j;
		};
	};
	timespec_get(&bench_stop_time, TIME_UTC);

	bench_diff_time = difftime(bench_stop_time.tv_sec, bench_start_time.tv_sec) * 1000000 + 
		(bench_stop_time.tv_nsec - bench_start_time.tv_nsec) / 1000;
	printf("benchmark time for one iteration: %f micro seconds\n", bench_diff_time / bench_iter);
	
	for (size_t i=0; i<bench_iter; ++i){
		printf("the result is: %lf\n", b[i]);
	};
	// dont need to avoid optimization with volatile because we print an element of b
	free(b);
}
