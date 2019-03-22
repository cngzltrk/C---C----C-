using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Deneme
{
    public partial class Form1 : Form
    {
        int hız1=2,hız2=2;
        public Form1()
        {
            InitializeComponent();
            btnx.Top = 0;
            btnx.Left = 0;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            btnx.Top += hız1;
            if (btnx.Top > 100)
            {
                
            }
            
        }

        private void btnx_Click(object sender, EventArgs e)
        {
            //timer1.Enabled = false;
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            btnx.Top -= 2;
            if (btnx.Top < 0)
            {
                durdurma(timer2, timer1);
            }

        }
        private void durdurma(Timer t1,Timer t2)
        {
            t1.Enabled = false;
            t2.Enabled = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    

    }
}
