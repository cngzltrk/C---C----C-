using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace denemeOyun
{
    public partial class Form1 : Form
    {
        int hız_sol = 2;
        int hız_top = 2;
        public Form1()
        {
            InitializeComponent();
            timer1.Enabled = true;
           // Cursor.Hide();
           // this.FormBorderStyle = FormBorderStyle.SizableToolWindow;
            raket.Top = arkaTahta.Bottom - (arkaTahta.Bottom / 15);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            raket.Left = Cursor.Position.X - (raket.Width / 2);
            top.Left += hız_sol;
            top.Top += hız_top;
            if (top.Bottom >= raket.Top && top.Bottom <= raket.Bottom && top.Left >= raket.Left && top.Right <= raket.Right) 
            {
                hız_top += 2;
                hız_sol += 2;
                hız_top = -hız_top;     
            }
            if (top.Left<=arkaTahta.Left)
            {
                hız_sol = -hız_sol;
            }
            if (top.Right>=arkaTahta.Right)
            {
                hız_sol = -hız_sol;
            }
            if (top.Top<=arkaTahta.Top)
            {
                hız_top = -hız_top;
            }
            if (top.Bottom>=arkaTahta.Bottom)
            {
                timer1.Enabled = false;
            }
        }

        private void arkaTahta_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
