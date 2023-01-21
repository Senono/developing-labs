// container_try_catchVC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	int max_size;
	int it = 0; //iterator
	T* array;
public:
	List(int m_s) : max_size(m_s)
	{
		if (m_s <= 0) { throw "Длина массива не может быть меньше , либо равна нулю"; }
		if (m_s > 0)
		{
			array = new T[m_s];
		}
		else
		{
			array = nullptr;
		}
	}

	T& operator[] (const int index)
	{
		if (index < 0) { throw "Индекс меньше нуля"; }
		if (index >= it) { throw "Индекс за пределами длины списка"; }
		return array[index];
	}

	int get_size() { return it; }

	void push_back(T element)
	{
		if (it == max_size) { throw "Список переполнен."; }
		else {
			array[it++] = element;
		};
	};

	void print()
	{
		if (it == 0)
		{
			throw "Список пуст";
		}
		else {
			for (int i = 0; i < it; i++)
			{
				cout << array[i] << "\t";
			}
		}
	}
	const List operator-- (const int i)
	{
		it--;
		return List(array[it]);
	}

	const List operator-- ()
	{
		for (int i = 0; i < it - 1; i++)
		{
			array[i] = array[i + 1];
		}
		it--;
		return List(array[it]);
	}

	~List()
	{
		delete[] array;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	try {
		List<int> list1(5);

		for (int i = 0; i < 5; i++)
		{
			list1.push_back(i);
		}

		list1.print();

		cout << endl << "list[4] = " << list1[4] << endl;

		cout << "длина списка : " << list1.get_size() << endl;


		cout << endl << "Удаление последнего элемента :" << endl;
		list1--;

		list1.print();


		cout << endl << "Добавление элемента 5 :" << endl;
		list1.push_back(5);

		list1.print();

		cout << endl << "Удаление первого элемента :" << endl;
		--list1;
		list1.print();
	}
	catch (const char* str)
	{
		cout << str;
	}

	//std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
