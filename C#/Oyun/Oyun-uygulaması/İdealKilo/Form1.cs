using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace İdealKilo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double  idealKilo, boy, yas, k,yil,kilo;
            DateTime dt=DateTime.Today;//günün tarihini atıp
            yil=dt.Year;//burdada yılı atıyoruz
            kilo=Convert.ToDouble(textBox3.Text);//dönüşüm
            if(comboBox1.Text=="Kadın")//seçenek 
            {
                k = 0.8;
                boy=Convert.ToDouble(textBox1.Text);
                yas=Convert.ToDouble(textBox2.Text);
                idealKilo = (boy - 100 + (yil - yas) / 10) * k;
                label7.Text = Convert.ToString(idealKilo);
                if(kilo<idealKilo)//kilo idealdan küçükse koşlularımız
                {
                    label6.Text = "Kilo al..";
                }
                else if(kilo>idealKilo)
                    label6.Text = "Kilo ver..";
                else
                    label6.Text = "süper kilon..";
            }
            else if (comboBox1.Text == "Erkek")//erkek seçenekleri
            {
                k = 0.9;
                boy = Convert.ToDouble(textBox1.Text);
                yas = Convert.ToDouble(textBox2.Text);
                idealKilo = (boy - 100 + (yil - yas) / 10) * k;
                if (kilo < idealKilo)
                {
                    label6.Text = "Kilo al..";
                }
                else if (kilo > idealKilo)
                    label6.Text = "Kilo ver..";
                else
                    label6.Text = "süper kilon..";
            }
            else//seçenek seçilmezse diye koşulumuz
            {
                label6.Text = "Cinsiyet seç..";
            }
        }
    }
}
