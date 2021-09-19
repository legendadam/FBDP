#define N 100000000
#define a 10
#define b 100
#include <stdio.h>
#include <stdlib.h>
#include <mpi/mpi.h>
int main(int argc, char **argv)
{
    int myid, numprocs, i, j;
    double dx = (double)(b - a) / N, x, d;
    double sum = 0.0, result = 0.0;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    for (i = myid; i < N; i = i + numprocs)
    {
        x = a + i * dx + dx / 2;
        sum += x * x * x * dx;
    }
    printf("I am process %d. Sum = %f.\n", myid, sum);
    if (myid != 0)
    {
        MPI_Send(&sum, 1, MPI_DOUBLE, 0, 99, MPI_COMM_WORLD);
    }
    else
    {
        result = sum;
        for (j = 1; j < numprocs; j++)
        {
            MPI_Recv(&d, 1, MPI_DOUBLE, j, 99, MPI_COMM_WORLD, &status);
            result += d;
        }
        printf("The integal of x*x in region [%d,%d] =%16.15f\n", a, b, result);
    }
    MPI_Finalize();
}