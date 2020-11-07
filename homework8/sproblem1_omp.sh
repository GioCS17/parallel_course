#!/bin/bash
#SBATCH -J ej4 # nombre del job
#SBATCH -p investigacion # nombre de la particion 
#SBATCH -N 4 # numero de nodos
#SBATCH --tasks-per-node=4 # numero de tasks por nodo

./problem1_omp

