#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int amount1, amount2; // Кол-во слогаемых
	double sum = 0;
	cout << "Введите количество слогаемых для первого ряда и следом для второго: " << endl;
	cin >> amount1 >> amount2;

	for (double i = 1; i < amount1; i++) 
		sum += (1 / i);

	cout << "1: " << sum << endl;
	sum = 1;

	for (double i = 1; i < amount2; i++)
		sum = sum + (1 / (i * i));

	cout << "2: " << sum << endl;

}