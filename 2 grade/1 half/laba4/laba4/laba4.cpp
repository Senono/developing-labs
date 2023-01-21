#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
	double re, im;

	void show(Complex c) {
		cout << "(" << c.re << ", " << c.im << ")";
	}

public:
	Complex(double r = 0.0, double i = 0.0) { // Конструктор 
		re = r;
		im = i;
		cout << "Re = " << re << " , Im = " << im << endl;
	}

	~Complex() { // Деструктор
		//cout << "Работает деструктор" << endl;
	}

	Complex(const Complex& c) {    // Конструктор копирования
		re = c.re;
		im = c.im;
	}

	void plus(Complex c) {
		show(*this);
		cout << " + ";
		show(c);
		cout << " = ";
		re += c.re;
		im += c.im;
		show(*this);
	}

	void minus(Complex c) {
		cout << endl;
		show(*this);
		cout << " - ";
		show(c);
		cout << " = ";
		re -= c.re;
		im -= c.im;
		show(*this);
	}

	void multiply(Complex c) {
		cout << endl;
		show(*this);
		cout << " * ";
		show(c);
		cout << " = ";

		double temp = re;
		re = re * c.re - im * c.im;
		im = temp * c.im + c.re * im;
		show(*this);
	}

	void division(Complex c) {
		cout << endl;
		show(*this);
		cout << " / ";
		show(c);
		cout << " = ";

		double temp = re;
		re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
		im = (im * c.re - temp * c.im) / (c.re * c.re + c.im * c.im);
		show(*this);
	}

	void compare(Complex c) {
		cout << endl << "Идёт сравнение двух следующих комплексных чисел: ";
		show(*this);
		cout << " и ";
		show(c);

		if (re == c.re && im == c.im) {
			cout << "Комплексные числа равны";
		}
		else {
			if (c.re == re)
				cout << endl << "Re двух комплесных чисел равны";
			else if (c.re > re)
				cout << endl << "Re второго числа больше, чем Re первого";
			else
				cout << endl << "Re первого числа больше, чем Re второго";
			if (c.im == im)
				cout << endl << "Im двух комплексных числе равны";
			else if (c.im > im)
				cout << endl << "Im второго числа больше, чем Im первого";
			else
				cout << endl << "Im первого числа больше, чем Im второго";
		}
	}

	void sopr() {
		im = -im;
		cout << endl << "Sopr: ";
		show(*this);
	}

};

int main()
{
	setlocale(LC_ALL, "");

	Complex a(5, 2);
	Complex b(3, -1);

	a.plus(b);
	b.minus(a);
	a.multiply(a);
	a.division(b);
	a.compare(b);
	a.sopr();

	return 0;
}