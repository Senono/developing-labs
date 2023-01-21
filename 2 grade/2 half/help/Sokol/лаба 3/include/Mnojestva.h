#ifndef MNOZHESTVO_H
#define MNOZHESTVO_H
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iterator>
#include <cassert>
using namespace std;

class Mnozhestvo{
private:
    int m_length;
    int *m_data;
public:
    Mnozhestvo()
    {
    int i, j;
    cout << "Введите количество элементов в множестве a:" << endl;
    cin >> n;
    cout << "Введите количество элементов в множестве b:" << endl;
    cin >> m;

    srand(time(NULL));

    for(i = 0;i < n;i++){
        j = 1 + rand() % 50;
        a.insert(j);
    }

    cout << "Множество A:" << endl;

    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Множество B:" << endl;

    for(i = 0;i < m;i++){
        j = 1 + rand() % 50;
        b.insert(j);
    }

    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
};

int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void add();
    void element();
    void crossing();
    int Menu();
private:
    multiset<int> a;
    multiset<int> b;
    int n;
    int m;
};


#endif
