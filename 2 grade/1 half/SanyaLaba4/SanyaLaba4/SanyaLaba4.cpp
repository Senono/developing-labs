#include <iostream>

using namespace std;

class Stack
{
private:
	int i = 0;
	int size = 99;
	int* arr = new int[size];

public:
	void push_back(int num)
	{
		arr[i] = num;
		arr[++i] = NULL;
		cout << "Число = " << num << " успешно добавлено!\n" << endl;
	}

	void pop_back()
	{
		cout << "Удалён последний элемент\n" << endl;
		arr[--i] = NULL;
	}

	void capacity()
	{

		cout << "Длина стека: " << i << endl;


	};

	void show()
	{
		for (i = 0; arr[i]; i++)
			cout << "Элемент с индексом [" << i << "] = " << arr[i] << endl;
	}


};
int main()
{
	setlocale(LC_ALL, "");

	Stack digital;

	int amount;
	cout << "Введите количество элементов в стек: ";
	cin >> amount;
	cout << endl;

	for (int i = 0; i < amount; i++)
	{
		int num;
		cout << "Введите " << i << " Элемент: ";
		cin >> num;
		digital.push_back(num);

	}

	/* digital.push_back(1);
	 digital.push_back(2);
	 digital.push_back(3);
	 digital.push_back(3);
	 digital.push_back(3);
	 digital.push_back(3);*/


	digital.pop_back();
	digital.show();
	digital.capacity();



	return 0;
}
