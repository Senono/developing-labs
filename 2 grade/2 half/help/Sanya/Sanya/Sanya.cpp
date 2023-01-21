#include <iostream>
#include <ctime>

using namespace std;

int i = 0;


class w_arr
{
private:
	static int size1;
	static int *arr;
public:
	class _nested {
	public:
		_nested() {
			size1 = 10;
			arr = new int[size1];

			for (i = 0; i < size1; i++)
			{
				arr[i] = rand() % 10;
			}
		}
	};
	
	//static void get_arr1(int size) {
	//	
	//}
	//static void get_arr2() {
	//	//выделение памяти для двумерного массива

	//}
	//static void get_clear() {
	//	//освобождение памяти
	//	delete[] * arr;
	//}
	static void get_arr() {
		//печать массива
		for (i = 0; i < size1; i++)
		{
			cout << arr[i] << endl;
			//cout << arr + i << endl;
		}
	}
private:
	static _nested s_init;
};

int w_arr::size1;
int* w_arr::arr;
w_arr::_nested w_arr::s_init;


int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	w_arr::get_arr();
	//arr.get_arr();
	//name.get_arr1(1);
	//cout << "Hello World!\n";
}