#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define BILLION 1e9

int main () {
	int n = 5;
	double time_taken = 0.0;
	while(n--) {
#ifdef CLOCK
		clock_t start = clock(), end;
#else
		struct timespec stop, start;
		int result;
		clock_gettime(CLOCK_REALTIME, &start);
#endif
		sleep(5);
		for(int i=0; i < 10000; i++); 
#ifdef CLOCK
		end = clock();
		time_taken = time_taken + (double)((double)end-start)/CLOCKS_PER_SEC;
#else
		clock_gettime(CLOCK_REALTIME, &stop);
		time_taken = (  	(double) (stop.tv_sec - start.tv_sec) + 
					(double) (stop.tv_nsec - start.tv_nsec)/(double)BILLION)
					+time_taken;
#endif
		printf("Time taken: %f\n", time_taken);
	}
	return 0;
}
