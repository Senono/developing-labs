#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <omp.h>

#define EPSILON 1.0e-14 // точность вычисления
// значений функции 8 double BesselJ0(double );
double BesselJ0(double x);
int main ()
{
double a, b, delta; 
double *res; // объявление массива
// значений функции
 int N;
 FILE *fp;
 if ((fp = fopen("input.txt","r")) == NULL)
 {
perror("\nОшибка открытия файла " "\"input.txt\"");
exit(EXIT_FAILURE );
 }
 fscanf(fp , "%lf %lf %lf", &a, &b, &delta ); 
 fclose(fp);
 if (( delta < 0.0) || (a >= b))
 {
printf("\nНекорректные входные данные\n");
exit(EXIT_FAILURE );
 }
 N = (b - a) / delta + 1; 
res = (double *) malloc(N*sizeof(double )); 
if ( res == NULL )
 {
perror("\nОшибка выделения памяти для массива res");
exit(EXIT_FAILURE );
 }
 double t1 = omp_get_wtime ();
 #pragma omp parallel for schedule(guided) 
 for(int i = 0; i < N; i++) 
  res[i] = BesselJ0(a + i * delta );
 double t2 = omp_get_wtime ();
 printf("Время , затраченное на вычислительный цикл , равно %.3lf с.\n", t2 - t1);
fp = fopen("output.txt", "w"); 
for(int i = 0; i < N; i++) 
fprintf(fp , "% .14e\t % .14e\n",a+i*delta, res[i]);
 fclose(fp); 
 free(res);
 return 0;
 }
 double BesselJ0(double x)
 {
 int k=0; 
double a=1.0; // текущий коэффициент
// ряда Тейлора 
double f=1.0; // частичная сумма
// ряда Тейлора 
while ( fabs(a) >= EPSILON )
 {
k++;
a = -a*x*x/(4.0*k*k);
f += a;
 }
 return f;
 }
// gcc -g -Wall -std=c99 -fopenmp borz.c -o borz.out
//g++ borz.c -o borz-2.out -fopenmp

