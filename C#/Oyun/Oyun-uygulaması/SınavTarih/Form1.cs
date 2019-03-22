using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SınavTarih
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)//tarih ve zmanı kontrol etmemizi sağlar
        {
            //maxdath ve min dath ile girilecek tarihleri belirleye biliyoruz
            lsbListe.Items.Add(dtpZaman.Value.ToShortDateString() + "   " + cbbDers.Text);//burdan ister saece zaman istersede sadece tarih yıl gibi seçenekler yapabiliriz
        }
    }
}
