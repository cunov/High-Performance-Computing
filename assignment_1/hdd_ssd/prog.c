#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_BENCH 10

void
main(int argc, char *argv[]){
	struct timespec bench_start_time;
	struct timespec bench_stop_time;
	double bench_diff_time;
	double *arr = (double*) malloc(sizeof(double) * (int) pow(2,20));
	double *trash = (double*) malloc(sizeof(double) * (int) pow(2,20));

	char fname_hdd_ind[] = "./hdd_ind.dat";
	char fname_hdd_arr[] = "./hdd_arr.dat";
	char fname_ssd_ind[] = "/run/mount/scratch/hpcuser026/ssd_ind.dat";
	char fname_ssd_arr[] = "/run/mount/scratch/hpcuser026/ssd_arr.dat";

	for (size_t i=0; i<pow(2,20); i++){
		arr[i] = i;
	};

	FILE *fp_hdd_ind = fopen(fname_hdd_ind, "wb+");
	if (fp_hdd_ind == NULL) {
		printf("error opening [HDD, IND] file\n");
	} else {
		timespec_get(&bench_start_time, TIME_UTC);
		for (size_t ib=0; ib<NUM_BENCH; ib++) {
			for (size_t i=0; i<pow(2,20); i++){
				fwrite(&arr[i], sizeof(double), 1, fp_hdd_ind);
				fflush(fp_hdd_ind);
			};
			fread(trash, sizeof(double), NUM_BENCH, fp_hdd_ind);
		};
		timespec_get(&bench_stop_time, TIME_UTC);
		bench_diff_time = difftime(bench_stop_time.tv_sec, bench_start_time.tv_sec) * 1000000 +
                    (bench_stop_time.tv_nsec - bench_start_time.tv_nsec) / 1000;
        	printf("[HDD, IND]\t%f micro seconds, on avg over %i iterations\n", bench_diff_time / NUM_BENCH, NUM_BENCH);
	};

	FILE *fp_hdd_arr = fopen(fname_hdd_arr, "wb+");
	if (fp_hdd_arr == NULL){
		printf("error opening [HDD, ARR] file\n");
	} else {
		timespec_get(&bench_start_time, TIME_UTC);
		for (size_t ib = 0; ib<NUM_BENCH; ib++){
			fwrite(arr, sizeof(double), pow(2,20), fp_hdd_arr);
			fflush(fp_hdd_arr);
		};
		timespec_get(&bench_stop_time, TIME_UTC);
		bench_diff_time = difftime(bench_stop_time.tv_sec, bench_start_time.tv_sec) * 1000000 +
		    (bench_stop_time.tv_nsec - bench_start_time.tv_nsec) / 1000;
		printf("[HDD, ARR]\t%f micro seconds, on avg over %i iterations\n", bench_diff_time / NUM_BENCH, NUM_BENCH);
	};

	FILE *fp_ssd_arr = fopen(fname_ssd_ind, "wb+");
	if (fp_ssd_arr == NULL){
		printf("error opening [SSD, IND]\n");
	} else {
		timespec_get(&bench_start_time, TIME_UTC);
		for (size_t ib=0; ib<NUM_BENCH; ib++){
 			fwrite(arr, sizeof(double), pow(2,20), fp_ssd_arr);
			fflush(fp_ssd_arr);
		};
		timespec_get(&bench_stop_time, TIME_UTC);
		bench_diff_time = difftime(bench_stop_time.tv_sec, bench_start_time.tv_sec) * 1000000 +
		    (bench_stop_time.tv_nsec - bench_start_time.tv_nsec) / 1000;
		printf("[SSD, IND]\t%f micro seconds, on avg over %i iterations\n", bench_diff_time / NUM_BENCH, (int) NUM_BENCH);
	};

	FILE *fp_ssd_ind = fopen(fname_ssd_arr, "wb+");
	if (fp_ssd_ind == NULL){
		printf("error opening [SSD, ARR] file\n");
	} else {
		timespec_get(&bench_start_time, TIME_UTC);
		for (size_t ib=0; ib<NUM_BENCH; ib++){
			for (size_t i=0; i<pow(2,20); i++){
				fwrite(&arr[i], sizeof(double), 1, fp_ssd_ind);
				fflush(fp_ssd_ind);
			};
		};
		timespec_get(&bench_stop_time, TIME_UTC);
 		bench_diff_time = difftime(bench_stop_time.tv_sec, bench_start_time.tv_sec) * 1000000 +
		    (bench_stop_time.tv_nsec - bench_start_time.tv_nsec) / 1000;
		printf("[SSD, ARR]\t%f micro seconds, on avg over %i iterations\n", bench_diff_time / NUM_BENCH, (int) NUM_BENCH);
	};


	if (remove(fname_hdd_ind)==0) {
		printf("Remove \"%s\" success...\n", fname_hdd_ind);
	} else { 
		printf("Remove \"%s\" FAILURE\n", fname_hdd_ind);
	};

	if (remove(fname_hdd_arr)==0) {
		printf("Remove \"%s\" success...\n", fname_hdd_arr);
	} else {
		printf("Remove \"%s\" FAILURE\n", fname_hdd_arr);
	};

	if (remove(fname_ssd_ind)==0) {
		printf("Remove \"%s\" success...\n", fname_ssd_ind);
	} else {
		printf("Remove \"%s\" FAILURE\n", fname_ssd_ind);
	};

	if (remove(fname_ssd_arr)==0) {
		printf("Remove \"%s\" success...\n", fname_ssd_arr);
	} else {
		printf("Remove \"%s\" FAILURE\n", fname_ssd_arr);
	};
};
