#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<omp.h>

int main() {

	int N = 100000;
	int n = 0;
	double x, y;
	double radio = 1;
	srand( time (NULL));

	double t1 = omp_get_wtime();
	#pragma omp parallel for num_threads(4) reduction(+:n) private(x, y) shared(radio, N)
		for (int i = 0; i < N; i++) {
			x = (double)rand()/RAND_MAX*2.0; //float in range 0 to 2
			y = (double)rand()/RAND_MAX*2.0; //float in range 0 to 2
			double diff_x = x - 1.0;
			double diff_y = y - 1.0;
			double dist =diff_x * diff_x + diff_y * diff_y;
			if (sqrt(dist) <= radio) {
				n+=1;
			}
		}
	
	double t2 = omp_get_wtime();
	int tid = omp_get_num_threads();
	printf("Threads ::%d\n", tid);

	printf("pi value %.5f\n", 4*n*1.0/N);
	printf("time :: %.10f\n", t2-t1);
}

