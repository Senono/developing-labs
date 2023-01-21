#include <iostream>
#include <fstream>
#include <sstream>
#include "time.h"

#define z 10000


using namespace std;


void sort_vstavka(int* a, int n)
{
    int new_elem;
    int p;

    for (int i = 0; i < n; i++)
    {
        new_elem = a[i];
        p = i - 1;

        while (p >= 0 && a[p] > new_elem)
        {
            a[p + 1] = a[p];
            p -= 1;
        }

        a[p + 1] = new_elem;
    }
}


void SortShell(int* a, int n)
{
    int increment;
    for (increment = 1; 2 * increment < n; increment *= 2)
    {

        while (increment >= 1)
        {
            for (int start = 1; start <= increment; start++)
            {
                sort_vstavka(a, n, start, increment);
                cout << "Массив после прохождения " << increment << "шагов: ";
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " ";
                }
            }

            increment /= 2;
        }
        if (increment == 0) break;
    }
}


static int counter = 0;
//чтение чисел из файла в массив
int* read_file(int* arr)
{
    char str[32];
    long int i = 0;
    ifstream f_in("arr.txt");
    if (!f_in.is_open())
        cout << "Error in open file 2!\n";

    while (f_in.getline(str, 31))
    {
        arr[i] = atoi(str);
        ++i;
    }

    f_in.close();
    return arr;
}


//создание и заполнение числами файла
void create_file()
{
    srand(time(NULL));
    ofstream f_out("arr.txt");
    if (!f_out.is_open())
        cout << "Error in open file 1!\n";

    for (long int i = 0; i < z; i++)
        f_out << rand() % 1000 << endl;
}

void file_print(int arr[])
{
    ofstream f_out("arr_result.txt");
    if (!f_out.is_open())
        cout << "Error in open file 1!\n";

    for (int i = 0; i < z; i++)
        f_out << arr[i] << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    create_file();
    int* arr = new int[z];
    read_file(arr);
    SortShell(arr, z);
    file_print(arr);
    delete[]arr;


    return 0;
}
