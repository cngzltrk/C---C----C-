using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ort_hesap
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnSon_Click(object sender, EventArgs e)
        {
            this.Close();//kapatma
        }

        private void txtSayi_TextChanged(object sender, EventArgs e)
        {
            
            
        }

        private void txtSayi_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar >= (char)48 && e.KeyChar <= (char)57)||e.KeyChar==(char)8)//8 back space diğerleri 0 - 9 arası
            {
                e.Handled = false;//yazdırır
            }
            else if (e.KeyChar == (char)13)
            {
                lsbSayilar.Items.Add(txtSayi.Text);//ekleme
                txtSayi.Text = "";//texti boşaltma
                txtSayi.Focus();//odaklanma
                e.Handled = false;//yazdırma
            }
            else
                e.Handled = true;//yazdırmaz
        }

        private void btnHesap_Click(object sender, EventArgs e)
        {
            double ort=0,sap=0;
            for(int i=0;i<lsbSayilar.Items.Count;i++)//burda girilen liste boxımızı kontrol ediyoruz sayısını alıp döngüye sokuyoruz
            {
                ort += Convert.ToDouble(lsbSayilar.Items[i]);//dönüştürüp ortlamaya atıyoruz
            }
            ort = ort / lsbSayilar.Items.Count;//top sayıyı ortalamaya bölüyoruz
            lblOrtalama.Text = ort.ToString();//burada toString(); bize sayıyı stringe çevirip oraya bırakıyor
            //standart sapma
            
            for (int i = 0; i < lsbSayilar.Items.Count; i++)
            {
                sap += Math.Pow  ((Convert.ToDouble(lsbSayilar.Items[i]) - ort),2);//üstünü alıyoruz
            }
            sap = Math.Sqrt(sap / lsbSayilar.Items.Count);//karesini alıyoruz
            lblSapma.Text = sap.ToString();//dönüştürüp yazıdrma
        }

        private void btnTemizle_Click(object sender, EventArgs e)
        {

            lsbSayilar.Items.Clear();//listeyi temizleme

        }
    }
}
