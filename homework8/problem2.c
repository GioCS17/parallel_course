#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<math.h>
#include<omp.h>
#include<mpi.h>

int main() {
	int rank, n_p;
	int max_n = 10000000;
	int n_threads = 16;
	double sum_g = 0;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &n_p);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int local_n = max_n / n_p; 
	int l_local= rank * local_n;
	int r_local= l_local + local_n;
	double local_sum = 0;
	double x;
	
	double t1, t2;

	t1 = MPI_Wtime();

	#pragma omp parallel for num_threads(n_threads) reduction(+:local_sum) private(x) shared(l_local, r_local, max_n)
		for (int i = l_local; i < r_local; i ++) {
			x = (i - 0.5) / max_n;
			local_sum += 4 / (1 + x * x);
		}
	
	MPI_Reduce(&local_sum, &sum_g, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	t2 = MPI_Wtime();
	
	if (rank == 0) {
		printf("time : %.6f\n", t2 - t1);
		printf("PI Value: %.6f\n", sum_g / max_n);
	}
	
	MPI_Finalize();
	
	
	return 0;
}

