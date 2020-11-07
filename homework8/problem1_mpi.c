#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<mpi.h>

int main() {

	int N = 1000000000;
	int my_N = N / 4;
	double x, y;
	double radio = 1;
	int n_p;
	int rank;
	int n = 0;
	int n_total = 0;
	double t1, t2;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &n_p);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	srand( time (NULL));

	t1 = MPI_Wtime();

	for (int i = 0; i < my_N; i++) {
		x = (double)rand()/RAND_MAX*2.0; //float in range 0 to 2
		y = (double)rand()/RAND_MAX*2.0; //float in range 0 to 2
		double diff_x = x - 1.0;
		double diff_y = y - 1.0;
		double dist =diff_x * diff_x + diff_y * diff_y;
		if (sqrt(dist) <= radio) {
			n+=1;
		}
	}
	MPI_Allreduce(&n, &n_total, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	t2 = MPI_Wtime();

	if(rank == 0) {
		printf("pi value %.5f\n", 4*n_total*1.0/N);
		printf("time :: %.10f\n", t2-t1);
	}
	MPI_Finalize();


	return 0;
}

