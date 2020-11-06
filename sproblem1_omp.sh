#!/bin/bash
#SBATCH -J ej4 # nombre del job
#SBATCH -p investigacion # nombre de la particion 
#SBATCH -N 1 # numero de nodos
#SBATCH --tasks-per-node=4 # numero de tasks por nodo

#module load openmpi/2.1.6 
#module load gcc/7.5.0

srun problem1_omp
#./problem1_omp

#module unload gcc/7.5.0
#module unload openmpi/2.1.6 
