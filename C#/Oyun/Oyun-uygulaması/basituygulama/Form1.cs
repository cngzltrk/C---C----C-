using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace basituygulama
{
    public partial class Form1 : Form
    {
        //referans oluşturma burda aptık çünkü global olması için
        Button btnHesapla;
        Button btnSon;
        Label lblA;
        Label lblb;
        Label lbls;
        Label lblt;
        TextBox txtA;
        TextBox txtB;


        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //nesne atama
            btnHesapla = new Button();
            btnSon = new Button();
            lblA = new Label();
            lblb = new Label();
            lbls = new Label();
            lblt = new Label();
            txtA = new TextBox();
            txtB= new TextBox();
            //ekleme
            Controls.Add(btnHesapla);
            Controls.Add(btnSon);
            Controls.Add(lblA);
            Controls.Add(lblb);
            Controls.Add(lbls);
            Controls.Add(lblt);
            Controls.Add(txtA);
            Controls.Add(txtB);
            //özellik atama
            lblA.Text = "A Sayısı ..:";
            lblb.Text = "b Sayısı ..:";
            lblt.Text = "toplam ..:";
            lbls.Text = "";
            lblA.Left = 40;
            lblb.Left = 40;
            lblt.Left = 40;
            lblA.Top=50;
            lblb.Top=100;
            lblt.Top=150;
            lbls.Left = 90;
            lbls.Top = 150;
            txtA.Left = 150;
            txtA.Top = 50;
            txtB.Left = 150;
            txtB.Top = 100;
            btnHesapla.Left = 40;
            btnHesapla.Top = 200;
            btnSon.Left = 150;
            btnSon.Top = 200;
            btnSon.Text = "Son";
            btnHesapla.Text = "Hesapla";
            //burda olay atama
            btnSon.Click += btnSon_Click;
            btnHesapla.Click += btnHesapla_Click;



        }
        //fonksiyonumuz
        void btnHesapla_Click(object sender, EventArgs e)
        {
            lbls.Text = Convert.ToString(Convert.ToInt32(txtA.Text) + Convert.ToInt32(txtB.Text));
        }

        void btnSon_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
