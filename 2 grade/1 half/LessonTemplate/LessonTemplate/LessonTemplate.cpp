#include <iostream>
#include <typeinfo>
using namespace std;

class A { virtual void f() {} };

int main()
{
	setlocale(LC_ALL, "");
	A a_ob;
	cout << typeid(a_ob).name();
}