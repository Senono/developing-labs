using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace _2RealLaba
{
    public partial class Form1 : Form
    {
        private Bitmap bmp;
        private Point start;
        private Point end;
        private Point realStart;

        public Color color;
        public Color colorEllipse;

        public Form1()
        {
            InitializeComponent();
            color = Color.Black;
            colorEllipse = Color.Red;
        }

        public void PutPixel(Bitmap b, int x, int y, Color clr)
        {
            if (x > 0 && x < pictureBox1.Width && y > 0 && y < pictureBox1.Height)
                b.SetPixel(x, y, clr);
        }

        public void Bresenham4Line(Bitmap b, Color clr, int x0, int y0, int x1, int y1)
        {
            int dx = (x1 > x0) ? (x1 - x0) : (x0 - x1); 
            int dy = (y1 > y0) ? (y1 - y0) : (y0 - y1);
            
            int sx = (x1 >= x0) ? (1) : (-1);
            int sy = (y1 >= y0) ? (1) : (-1);

            if (dy < dx) 
            {
                int d = (dy << 1) - dx;
                int d1 = dy << 1;
                int d2 = (dy - dx) << 1;
                PutPixel(b, x0, y0, clr);
                int x = x0 + sx;
                int y = y0;
                for (int i = 1; i <= dx; i++)
                {
                    if (d > 0)
                    {
                        d += d2;
                        y += sy;
                    }
                    else
                        d += d1;
                    PutPixel(b, x, y, clr);
                    x += sx;
                }
            }
            else
            {
                int d = (dx << 1) - dy;
                int d1 = dx << 1;
                int d2 = (dx - dy) << 1;
                PutPixel(b, x0, y0, clr);
                int x = x0;
                int y = y0 + sy;
                for (int i = 1; i <= dy; i++)
                {
                    if (d > 0)
                    {
                        d += d2;
                        x += sx;
                    }
                    else 
                        d += d1;
                    PutPixel(b, x, y, clr);
                    y += sy;
                }
            }
        }

        private void DrawRectangle(Point point1, Point point2, Bitmap b, Color clr) //рисовать прямоугольник
        {
            Bresenham4Line(b, clr, point1.X, point1.Y, point2.X, point1.Y);
            Bresenham4Line(b, clr, point1.X, point2.Y, point2.X, point2.Y);
            Bresenham4Line(b, clr, point1.X, point1.Y, point1.X, point2.Y);    
            Bresenham4Line(b, clr, point2.X, point1.Y, point2.X, point2.Y);
        }

        public void Pixel4(Bitmap b, int x, int y, int _x, int _y, Color clr)
        {
            PutPixel(b, x + _x, y + _y, clr);
            PutPixel(b, x + _x, y - _y, clr);
            PutPixel(b, x - _x, y + _y, clr);
            PutPixel(b, x - _x, y - _y, clr);   
        }

       void DrawElipse(Bitmap bmp, int x, int y, int a, int b, Color clr)
       {
            int _x = 0; 
            int _y = b; 
            int a_sqr = a * a; 
            int b_sqr = b * b; 
            int delta = 4 * b_sqr * ((_x + 1) * (_x + 1)) + a_sqr * ((2 * _y - 1) * (2 * _y - 1)) - 4 * a_sqr * b_sqr; // Функция координат точки (x+1, y-1/2)
            while (a_sqr * (2 * _y - 1) > 2 * b_sqr * (_x + 1)) // Первая часть дуги
            {
                Pixel4(bmp, x, y, _x, _y, clr);
                if (delta < 0) // Переход по горизонтали
                {
                    _x++;
                    delta += 4 * b_sqr * (2 * _x + 3);
                }
                else // Переход по диагонали
                {
                    _x++;
                    delta = delta - 8 * a_sqr * (_y - 1) + 4 * b_sqr * (2 * _x + 3);
                    _y--;
                }
            }
            delta = b_sqr * ((2 * _x + 1) * (2 * _x + 1)) + 4 * a_sqr * ((_y + 1) * (_y + 1)) - 4 * a_sqr * b_sqr; // Функция координат точки (x+1/2, y-1)
            while (_y + 1 != 0) // Вторая часть дуги, если не выполняется условие первого цикла, значит выполняется a^2(2y - 1) <= 2b^2(x + 1)
            {
                Pixel4(bmp, x, y, _x, _y, clr);
                if (delta < 0) // Переход по вертикали
                {
                    _y--;
                    delta += 4 * a_sqr * (2 * _y + 3);
                }
                else // Переход по диагонали
                {
                    _y--;
                    delta = delta - 8 * b_sqr * (_x + 1) + 4 * a_sqr * (2 * _y + 3);
                    _x++;
                }
            }
       }

        private void Form1_Load(object sender, EventArgs e)
        {
            bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if ((e.Button & MouseButtons.Left) == MouseButtons.Left)
            {
                if (e.X < realStart.X & e.Y > realStart.Y) // 3
                {
                    end.X = realStart.X;
                    end.Y = e.Y;
                    start.X = e.X;
                }
                else if (e.X > realStart.X & e.Y > realStart.Y) // 4
                {
                    end.X = e.X;
                    end.Y = e.Y;
                }
                else if ((e.X - realStart.X) > 0 & (e.Y - realStart.Y) < 0) // 1
                {
                    end.X = e.X;
                    end.Y = realStart.Y;
                    start.Y = e.Y;
                    start.X = realStart.X;
                }
                else if (e.X != realStart.X & e.Y != realStart.Y) // 2
                {
                    end.X = realStart.X;
                    end.Y = realStart.Y;
                    start.X = e.X;
                    start.Y = e.Y;
                }

                bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
                DrawRectangle(start, end, bmp, color);
                int cx = Convert.ToInt32(Math.Abs((end.X + start.X) / 2));//абсцисса центра 
                int cy = Convert.ToInt32(Math.Abs((end.Y + start.Y) / 2));//ордината центра
                Point circleCenter = new Point(cx, cy);//сохраняем центр
                int circleLenghtY = Convert.ToInt32(Math.Abs((end.Y - start.Y) / 2));//длина элипса по оси ординат
                int circleLenghtX = Convert.ToInt32(Math.Abs((end.X - start.X) / 2));//длина элипса по оси абсцисс
                DrawElipse(bmp, circleCenter.X, circleCenter.Y, circleLenghtX, circleLenghtY, colorEllipse);//рисуем элипс
                pictureBox1.Image = (Image)bmp;

/*                textBox1.Text += "Start1: " + start.ToString()
                  + " End: " + end.ToString() + "eX: " + e.X + " eY: " + e.Y + "\r\n";*/
            }
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            textBox1.Text = "";
            realStart.X = e.X;
            realStart.Y = e.Y;
            start.X = e.X;
            start.Y = e.Y;
            end.X = e.X;
            end.Y = e.Y;

            textBox1.Text += "Start1: " + start.ToString()
                  + " End: " + end.ToString() + "eX: " + e.X + " eY: " + e.Y + "\r\n";
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
        }
    }
}
