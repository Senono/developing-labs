using System;
using System.Dynamic;

namespace _3l_2CSharp
{
    class Figure
    {
        public int x { get; set; }
        public int y { get; set; }

        public Figure(int X, int Y)
        {
            x = X;
            y = Y;
        }
        public void showCenter()
        {
            Console.WriteLine("Центр фигуры в координатах: " + x + ", " + y);
        }
    }

    class Triangle:Figure
    {
        public int square { get; set; }
        public Triangle(int x, int y, int sq):base(x, y)
        {
            square = sq;
        }
        public void draw()
        {
            showCenter();
            Console.WriteLine("Плошадь треугольника: " + square);
        }
    }

    class Circle:Figure
    {
        public int radius { get; set; }
        public Circle(int x, int y, int r):base(x,y)
        {
            radius = r;
        }
        public void draw()
        {
            showCenter();
            Console.WriteLine("Радиус окружности: " + radius);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Circle circle1 = new Circle(1, 0, 5);
            Triangle triangle1 = new Triangle(3, 2, 20);
            circle1.draw();
            triangle1.draw();
        }
    }
}
