using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;
using System.Diagnostics;

namespace _3_laba
{
    public partial class Form1 : Form
    {
        int test = 0;

        public Bitmap bmp;
        public Color red, black;

        public List<Point> points = new List<Point>();
        public int coords = 1;
        public Point start = new Point(), end = new Point(), realStart = new Point();

        public bool isLined = false;

        private readonly int left = 1;
        private readonly int right = 2;
        private readonly int bottom = 4;
        private readonly int top = 8;

        public Form1()
        {
            InitializeComponent();
            bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            red = Color.Red;
            black = Color.Black;
        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                textBox1.Text = "Coords of rect: " + start.ToString() + end.ToString();
                for (int i = 1; i < coords; i++)
                {
                    CohenSutherland(points[i - 1].X, points[i - 1].Y, points[i].X, points[i].Y, start, end, bmp, Color.Blue);
                }

                pictureBox1.Image = (Image)bmp;
            }
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left) {
                points.Add(new Point(e.X, e.Y));
                if (!isLined)
                    isLined = true;
                else {
                    Bresenham4Line(bmp, red, points[coords - 1].X, points[coords - 1].Y, points[coords].X, points[coords].Y, true);
                    coords++;
                }

                pictureBox1.Image = (Image)bmp;
            }
            realStart.X = e.X;
            realStart.Y = e.Y;
            start.X = e.X;
            start.Y = e.Y;
            end.X = e.X;
            end.Y = e.Y;
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (MouseButtons == MouseButtons.Right)
            {
                Bitmap clear = new Bitmap(pictureBox1.Width, pictureBox1.Height);
                bmp = clear;

                if (e.X < realStart.X & e.Y > realStart.Y) // 3
               {
                    end.X = realStart.X;
                    end.Y = e.Y;
                    start.X = e.X;
                } else if (e.X > realStart.X & e.Y > realStart.Y) // 4
                  {
                    end.X = e.X;
                    end.Y = e.Y;
                } else if ((e.X - realStart.X) > 0 & (e.Y - realStart.Y) < 0) // 1
                  {
                    end.X = e.X;
                    end.Y = realStart.Y;
                    start.Y = e.Y;
                    start.X = realStart.X;
                } else if (e.X != realStart.X & e.Y != realStart.Y) // 2
                  {
                    end.X = realStart.X;
                    end.Y = realStart.Y;
                    start.X = e.X;
                    start.Y = e.Y;
                }

                for (int i = 1; i < coords; i++)
                    Bresenham4Line(bmp, red, points[i - 1].X, points[i - 1].Y, points[i].X, points[i].Y);
                DrawRectangle(bmp, black, start, end);

                pictureBox1.Image = (Image)bmp;
            }
        }

        private void PutPixel(Bitmap b, Color clr, int x, int y)
        {
            b.SetPixel(x, y, clr);
        }

        private async void Bresenham4Line(Bitmap b, Color clr, int x0, int y0, int x1, int y1, bool beaty = false)
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
                PutPixel(b, clr, x0, y0);
                if (beaty)
                {
                    pictureBox1.Image = (Image)b;
                    await Task.Delay(1);
                }
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
                    PutPixel(b, clr, x, y);
                    if (beaty)
                    {
                        pictureBox1.Image = (Image)b;
                        await Task.Delay(1);
                    }
                    x += sx;
                }
            }
            else
            {
                int d = (dx << 1) - dy;
                int d1 = dx << 1;
                int d2 = (dx - dy) << 1;
                PutPixel(b, clr, x0, y0);
                if (beaty)
                {
                    pictureBox1.Image = (Image)b;
                    await Task.Delay(1);
                }
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
                    PutPixel(b, clr, x, y);
                    if (beaty)
                    {
                        pictureBox1.Image = (Image)b;
                        await Task.Delay(1);
                    }
                    y += sy;
                }
            }
        }

        private void DrawRectangle(Bitmap b, Color clr, Point start, Point end)
        {
            Bresenham4Line(b, clr, start.X, start.Y, end.X, start.Y);
            Bresenham4Line(b, clr, end.X, start.Y, end.X, end.Y);
            Bresenham4Line(b, clr, end.X, end.Y, start.X, end.Y);
            Bresenham4Line(b, clr, start.X, end.Y, start.X, start.Y);
        }

        private int Code(int x, int y, Point startR, Point endR)
        {
            int c = 0;
            if (x < startR.X) c |= left;
            if (x > endR.X) c |= right;
            if (y > endR.Y) c |= bottom;
            if (y < startR.Y) c |= top;
            return c;
        }

        private void CohenSutherland(int x0, int y0, int x1, int y1, Point startR, Point endR, Bitmap b, Color clr)
        {
            int c1 = Code(x0, y0, startR, endR);
            int c2 = Code(x1, y1, startR, endR);
            textBox1.Text += "Code1 start: " + c1 + " Code 2 start: " + c2 + "\n";
            int c;
            int x = 0, y = 0;

            while (c1 != 0 || c2 != 0) {
                if ((c1 & c2) != 0) {
                    x0 = 0;
                    y0 = 0;
                    x1 = 0;
                    y1 = 0;
                    break;
                }

                c = c1;
                if (c1 == 0)
                    c = c2;
                textBox1.Text += " Code1: " + c1 + " Code 2: " + c2;

                if ((c & left) != 0) { // точка слева
                    x = startR.X;
                    y = y0 + (int)(Convert.ToDouble(y1 - y0) / (x1 - x0) * (startR.X - x0));
                } else if ((c & right) != 0) {
                    x = endR.X;
                    y = y0 + (int)(Convert.ToDouble(y1 - y0) / (x1 - x0) * (endR.X - x0));
                } else if ((c & top) != 0) {
                    y = startR.Y;
                    x = x0 + (int)(Convert.ToDouble(x1 - x0) / (y1 - y0) * (startR.Y - y0));
                } else if ((c & bottom) != 0) {
                    y = endR.Y;
                    x = x0 + (int)(Convert.ToDouble(x1 - x0) / (y1 - y0) * (endR.Y - y0));
                }

                if (c == c1) {
                    x0 = x;
                    y0 = y;
                    c1 = Code(x0, y0, startR, endR);
                } else {
                    x1 = x;
                    y1 = y;
                    c2 = Code(x1, y1, startR, endR);
                }
            }
            Bresenham4Line(b, clr, x0, y0, x1, y1);
        }
    }
}
