using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sınıf
{
    public partial class Form1 : Form
    {
        raket r = new raket();
        public Form1()
        {
            InitializeComponent();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            panel1.Controls.Add(r);
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            r.hareketet(e.X);

        }
    }
}
