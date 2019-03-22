using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DaireAlan
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {
            
        }

        private void btnHesap_Click(object sender, EventArgs e)
        {
            double cap, alan, cevre;
            cap = Convert.ToDouble(txtYarıcap.Text);//dönüşüm
            cevre = 2 * 3.14 * cap;
            alan = 3.14 * cap * cap;
            lblalan.Text = Convert.ToString(alan);//lbllere yazdırma işlemleri
            lblcevre.Text = Convert.ToString(cevre);//lblelere yazdırma işlemleri
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();//burada basıldığında kapatılması için
        }
    }
}
