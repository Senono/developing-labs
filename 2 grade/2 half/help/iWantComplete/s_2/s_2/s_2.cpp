// num_denom_VS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Fraction
{
private:
	int numerator, denominator;
public:

	Fraction(int num = 0, int denom = 0)
	{
		numerator = num;
		denominator = denom;
	}

	const Fraction operator+(const Fraction& right)
	{
		//	(num1*denom2)+(num2*denom1) , (denom1*denom2)
		return Fraction((this->numerator * right.denominator) + (right.numerator * this->denominator), this->denominator * right.denominator);
	}

	const Fraction operator*(const Fraction& right)
	{
		//	num1*num2 , denom1*denom2
		return Fraction(this->numerator * right.numerator, this->denominator * right.denominator);
	}

	const Fraction operator= (const Fraction& right)
	{
		return Fraction(this->numerator = right.numerator, this->denominator = right.denominator);
	}

	void print()
	{
		cout << numerator << "/" << denominator << endl;
	}

	const bool operator == (const Fraction& right)
	{
		bool check = false;
		if (this->numerator == right.numerator && this->denominator == right.denominator) { check = true; };
		return check;
	}

	const bool operator > (const Fraction& right)
	{
		bool check = false;
		// (num1*denom2) (num2*denom1)
		if ((this->numerator * right.denominator) > (right.numerator * this->denominator)) { check = true; };
		return check;
	}

	const bool operator < (const Fraction& right)
	{
		bool check = false;
		// (num1*denom2) (num2*denom1)
		if ((this->numerator * right.denominator) < (right.numerator * this->denominator)) { check = true; };
		return check;
	}


};

class Complex
{
private:
	double real, imaginary;
public:
	Complex(double re = 0, double im = 0)
	{
		real = re;
		imaginary = im;
	}
	const Complex operator+ (const Complex& right)
	{
		return Complex(this->real + right.real, this->imaginary + right.imaginary);
	}
	void print()
	{
		cout << real << " + " << imaginary << "i" << endl;
	}
	const Complex operator* (const Complex& right)
	{
		//re1*re2 - im1*im2 , re1*im2 + im1*re2
		return Complex((this->real * right.real) - (this->imaginary * right.imaginary), (this->real * right.imaginary) + (this->imaginary * right.real));
	}
	const Complex operator= (const Complex& right)
	{
		return this->real = right.real, this->imaginary = right.imaginary;
	}
	const bool operator == (const Complex& right)
	{
		bool check = false;
		if (this->real == right.real && this->imaginary == right.imaginary) { check = true; };
		return check;
	}
	const bool operator > (const Complex& right)
	{
		//	bool check = false;
		//	if (this->real > right.real  );
		//	return check;
		double a = sqrt(this->real * this->real + this->imaginary * this->imaginary);
		double b = sqrt(right.real * right.real + right.imaginary * right.imaginary);
		bool check = false;
		if (a > b) { check = true; }
		return check;
	}
	const bool operator < (const Complex& right)
	{
		double a = sqrt(this->real * this->real + this->imaginary * this->imaginary);
		double b = sqrt(right.real * right.real + right.imaginary * right.imaginary);
		bool check = false;
		if (a < b) { check = true; }
		return check;
	}

};

int main(void)
{
	Fraction fr1(1, 2);
	Fraction fr2(2, 2);
	Fraction fr3(0,0);

	fr3 = fr1 + fr2;
	fr3.print();
	fr3 = (0, 0);

	fr3 = fr1 * fr2;
	fr3.print();
	fr3 = (0, 0);

	if (fr1 == fr2) { cout << "true;"<< endl; }
	else { cout << "false" << endl; }
	if (fr1 > fr2) { cout << "true" << endl; }
	else { cout << "false" << endl; }
	if (fr1 < fr2) { cout << "true" << endl; }
	else { cout << "false" << endl; }

	cout << endl << "COMPLEX" << endl;

	Complex co1(1, 2);
	Complex co2(1,1);
	Complex co3(0, 0);

	co3 = co1 + co2;
	co3.print();
	co3 = (0, 0);

	co3 = co1 * co2;
	co3.print();
	co3 = (0, 0);

	if (co1 == co2) { cout << "true" << endl; }
	else { cout << "false" << endl; };

	if (co1 > co2) { cout << "true" << endl; }
	else { cout << "false" << endl; };

	if (co1 < co2) { cout << "true" << endl; }
	else { cout << "false" << endl; };

	return 0;
};

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
