#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Home {
private:
	int rooms;
	double square;
	int floar;
	string district;
public:
	Home(int room, double sq, int fl, string dis): rooms(room), square(sq), floar(fl), district(dis) {}

	double getSquare() {
		return square;
	}
};

class Zayavka {
private:
	Home toHome; // Желаемый дом
	Home fromHome; // Мой дом
public:
	Zayavka(Home home1, Home home2): toHome(home1), fromHome(home2) {}
};

void change(Zayavka zayavka1) {
	for (int i = kartoteka)
}

int main()
{
	setlocale(LC_ALL, "");

	Home home1(2, 50, 1, "Кировский");
	Home home2(3, 70, 2, "Советский");
	Home home3(4, 100, 3, "Красноармейский");

	Zayavka zayavka1(home3, home1);
	Zayavka zayavka2(home1, home3);

	list <Zayavka> kartoteka;
	kartoteka.push_back(zayavka1);
}