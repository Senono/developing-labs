#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Rus"); // Русский язык
	srand(time(NULL)); // Фикс рандома

	int firstMatrixStr, firstMatrixCol, secondMatrixStr, secondMatrixCol;
	printf("Введите количество строк первой матрицы: ");
	scanf_s("%d", &firstMatrixStr);
	printf("Введите количество столбцов первой матрицы: ");
	scanf_s("%d", &firstMatrixCol);
	printf("Введите количество строк второй матрицы: ");
	scanf_s("%d", &secondMatrixStr);
	printf("Введите количество столбцов второй матрицы: ");
	scanf_s("%d", &secondMatrixCol);

	if (firstMatrixCol != secondMatrixStr) return 1; // Проверка возможности умножения матриц

	int resultMatrixStr = firstMatrixStr;
	int resultMatrixCol = secondMatrixCol;

	// Создание матриц в виде динамических двумерных массивов
	int** firstMatrix = (int**)malloc(sizeof(int*) * firstMatrixStr);
	for (int i = 0; i < firstMatrixStr; ++i)
		firstMatrix[i] = (int*)malloc(sizeof(int) * firstMatrixCol);

	int** secondMatrix = (int**)malloc(sizeof(int*) * secondMatrixStr); 
	for (int i = 0; i < secondMatrixStr; ++i)
		secondMatrix[i] = (int*)malloc(sizeof(int) * secondMatrixCol); 

	int** resultMatrix = (int**)malloc(sizeof(int*) * resultMatrixStr);
	for (int i = 0; i < resultMatrixStr; ++i)
		resultMatrix[i] = (int*)malloc(sizeof(int) * resultMatrixCol);

	// Заполнение матриц случайными числами
	printf("Первая матрица: \n");
	for (int i = 0; i < firstMatrixStr; ++i) {
		for (int j = 0; j < firstMatrixCol; ++j) {
			firstMatrix[i][j] = rand() % (sizeof(int*) * firstMatrixStr);
			printf("[%d] ", firstMatrix[i][j]);
		}
		printf("\n");
	}
	printf("Вторая матрица: \n");
	for (int i = 0; i < secondMatrixStr; ++i) {
		for (int j = 0; j < secondMatrixCol; ++j) {
			secondMatrix[i][j] = rand() % 100;
			printf("[%d] ", secondMatrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < resultMatrixStr; ++i)
		for (int j = 0; j < resultMatrixCol; ++j)
			resultMatrix[i][j] = 0;

	printf("Итоговая матрица: \n");
	for (int i = 0; i < resultMatrixStr; ++i) {
		for (int j = 0; j < resultMatrixCol; ++j) {

				for (int k = 0; k < firstMatrixCol; ++k)
					resultMatrix[i][j] += (firstMatrix[i][k] * secondMatrix[k][j]);
				printf("[%d] ", resultMatrix[i][j]);

		}
		printf("\n");
	}

	return 0;
}