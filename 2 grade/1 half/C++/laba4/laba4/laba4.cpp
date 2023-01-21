#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define FILE_NAME1 "polynom1.txt"
#define FILE_NAME2 "polynom2.txt"

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream firstPolynomFILE(FILE_NAME1);
	if (!firstPolynomFILE) cout << "Ошибка чтения первого файла!" << endl;
	else cout << "Первый файл успешно открыт!" << endl;

	ifstream secondPolynomFILE(FILE_NAME2);
	if (!secondPolynomFILE) cout << "Ошибка чтения второго файла!" << endl;
	else cout << "Второй файл успешно открыт!" << endl;


	vector<int> firstPolynom;
	vector<int> secondPolynom;

	int tmp;

	int firstCount;
	firstPolynomFILE >> firstCount;
	while (firstPolynomFILE >> tmp) {
		firstPolynom.push_back(tmp);
	}
	cout << "Первый полином: ";
	for (unsigned int i = 0; i < firstPolynom.size(); i++) 
		cout << firstPolynom[i] << "x^" << i << " ";

	int secondCount;
	secondPolynomFILE >> secondCount;
	while (secondPolynomFILE >> tmp) {
		secondPolynom.push_back(tmp);
	}
	cout << endl << "Второй полином: ";
	for (unsigned int i = 0; i < secondPolynom.size(); i++)
		cout << secondPolynom[i] << "x^" << i << " ";

	vector<int> thirdPolynom;
	if (firstCount > secondCount)
		for (int i = 0; i < firstCount; ++i)
			thirdPolynom.push_back(0);

	for (unsigned int i = 0; i < firstPolynom.size(); ++i) {
		for (unsigned int j = 0; j < secondPolynom.size() - i; ++j) {
			int smesh = j + i;
			thirdPolynom[smesh] += (firstPolynom[i] * secondPolynom[j]);
		}
	}

	cout << endl << "Полученный полином после умножения двух прошлых: ";
	for (unsigned int i = 0; i < thirdPolynom.size(); i++)
		cout << thirdPolynom[i] << "x^" << i << " ";

	firstPolynomFILE.close();
	secondPolynomFILE.close();
}