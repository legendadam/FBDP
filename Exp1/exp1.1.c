#include <stdio.h>
#include <stdlib.h>
#include <mpi/mpi.h>
#include <math.h>

int main(int argc, char **argv)
{
    int myid, numprocs, j;
    double sum = 0.0, result = 0.0;
    int N = atoi(argv[1]);
    long data[N], i;
    for (i = 0; i < N; i++)
    {
        data[i] = i * (i + 1);
    }
    MPI_Init(&argc, &argv);
    MPI_Barrier(MPI_COMM_WORLD);
    double start = MPI_Wtime();
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    for (j = myid; j < N; j += numprocs)
    {
        sum += sqrt(data[j]);
    }
    printf("I am process %d. Sum = %f.\n", myid, sum);
    MPI_Reduce(&sum, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (myid == 0)
    {
        printf("Result = %f.\n", result);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    double end = MPI_Wtime();
    MPI_Finalize();
    printf("I am process %d. Running time = %f.\n", myid, end - start);
}