#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <omp.h>

int main()
{
 printf("Здравствуй, друг!\n");
 #pragma omp parallel
 { int i,n;
 i = omp_get_thread_num();
 n = omp_get_num_threads();
 printf("Я поток № %d из %d\n",i,n);
 }
 return 0;
}
// g++ omp-example-1.c -o omp-example-1.out -fopenmp
