#include <iostream>
using namespace std;

#define LENGTH 10

int InterpolSearch(int* arr, int n, int key) {
    int left = 0; // Левая граница
    int right = n - 1; // Правая граница
    int mid; // Разделительный элемент

    while (arr[left] <= key && arr[right] >= key)
    {
        mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if (arr[mid] < key) left = mid + 1;
        else if (arr[mid] > key) right = mid - 1;
        else return mid;
    }
    if (arr[left] == key) return left;
    else return -1;
    //}
    //
    //    while (arr[left] <= key && arr[right] >= key) {
    //        mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
    //        cout << "mid = " << mid << "left = " << left << "right = " << right << endl;
    //        if (arr[mid] < key) left = mid + 1;
    //        else if (arr[mid] > key) right = mid - 1;
    //        else return mid;
    //    }
    //
    //    if (arr[left] == key) return left;
    //    if (arr[right] == key) return right;
    //    else return -1;
}

int main()
{
    setlocale(LC_ALL, "");

    int arr[LENGTH] = { 1, 2, 3, 4, 10, 100, 1000, 1111, 100000, 10000000 };
    int key;

    cout << "Введите искомый элемент: ";
    cin >> key;

    int result = InterpolSearch(arr, 10, key);
    if (result == -1) cout << endl << "Элемент не найден" << endl;
    else cout << endl << "Индекс элемента: " << result << endl;

}