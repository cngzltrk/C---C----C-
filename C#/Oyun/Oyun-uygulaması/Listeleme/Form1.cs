using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Listeleme
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnSon_Click(object sender, EventArgs e)
        {
            this.Close();//kapatma işlemi yapan kod
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnListele_Click(object sender, EventArgs e)
        {
            for(int i=0;i<lsbSecenek.Items.Count;i++)//listboxın sayısı kadar döngüye girer
            {
                if(lsbSecenek.GetItemChecked(i)==true)//burdaki kodumuz bize oraya değer döndürür ve eğer tikli ise içeri girer
                {
                    lsbSiparis.Items.Add(lsbSecenek.Items[i]);//list boxımıza yazdırma işlemi yapıyoruz
                }
            }
        }
    }
}
