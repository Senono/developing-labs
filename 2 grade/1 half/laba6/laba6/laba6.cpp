#include <iostream>
#include <string>
using namespace std;

class Learner {
private:
	string firstName;
	string lastName;
	int age;
	string gender;
public:
	Learner(string fName, string lName, int a, string gen) { // Конструктор
		firstName = fName;
		lastName = lName;
		age = a;
		gender = gen;
		show();
	}

	// Конструктор копирования
	Learner(Learner &l) { 
		firstName = l.firstName;
		lastName = l.lastName;
		age = l.age;
		gender = l.gender;
	}

	virtual void show() {
		cout << "\nДанные учащегося:\nName: " << firstName << " " << lastName << endl << "Age: " << age << endl << "Gender: " << gender << endl;
	}

	void setFirstName(string name) {
		firstName = name;
		cout << "Имя изменено на " << firstName << endl;
	}
	void setLastName(string name) {
		lastName = name;
		cout << "Фамилия изменена на " << lastName << endl;
	}

	void setAge(int a) {
		age = a;
		cout << "Возраст учащегося изменен на: " << age << endl;
	}
};

class Schoolboy : public Learner {
private:
	int grade;
	float averageRating;
	int schoolNum;
public:
	Schoolboy(string fName, string lName, int a, string gen, int gr, float rate, int SchNum) : Learner(fName, lName, a, gen) {
		grade = gr;
		averageRating = rate;
		schoolNum = SchNum;
		show();
	}

	void show() {
		cout << "Дополнительные данные школьника:\nGrade: " << grade << endl << "Average Rating: " << averageRating << endl << "Number of School: " << schoolNum << endl;
	}

	void setGrade(int gr) {
		grade = gr;
		cout << "Класс изменен на " << grade << " класс" << endl;
	}

	void setSchoolNum(int SchNum) {
		schoolNum = SchNum;
		cout << "Номер школы изменён на " << schoolNum << endl;
	}
};

class Student : public Learner {
private:
	int id;
	int grade;
	string university;
public:
	Student(string fName, string lName, int a, string gen, int idN, int gr, string Univer) : Learner(fName, lName, a, gen) {
		id = idN;
		grade = gr;
		university = Univer;
		show();
	}

	void show() {
		cout << "Дополнительный данные студента:\nGrade: " << grade << endl << "Id: " << id << endl << "University: " << university << endl;
	}

	void setUniversity(string univer) {
		university = univer;
		cout << "УНиверститет студента изменен на: " << university << endl;
	}

	void setGrade(int gr) {
		grade = gr;
		cout << "Номер курса студента изменен на: " << grade << endl;
	}

};

int main()
{
	setlocale(LC_ALL, "");
	Learner Learner1("Alex", "Asselborn", 19, "male");
	Schoolboy Schoolboy1("Alex", "Asselborn", 19, "male", 11, 4.5, 117);
	Student Student1("Alex", "Asselborn", 19, "male", 400029, 2, "Volsu");

	Learner1.setAge(25);
	Learner1.show();
	Schoolboy1.setGrade(10);
	Schoolboy1.show();
	Student1.setAge(30);
	Student1.show();

}
	