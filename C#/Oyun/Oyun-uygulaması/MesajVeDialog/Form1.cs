using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MesajVeDialog
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //bu uyarı verir
            MessageBox.Show("Bilgi","Başlık",MessageBoxButtons.OKCancel,MessageBoxIcon.Question);//ilki orta 2 başlık 3 ise evet hayır 4 ise ünlem logo 
        }
    }
}
