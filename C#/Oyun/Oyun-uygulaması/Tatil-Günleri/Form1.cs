using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tatil_Günleri
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnSon_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cbbResmi.Items.Add("Yılbaşı");//burda form yüklendiğinde combobox a ekleme yapıyoruz
        }

        private void btnEkle_Click(object sender, EventArgs e)
        {
            lsbTatil.Items.Add(cbbResmi.Text + "    " +//combocox yazdırma
                mtcGun.SelectionStart.ToShortDateString() + "    "//burda başlangıcı girp
                + mtcGun.SelectionEnd.ToShortDateString());//burdada bitişi girip tarihleri yazdırıyoruz

        }

        private void btnCık_Click(object sender, EventArgs e)
        {
            lsbTatil.Items.Remove(lsbTatil.SelectedItem);//burda da silme işlemi yapmaktayız
        }
    }
}
