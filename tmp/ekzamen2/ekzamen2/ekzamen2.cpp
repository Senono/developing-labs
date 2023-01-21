#include <iostream>
using namespace std;

//int fibonachi(int n) {
//    if (n == 0) return 0;
//    if (n == 1) return 1;
//    return fibonachi(n - 1) + fibonachi(n - 2);
//}

int main()
{
    int x = 12;
    int* p = &x;
    x = *p += 3;
    cout << x;
    /*int n;
    for (int i = 1; i < 10; i++) {
        n = fibonachi(i);
        cout << n << " ";
    }*/
   /* struct User {
        string name;
        int age;
    };

    struct User arr[12];

    arr[1].age = 2;
    arr[11].name = "Alex";

    cout << arr[1].age << " " << arr[11].name;*/
}