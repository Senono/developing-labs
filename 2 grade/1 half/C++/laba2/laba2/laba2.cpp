#include <iostream>
using namespace std;

#define LENGTH 100

template <class X> class DoubleArr {
private:
	X** arr;

	int line = -1;
	unsigned int lSize;
	int sizes[LENGTH]; // Массив с длинами строк
public:
	DoubleArr() {
		arr = new X*[LENGTH];
	}

	~DoubleArr() {
		delete arr;
	}

	void addLine() {
		line++;
		cout << "Введите размер новой строки: ";
		cin >> lSize;
		arr[line] = new X[lSize];
		// Добавление размера новой строки в массив с длинами
		sizes[line] = lSize;
		cout << "Введите элементы " << line + 1 << " строки: " << endl;
		for (unsigned int i = 0; i < lSize; i++) {
			cin >> arr[line][i];
		}
	}

	void show() {
		for (int i = 0; i < (line + 1); ++i) {
			for (int j = 0; j < sizes[i]; ++j) {
				cout << "[" << arr[i][j] << "]";
			}
			cout << endl;
		}
	}
};

class Fraction {
private:
	double numerator, denominator;
public:
	Fraction(double n = 1, double d = 1) {
		numerator = n;
		denominator = d;
	}

	~Fraction() {}

	Fraction(const Fraction& f) {
		numerator = f.numerator;
		denominator = f.denominator;
	}

	const Fraction operator+(const Fraction& frac) {
		Fraction tmp;
		double gen = 0;
		if (denominator == frac.denominator) {
			tmp.denominator = denominator;
			tmp.numerator = numerator + frac.numerator;
		}
		else {
			for (double i = denominator; denominator % i != 0 && frac.denominator != 0; i++)
				gen = i;
			tmp.numerator = gen / denominator * numerator + gen / frac.denominator * frac.numerator;
			tmp.denominator = gen;
		}

		return tmp;
	}

	const Fraction operator-(const Fraction& frac) {
		Fraction tmp;
		double gene = 0;
		if (denominator == frac.denominator) {
			tmp.denominator = denominator;
			tmp.numerator = numerator - frac.numerator;
		}
		else {
			for (double i = denominator; (int)(denominator % i)!= 0 && frac.denominator != 0; i++) {
				cout << gene;
				gene = i;
			}
			tmp.numerator = gene / denominator * numerator - gene / frac.denominator * frac.numerator;
			tmp.denominator = gene;
		}

		return tmp;
	}

	const Fraction operator*(const Fraction& frac) {
		Fraction tmp;
		tmp.numerator = numerator * frac.numerator;
		tmp.denominator = denominator * frac.denominator;

		return tmp;
	}

	bool operator == (const Fraction& frac) {
		return (this->numerator == frac.numerator && this->denominator == frac.denominator);
	}

	friend ostream& operator<< (ostream& out, const Fraction& frac);
	friend istream& operator>> (istream& in, Fraction& frac);
};

class Complex {
private: 
	double re, im, abs;
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

	const Complex operator+(const Complex& comp) {
		Complex tmp;
		tmp.re = re + comp.re;
		tmp.im = im + comp.im;
		tmp.init();

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

	bool operator == (const Complex& comp) {
		return this->abs == comp.abs;
	}

	friend ostream& operator<< (ostream& out, const Complex& comp);
	friend istream& operator>> (istream& in, Complex& comp);
};

ostream& operator<< (ostream& out, const Fraction& frac) {
	out << frac.numerator << "/" << frac.denominator;
	return out;
}

istream& operator>> (istream& in, Fraction& frac) {
	cout << "Введите числитель: ";
	in >> frac.numerator;
	cout << "Введите знаменатель: ";
	in >> frac.denominator;
	cout << "Numerator = " << frac.numerator << " Denominator = " << frac.denominator << endl;

	return in;
}

ostream& operator<< (ostream& out, const Complex& comp) {
	out << "(" << comp.re << "," << comp.im << ")";
	return out;
}
	
istream& operator>> (istream& in, Complex& comp) {
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

	Fraction frac1, frac2;
	cin >> frac1 >> frac2;
	cout << frac1 - frac2;

	DoubleArr<double> arr;
	arr.addLine();
	arr.addLine();
	arr.addLine();
	arr.addLine();
	arr.addLine();
	arr.show();
	DoubleArr<Complex> arr2;
	arr2.addLine();
	arr2.show();
	DoubleArr<Fraction> arr3;
	arr3.addLine();
	arr3.addLine();
	arr3.show();
}