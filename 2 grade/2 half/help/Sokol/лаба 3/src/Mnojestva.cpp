#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iterator>
#include <algorithm>
#include "Mnojestva.h"
using namespace std;

void Mnozhestvo::add(){
    char k;
    int z;

    cout << "������� ""a"", ���� �������� ������� � ��������� A, ��� ""b"", ���� �������� ������� � ��������� B:" << endl;
    cin >> k;

    if(k == 'a'){
        cout<<"������� ����� ������� ������ ��������" <<endl;
        cin>> z;
        a.insert(z);
        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    if(k == 'b'){
        cout<<"������ ����� ������� ������ ��������" <<endl;
        cin>> z;
        b.insert(z);
        copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}
void Mnozhestvo::element(){
    int g;
    cout << "������� ����� ��������" << endl;
    cin >> g;
}


void Mnozhestvo::crossing()
{
    multiset<int> c;

    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));

    if(c.empty())
        cout << "��������� ������." << endl;
    else{
    copy(c.begin(), c.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
   }
}
int Mnozhestvo::Menu()
{
    int key = 0, i;

    for(i = 0;i < 1000;i++){

    cout << "�������� ����� ��������, ������� ����� ����������� ��� ����������(���): " << endl;
    cout << "1 - ���������� ��������" << endl;
    cout << "2 - ����������� ��������" << endl;
    cout << "3 - ����� ������� ����� g" << endl;
    cout << "0 - ����� �� ���������" << endl;

    cin >> key;

    switch (key)
    {
    case 1:
        add();
        break;
    case 2:
        crossing();
        break;
    case 3:
        element();
        break;
    case 0:
        system("pause");
        return 0;
    default:
        break;
    }
  }
}
