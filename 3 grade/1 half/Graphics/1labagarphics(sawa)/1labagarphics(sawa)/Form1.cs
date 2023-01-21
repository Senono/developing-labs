using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1labagarphics_sawa_
{
    public partial class Form1 : Form
    {
        Bitmap bmp;

        static List<List<int>> coords = new List<List<int>>();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            List<int> point = new List<int>();
            switch (e.Button)
            {
                case MouseButtons.Left:
                    point.Add(e.X);
                    point.Add(e.Y);
                    coords.Add(point);

                    bmp.SetPixel(e.X, e.Y, Color.Black);
                    pictureBox1.Image = (Image)(bmp);
                    break;
                case MouseButtons.Right:
                    Random random2 = new Random();
                    for (int i = 0; i < coords.Count; i++)
                        bmp.SetPixel(coords[i][0], coords[i][1], Color.FromArgb(random2.Next(255), random2.Next(255), random2.Next(255)));
                    pictureBox1.Image = (Image)(bmp);
                    break;
            }   
        }

    }
}
