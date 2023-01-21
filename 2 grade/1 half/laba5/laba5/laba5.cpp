#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
	double re, im, abs;

	void show(Complex c) {
		cout << "(" << c.re << ", " << c.im << ")";
	}

public:
	Complex(double r = 0.0, double i = 0.0) { // Конструктор 
		re = r;
		im = i;
		abs = sqrt(r * r + i * i);
	}

	~Complex() {} // Деструктор

	Complex(const Complex& c) {    // Конструктор копирования
		re = c.re;
		im = c.im;
		abs = sqrt(c.re * c.re + c.im * c.im);
	}

	void init() {
		abs = sqrt(re * re + im * im);
	}

	void plus(Complex c) {
		cout << *this << " + " << c << " = ";
		re += c.re;
		im += c.im;
		cout << *this;
	}

	void minus(Complex c) {
		cout << endl << *this << " - " << c << " = ";
		re -= c.re;
		im -= c.im;
		cout << *this;
	}

	void multiply(Complex c) {
		cout << *this << " * " << c << " = ";
		double temp = re;
		re = re * c.re - im * c.im;
		im = temp * c.im + c.re * im;
		cout << *this;
	}

	void division(Complex c) {
		cout << *this << " / " << c << " = ";
		double temp = re;
		re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
		im = (im * c.re - temp * c.im) / (c.re * c.re + c.im * c.im);
		cout << *this;
	}

	void compare(Complex c) {
		cout << endl << "Идёт сравнение двух следующих комплексных чисел: ";
		cout << *this << " и " << c;

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
		cout << *this;
	}

	const Complex operator+(const Complex &comp) {
		Complex tmp;
		tmp.re = re + comp.re;
		tmp.im = im + comp.im;

		return tmp;
	}

	const Complex operator-(const Complex& comp) {
		Complex tmp;
		tmp.re = re - comp.re;
		tmp.im = im - comp.im;

		return tmp;
	}

	const Complex operator*(const Complex& comp) {
		Complex tmp;
		tmp.re = re * comp.re - im * comp.im;
		tmp.im = re * comp.im + comp.re * im;
		
		return tmp; 
	}

	bool operator == (const Complex & comp) {
		return this->abs == comp.abs;
	}
	
	friend ostream& operator<< (ostream &out, const Complex& comp);
	friend istream& operator>> (istream &in, Complex& comp);
	double getAbs() {
		return abs;
	}
};

ostream& operator<< (ostream &out, const Complex &comp) {
	out << "(" << comp.re << "," << comp.im << ")";
	return out;
}

istream& operator>> (istream &in, Complex &comp) {
	cout << "Введите действительную часть комплексного числа: ";
	in >> comp.re;
	cout << "Введите мнимую часть комплексного числа: ";
	in >> comp.im;
	cout << "Re = " << comp.re << " , Im = " << comp.im << endl;

	return in;
}

int main()
{
	setlocale(LC_ALL, "");

	Complex a, b;
	cin >> a >> b;
	a.init();
	b.init();

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " == " << b << " - " << (a == b) << endl;
	a.multiply(a);
	a.division(b);
	a.compare(b);
	a.sopr();

	return 0;
}