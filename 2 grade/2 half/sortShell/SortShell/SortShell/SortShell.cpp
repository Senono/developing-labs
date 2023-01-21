#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FILE "sort.txt"

int sortVstavka(int* a, int n, int k, int j) {
    int count = 0;
    for (int i = k + j; i < n; i += j) {
        if (a[i - j] > a[i]) {
            int tmp = a[i];
            int z;
            for (z = i; z > k&& a[z - j] > tmp; z -= j) {
                a[z] = a[z - j]; // Сдвигаем элементы вправо, пока не найдём нужно место z
                count++;
            }
            a[z] = tmp;
            count++;
        }
    }
   /* for (int i = k + j; i < n; i += j)
        for (int z = i; z > k&& a[z - j] > a[z]; z -= j) {
            swap(a[z - j], a[z]);
            count++;
        }*/
    return count;
}

int sortShell(int* a, int n) {
    int count = 0;
    for (int increment = n / 2; increment > 0; increment /= 2) {
        for (int start = 0; start < increment; start++) {
            count += sortVstavka(a, n, start, increment);
            cout << endl << "Массив после сортировки вставкой с элемента " << start << " и шагом " << increment << ": ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
        }
        //Проверка
        /*cout << endl<< "Массив после прохождения " << increment << " Шагов: ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";*/
    }
    /*int increment;
    for (increment = 1; 2 * increment < n; increment *= 2);
        while (increment >= 1) {
            for (int start = 1; start <= increment; start++) count += sortVstavka(a, n, start, increment);
            increment /= 2;
        }*/
    return count;
}


int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int n;
    cout << "Введите желаемое количество чисел для записи в файл: ";
    cin >> n;

    int* arr = new int[n];

    ofstream fout(FILE);
    if (!fout.is_open()) {
        cout << "Ошибка при открытии файла для записи" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
        fout << rand() % 100 + 1 << " ";
    fout.close();

    ifstream fin(FILE);
    if (!fin.is_open()) {
        cout << "Ошибка при открытии файла для чтения" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
        cout << arr[i] << " ";
    }
    fin.close();

    //int test[8] = { 56, 43, 12, 78, 42, 93, 16, 55 };

    //unsigned int start_time = clock();
     cout << "Количество операций: " << sortShell(arr, n);
    //unsigned int end_time = clock(); // конечное время
    //unsigned int search_time = end_time - start_time; // искомое время
    //cout << endl << "Время выполнения программы : " << search_time/1000.0;

    //getchar();
    //sortVstavka(test, n, 3, 1);
    cout << endl << "Полученный отсортированный массив после сортировки методом Шелла:" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
     getchar();
    fout.open(FILE);
    if (!fout.is_open()) {
        cout << "Ошибка при открытии файла для записи" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
        fout << arr[i] << " ";
    fout.close();
}