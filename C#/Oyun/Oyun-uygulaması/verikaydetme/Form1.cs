using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;//dosyalam işlemi için gerekli uzay
namespace verikaydetme
{
    public partial class Form1 : Form
    {
        private void DosyayaYaz()
        {
           
        }

        

        
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                StreamReader Dosya = File.OpenText(@"C:\Users\sadık\Desktop\Ders notları\c# notları\Oyun\Oyun-uygulaması\verikaydetme\dosya.txt");//Dosyayı açmaya çalış olmaz ise catch bloğuan geç
                Dosya.Close();
            }
            catch
            {

                StreamWriter Dosya = File.CreateText(@"C:\Users\sadık\Desktop\Ders notları\c# notları\Oyun\Oyun-uygulaması\verikaydetme\dosya.txt");// yeni dosya oluştur.
                Dosya.Close();
            }
            StreamWriter dosya = File.AppendText(@"C:\Users\sadık\Desktop\Ders notları\c# notları\Oyun\Oyun-uygulaması\verikaydetme\dosya.txt");//Dosyayı appendText ile yazmak için açtık
            dosya.WriteLine(ad.Text); // Dosya.WriteLine ile dosyaya isim ve soyisim text kutularındaki değerleri aralrına bir tab boşluk bırakarak ekledik.
            dosya.Close(); // Dosya yı kapattık.

           
        }

        private void button3_Click(object sender, EventArgs e)
        {
            kutu.Visible = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            kutu.Visible = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            kutu.Visible = false;

        }

        private void button2_Click(object sender, EventArgs e)
        {
            StreamReader dosya = File.OpenText(@"C:\Users\sadık\Desktop\Ders notları\c# notları\Oyun\Oyun-uygulaması\verikaydetme\dosya.txt");//Stream Reader ile Dosyayı okuyoruz.
            string s = dosya.ReadLine();//ilk satırı okuyoruz.
            while (s != null)//s boş olmadığı sürece satırı okutup bir alt satıra geçiyoruz.
            {
                lstListem.Items.Add(s);//Listbhox a okunan satırı ekletiyoruz.
                s = dosya.ReadLine(); // ve satırı okutup tekrar bir alt satıra geçiyoruz.
            }
            dosya.Close();//Dosyayı kapatıyoruz.
        }
        
    }
}
