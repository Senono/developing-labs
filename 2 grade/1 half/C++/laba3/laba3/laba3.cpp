#include <iostream>
using namespace std;

template<class T> class List {
private:
	int m_length;
	int m_point = 0;
	T* m_array;
public:
	List(int length) : m_length(length) {
		if (length <= 0)
			throw "Длина списка не может быть меньше или равна нулю";

		if (length > 0)
			m_array = new T[length];
		else
			m_array = nullptr;
	}

	~List() {
		delete[] m_array;
	}

	T& operator[](int index) {
		if (index < 0)
			throw "Индекс не может быть меньше нуля";
		if (index >= m_point)
			throw "Индекс не может превышать длину списка";
		return m_array[index];
	}

	int getLength() { return m_point; }

	void push_back(T a) {
		if (m_point == m_length)
			throw "Список достиг максимальной длины";
		m_array[m_point++] = a;
	}

	void pop_backN(int num) {
		if (m_point == 0)
			throw "Список пуст. Невозможно удалить элементы";
		if (num > m_point)  
			throw "Вы пытаетесь удалить больше элементов, чем существует в массиве";

		int len = m_length - num;
		T* data = new T[len];

		for (int index = 0; index < len; ++index)
			data[index] = m_array[index];

		delete[] m_array;
		m_array = data;
		m_point -= num;
	}

	void show() {
		if (m_point == 0) cout << "Список пуст!";
		for (int i = 0; i < m_point; ++i)
			cout << m_array[i] << " ";
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	try {
		List<int> list1(4);
		//List<int> list2(-1);
		//List<double> list3(0);
		list1.push_back(2);
		list1.push_back(4);
		list1.push_back(4);
		list1.push_back(4);
		//list1.push_back(4);
		//cout << list1[-1];
		//cout << list1[4];
		cout << list1[3] << endl;
		list1.show();

		list1.pop_backN(1);
		list1.show();
		list1.pop_backN(3);
		list1.show();
		list1.pop_backN(2);
	}
	catch(const char *str) {
		cout << str;
	}
}