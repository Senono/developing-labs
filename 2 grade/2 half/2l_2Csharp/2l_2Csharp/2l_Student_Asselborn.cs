using System;

namespace _2l_2Csharp
{

    class Student
    {
        public string name;
        public int grade;
        public bool isGrant;

        public Student(string n, int g, bool grant)
        {
            this.name = n;
            this.grade = g;
            this.isGrant = grant;
        }
        public Student(string n, int g)
        {
            this.name = n;
            this.grade = g;
        }
        public Student(string n)
        {
            this.name = n;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Student st1 = new Student("Alex", 2, false);
            Student st2 = new Student("Alexander", 3);
            Student st3 = new Student("Lera");

            Console.WriteLine(st1.name + " " + st1.grade + " курс, стипендия: " + st1.isGrant);
            Console.WriteLine(st2.name + " " + st2.grade + " курс");
            Console.WriteLine(st3.name);
        }
    }
}
