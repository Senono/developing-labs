using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2labagraphics
{
    public partial class Form1 : Form
    {
        Bitmap bmp;
        List<Point> coordinates = new List<Point>();
        bool IsLined = false;

        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
        }

        public static void PutPixel(Bitmap b, Color clr, int x, int y)
        {
            b.SetPixel(x, y, clr);
        }

        public static void AlgorithmBrethenhem(Bitmap b, Color clr, int x0, int y0, int x1, int y1)
        {
            int dx = (x1 > x0) ? (x1 - x0) : (x0 - x1);
            int dy = (y1 > y0) ? (y1 - y0) : (y0 - y1);

            int signX = (x1 > x0) ? 1 : -1;
            int signY = (y1 > y0) ? 1 : -1;

            if (dx > dy)
            {
                int d = (dy << 1) - dx;
                int d1 = dy << 1;
                int d2 = (dy - dx) << 1;
                PutPixel(b, clr, x0, y0);
                int x = x0 + signX;
                int y = y0;
                for (int k = 1; k <= dx; k++)
                {
                    if (d > 0)
                    {
                        d += d2;
                        y += signY;
                    }
                    else
                        d += d1;
                    PutPixel(b, clr, x, y);
                    x += signX;
                }
            }
            else
            {
                int d = (dx << 1) - dy;
                int d1 = dx << 1;
                int d2 = (dx - dy) << 1;
                PutPixel(b, clr, x0, y0);
                int x = x0;
                int y = y0 + signY;
                for (int k = 1; k <= dy; k++)
                {
                    if (d > 0)
                    {
                        d += d2;
                        x += signX;
                    }
                    else
                        d += d1;
                    PutPixel(b, clr, x, y);
                    y += signY;
                }
            }
        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            switch(e.Button)
            {
                case MouseButtons.Left:
                    if (IsLined)
                    {
                        coordinates.Clear();
                        IsLined = false;
                    }
                    Point point = new Point(e.X, e.Y);
                    coordinates.Add(point);
                    bmp.SetPixel(e.X, e.Y, Color.Black);
                    break;
                case MouseButtons.Right:
                    int coordsCount;
                    Color clr = Color.Red;

                    if ((coordsCount = coordinates.Count) > 1)
                    {
                        Bitmap tmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);

                        for (int i = 0; i < coordsCount - 1; i++)
                        {
                            int x0 = coordinates[i].X;
                            int y0 = coordinates[i].Y;
                            int x1 = coordinates[i + 1].X;
                            int y1 = coordinates[i + 1].Y;

                            AlgorithmBrethenhem(tmp, clr, x0, y0, x1, y1);
                            if (i == coordsCount - 2) bmp = tmp;
                            
                        }

                        AlgorithmBrethenhem(bmp, clr, coordinates[0].X, coordinates[0].Y, coordinates[coordsCount - 1].X, coordinates[coordsCount - 1].Y);
                        IsLined = true;
                    }
                    break;
            }

            pictureBox1.Image = (Image)bmp;
        }

        private void Form1_LocationChanged(object sender, EventArgs e)
        {
            bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
        }
    }
}
