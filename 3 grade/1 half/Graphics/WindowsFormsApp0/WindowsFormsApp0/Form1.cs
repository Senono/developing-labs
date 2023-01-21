using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp0
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void PictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            Bitmap bm = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            bm.SetPixel(e.X, e.Y, Color.FromArgb(256,0,0, 0));
            pictureBox1.Image = bm;
            Debug.WriteLine("test");
            //Invalidate(new Rectangle(0, 0, pictureBox1.Width, pictureBox1.Height));
            pictureBox1.Refresh();
        }
    }
}
