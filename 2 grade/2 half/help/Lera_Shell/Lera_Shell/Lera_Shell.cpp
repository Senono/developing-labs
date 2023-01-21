//#include "InSort.h"
#include <iostream>
using namespace std;

void InsertionSort(int* arr, int N, int start, int increment) {
	//����������� ������ ���������
			   //����� ��������� � ������
	for (int i = start + increment; i < N; i += increment) {
		if (arr[i - increment] > arr[i]) {
			int tmp = arr[i];
			int z;
			for (z = i; z > start&& arr[z - increment] > tmp; z -= increment) 
				arr[z] = arr[z - increment]; // �������� �������� ������, ���� �� ����� ����� ����� z
			arr[z] = tmp;
		}
	}
}

void SortShell(int* list, int N) {
	//int count;
	for (int increment = N / 2; increment > 0; increment /= 2)
		for (int start = 0; start < increment; start++)
			InsertionSort(list, N, start, increment);
	cout << "������ ����� ����������:" << endl;
	for (int i = 0; i < N; i++)
		cout << list[i] << " ";

	//return 0;
}

/*int ShellSort(int *list, int N) {
			//����������� ������ ���������
					   //����� ��������� � ������

passes = [log_2 N];
while (passes >= 1) {
	increment = 2^passes-1;
	for (int start = 1; start < increment; start++) {
		InsertionSort(list, N, start, increment);
	 }

	passes = passes - 1;
   }
}*/

int main() {
	setlocale(LC_ALL, "Rus");

	int N;
	cout << "������ ������� = ";
	cin >> N;
	int* list = new int[N]; //���������� ������������� �������

	for (int i = 0; i < N; i++) {
		cout << i + 1 << " ������� = ";
		cin >> list[i];
	}

	SortShell(list, N);

	delete[] list;
	return 0;
}
