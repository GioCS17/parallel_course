all: p1_omp p1_mpi

p1_omp: problem1_omp.c
	@gcc -fopenmp -o problem1_omp problem1_omp.c -lm
	@sbatch sproblem1_omp.sh

p1_mpi: problem1_mpi.c
	@mpicc -o problem1_mpi problem1_mpi.c -lm
	@sbatch sproblem1_mpi.sh

p2_hib: problem2.c
	@mpicc -fopenmp problem2.c -o problem2
	@sbatch sproblem2.sh
clear: 
	rm problem1_omp
	rm problem1_mpi
