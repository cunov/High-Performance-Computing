#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int SIZE = 30000;
const int NUM_BENCH = 10000;

static inline
void
mul_cpx(
    double *a_re,
    double *a_im,
    double *b_re,
    double *b_im,
    double *c_re,
    double *c_im
    ){
	*a_re = *b_re * *c_re - *b_im * *c_im;
	*a_im = *b_re * *c_im + *b_im * *c_re;
};

	
int
main(int argc, char *argv[]){
	srand(time(0));
	struct timespec bench_start_time;
        struct timespec bench_stop_time;
        double bench_diff_time;

	double a_re[SIZE], a_im[SIZE],
		b_re[SIZE], b_im[SIZE],
		c_re[SIZE], c_im[SIZE];
	
	timespec_get(&bench_start_time, TIME_UTC);
	for (int j=0; j<NUM_BENCH; j++){
		for (int i=0; i<SIZE; i++){
			b_re[i] = rand() % 5;
			b_im[i] = rand() % 5;
			c_re[i] = rand() % 5;
			c_im[i] = rand() % 5;

			mul_cpx(&a_re[i], &a_im[i], &b_re[i], &b_im[i], &c_re[i], &c_im[i]);
		};
	};
        timespec_get(&bench_stop_time, TIME_UTC);

        bench_diff_time = difftime(bench_stop_time.tv_sec, bench_start_time.tv_sec) * 1000000 +
                (bench_stop_time.tv_nsec - bench_start_time.tv_nsec) / 1000;

	int r = rand() % SIZE;
	printf("%f + %fi\n", a_re[r], a_im[r]);
	printf("%i iterations took (%f) micro seconds on avg\n", NUM_BENCH, bench_diff_time);
	return 0;
};
