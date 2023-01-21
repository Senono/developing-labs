using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace _1laba {
    public partial class Form1 : Form {
        public Bitmap bmp;
        private readonly Bitmap clearBmp;
        public Color black;

        public List<Point> points = new List<Point>();
        private int countCoords = 0;
        private int cx = 0, cy = 0;

        private bool reDraw = false;

        public Form1() {
            InitializeComponent();
            bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            clearBmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            black = Color.Black;
        }

        private void PutPixel(Bitmap b, Color clr, int x, int y) {
            if (x <= 0 || y <= 0 || x >= pictureBox1.Width || y >= pictureBox1.Height)
                return;
            b.SetPixel(x, y, clr);
        }

        private async void BresenhamLine(Bitmap b, Color clr, int x0, int y0, int x1, int y1, bool beaty = false) {
            int dx = (x1 > x0) ? (x1 - x0) : (x0 - x1);
            int dy = (y1 > y0) ? (y1 - y0) : (y0 - y1);

            int sx = (x1 >= x0) ? (1) : (-1);
            int sy = (y1 >= y0) ? (1) : (-1);

            if (dy < dx) {
                int d = (dy << 1) - dx;
                int d1 = dy << 1;
                int d2 = (dy - dx) << 1;
                PutPixel(b, clr, x0, y0);
                if (beaty) {
                    pictureBox1.Image = (Image)b;
                    await Task.Delay(1);
                }
                int x = x0 + sx;
                int y = y0;
                for (int i = 1; i <= dx; i++) {
                    if (d > 0) {
                        d += d2;
                        y += sy;
                    } else
                        d += d1;
                    PutPixel(b, clr, x, y);
                    if (beaty) {
                        pictureBox1.Image = (Image)b;
                        await Task.Delay(1);
                    }
                    x += sx;
                }
            } else {
                int d = (dx << 1) - dy;
                int d1 = dx << 1;
                int d2 = (dx - dy) << 1;
                PutPixel(b, clr, x0, y0);
                if (beaty) {
                    pictureBox1.Image = (Image)b;
                    await Task.Delay(1);
                }
                int x = x0;
                int y = y0 + sy;
                for (int i = 1; i <= dy; i++) {
                    if (d > 0) {
                        d += d2;
                        x += sx;
                    } else
                        d += d1;
                    PutPixel(b, clr, x, y);
                    if (beaty) {
                        pictureBox1.Image = (Image)b;
                        await Task.Delay(1);
                    }
                    y += sy;
                }
            }
        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e) {
            if (e.Button == MouseButtons.Left) {
                if (reDraw) {
                    Bitmap tmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
                    bmp = tmp;
                    for (int i = 0; i < countCoords - 1; i++) {
                        BresenhamLine(bmp, black, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
                    }
                    reDraw = false;
                }

                points.Add(new Point(e.X, e.Y));
                countCoords++;
                if (countCoords != 1)
                    BresenhamLine(bmp, black, points[countCoords - 2].X, points[countCoords - 2].Y, points[countCoords - 1].X, points[countCoords - 1].Y, true);
            } else if (e.Button == MouseButtons.Right) {
                BresenhamLine(bmp, black, points[countCoords - 1].X, points[countCoords - 1].Y, points[0].X, points[0].Y, true);
                reDraw = true;

                foreach (Point pt in points) {
                    cx += pt.X;
                    cy += pt.Y;
                }
                cx /= countCoords;
                cy /= countCoords;
                PutPixel(bmp, black, cx, cy);
            }
        }

        private void button1_Click(object sender, EventArgs e) {
            /*Form2 frm = new Form2();
            frm.ShowDialog();
            int x2 = frm.x;*/
            int phi = Convert.ToInt32(textBox1.Text);

            List<Point> tmp = new List<Point>(points);
            points.Clear();
            for (int i = 0; i < countCoords; i++) {
                int x = Convert.ToInt32((tmp[i].X - cx) * Math.Cos(phi * 3.14 / 180) - (tmp[i].Y - cy) * Math.Sin(phi * 3.14 / 180)) + cy;
                int y = Convert.ToInt32((tmp[i].X - cx) * Math.Sin(phi * 3.14 / 180) + (tmp[i].Y - cy) * Math.Cos(phi * 3.14 / 180)) + cy;
                points.Add(new Point(x, y));
            }

            Bitmap tmpB = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            bmp = tmpB;
            for (int i = 0; i < countCoords - 1; i++) {
                BresenhamLine(bmp, black, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
            }
            BresenhamLine(bmp, black, points[points.Count - 1].X, points[points.Count - 1].Y, points[0].X, points[0].Y);
            reDraw = true;
            pictureBox1.Image = (Image)bmp;
        }

        private void button5_Click(object sender, EventArgs e) {
            openFileDialog1.ShowDialog();
            points.Clear();
            using (StreamReader sr = new StreamReader(openFileDialog1.FileName)) {
                while (sr.Peek() >= 0) {
                    String[] tmpCoords = sr.ReadLine().Split(',');
                    points.Add(new Point(Convert.ToInt32(tmpCoords[0]), Convert.ToInt32(tmpCoords[1])));
                }

                countCoords = points.Count;
                bmp = clearBmp;
                for (int i = 0; i < countCoords - 1; i++) {
                    BresenhamLine(bmp, black, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
                }
                BresenhamLine(bmp, black, points[points.Count - 1].X, points[points.Count - 1].Y, points[0].X, points[0].Y);
                reDraw = true;
                pictureBox1.Image = (Image)bmp;

                foreach (Point pt in points) {
                    cx += pt.X;
                    cy += pt.Y;
                }
                cx /= countCoords;
                cy /= countCoords;
            }
        }

        private void button3_Click(object sender, EventArgs e) {

        }

        private void button2_Click(object sender, EventArgs e) {
            List<Point> tmp = new List<Point>(points);
            points.Clear();

            for (int i = 0; i < countCoords; i++) {
                points.Add(new Point(tmp[i].X + Convert.ToInt32(textBox2.Text), tmp[i].Y + Convert.ToInt32(textBox3.Text)));
            }

            Bitmap tmpB = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            bmp = tmpB;
            for (int i = 0; i < countCoords - 1; i++) {
                BresenhamLine(bmp, black, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
            }
            BresenhamLine(bmp, black, points[points.Count - 1].X, points[points.Count - 1].Y, points[0].X, points[0].Y);
            reDraw = true;
            pictureBox1.Image = (Image)bmp;
        }

        private void button6_Click(object sender, EventArgs e) {
            saveFileDialog1.ShowDialog();
            using (StreamWriter sw = new StreamWriter(saveFileDialog1.FileName)) {
                for (int i = 0; i < points.Count; i++)
                    sw.WriteLine(points[i].X + "," + points[i].Y);
            }
        }
    }
}
