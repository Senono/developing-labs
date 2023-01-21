#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int main()
{
    int i = 3;

    int matrix[3][3];
    int vector[3];
    int resVector[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i + j;
            cout << matrix[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++) {
        vector[i] = i;
        cout << vector[i] << endl;
    }
    int rank;
#pragma omp parallel private(rank){
    rank = omp_get_thread_num();
#pragma omp for 
    for (int j = 0; j < 3; i++)
        resVector[rank] += matrix[rank][j] * vector[j];
    }
}