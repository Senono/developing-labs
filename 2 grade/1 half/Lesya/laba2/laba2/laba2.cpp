#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define COL 3 // Кол-во колонок и строк 

int main()
{
	setlocale(LC_ALL, "Rus"); // Русский язык
	srand(time(NULL)); // Фикс рандома 

	int maxStr = 0; // Максимальная сумма
	int tmpStr = 0; // Подсчет суммы в цикле
	int maxIndex; // Номер строчки с максимальной суммой

	int matrix[COL][COL];
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < COL; j++) {
			matrix[i][j] = rand() % 100; // Заполнение матрицы рандомными элементами 
			tmpStr += matrix[i][j]; // Сложение строчки 
			printf("[%d] ", matrix[i][j]);
		}

		if (tmpStr > maxStr) { // Если сумма нынешней строчки больше максимальной суммы на данный момент
			maxStr = tmpStr; // Заменяем максимальную сумму
			maxIndex = i; // Записываем в переменную maxIndex номер строчки
		}
		tmpStr = 0; // Обнуляем временную строчку
		printf("\n");
	}

	printf("Max Sum = %d\n", maxStr);
	for (int i = 0; i < COL; i++)
		printf("[%d] ", matrix[maxIndex][i]); // Вывод строчки
		
	return 0;
}