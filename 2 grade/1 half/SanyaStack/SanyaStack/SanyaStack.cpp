#include <iostream>
using namespace std;

class Deliver {
private:
	float weight;
	string name;
	int speed;
	int capacity;
public:
	Deliver(string name, float weight, int speed, int capacity) {
		this->name = name;
		this->weight = weight;
		this->speed = speed;
		this->capacity = capacity;
	}

	~Deliver() {
		cout << "Работает деструктор" << this << endl;
	}

	Deliver(Deliver& d) {
		name = d.name;
		weight = d.weight;
		speed = d.speed;
		capacity = d.capacity;
	}

	virtual void show() {
		cout << "Название компании: " << name << "\nВес пустого транспорта: " << weight << "\nСредняя скорость: " << speed << "\nМаксимальная вместимость: " << capacity << endl;
	}
/////////////////////
	void setName(string n) {
		name = n;
		cout << "Название компании изменено на: " << n << endl;
	}

	void setWeight(float w) {
		weight = w;
		cout << "Вес изменен на: " << w << endl;
	}

	void setSpeed(int s) {
		speed = s;
		cout << "Средняя скорость изменена на: " << s << endl;
	}

};

class Train : public Deliver{
private:	
	string model;
	int vagon;
	string type;
public:
	Train(string n, float w, int s, int c, string m, int v, string t) : Deliver(n, w, s, c)
	{
		this->model = m;
		this->vagon = v;
		this->type = t;

	}
	~Train()
	{
		cout << "Работает деструктор Train" << this << endl;
	}

	void setModel(string m)
	{
		model = m;
		cout << "Название модели изменина на : " << m << endl;
	}

	void setVagon(int v) 
	{
		vagon = v;
		cout << "Количество вагонов изменено : " << v << endl;
	}	

	void show()
	{
		cout << "Данные поезда:\nМодель поезда: " << model << "\nКоличество вагонов: " << vagon << "\nТип поезда: " << type << endl;
	}
};

class Airplane : public Deliver
{
private:
	int wing;
	string type;
	int turbine;
public:
	Airplane(string n, float w, int s, int c, int wng, string t, int tur) : Deliver(n, w, s, c)
	{
		this->wing = wng;
		this->type = t;
		this->turbine = tur;
	}
	~Airplane()
	{
	}

	void setWing(int w)
	{
		wing = w;
		cout << "Количество крыльев измененено : " << w << endl;
	}

	void setTurbine(int t)
	{
		turbine = t;
		cout << "Количество турбин изменено на : " << t << endl;
	}

	void show()
	{
		cout << "Данные самолёта:\nКоличество крыльев: " << wing << "\nТип самолёта: " << type << "\nКоличество турбин: " << turbine << endl;
 	}
};


int main() {
	setlocale(LC_ALL, "");

	Deliver Deliver1("DHL", 100, 100, 1000);
	Deliver1.show();
	Deliver1.setName("HDL");
	Deliver1.show();

	Train Deliver2("KHL", 100000, 60, 100000000000000, "LOL20007", 20, "Товарный");
	Deliver2.show();
	Deliver2.setVagon(25);
	Deliver2.show();

	Airplane Deliver3("AHL", 20000, 300, 10000000, 2, "Пассажирский", 4);
	Deliver3.show();
	Deliver3.setTurbine(6);
	Deliver3.show();
}