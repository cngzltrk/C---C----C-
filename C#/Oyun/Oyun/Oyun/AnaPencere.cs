using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Media;
using System.IO;
namespace Oyun
{
    public partial class AnaPencere : Form
    {
        SoundPlayer oyunsonuSes = new SoundPlayer();
        SoundPlayer carpses = new SoundPlayer();    
        int hız_gen = 2, hız_top = -2,mouseX,salise=0,saniye=0,milisaniye=0;
        
        public AnaPencere()
        {
            InitializeComponent();
            this.FormBorderStyle = FormBorderStyle.SizableToolWindow;
            raket.Top = arkaTahta.Bottom - (arkaTahta.Bottom / 15); 
            
        }


        private void AnaPencere_Load(object sender, EventArgs e)
        {
            
            raket.Visible = false;
            top.Visible = false;
            grbSkor.Visible = false;
            skorTahta.Visible = false;

            
        }

        private void arkaTahta_MouseClick(object sender, MouseEventArgs e)
        {
            ustTahta.Visible = false;
            raket.Visible = true;
            top.Visible = true;
            zaman.Enabled = true;
            sayac.Enabled = true;
            top.Left = raket.Left + 50;
            top.Top = raket.Top -20;
            Cursor.Hide();
            milisaniye = salise = saniye = 0;
        }

        private void zaman_Tick(object sender, EventArgs e)
        {
           oyunsonuSes.SoundLocation = "C:\\Users\\sadık\\Desktop\\Ders notları\\c# notları\\Oyun\\Oyun\\ses\\button-4.wav";

           carpses.SoundLocation = "C:\\Users\\sadık\\Desktop\\Ders notları\\c# notları\\Oyun\\Oyun\\ses\\button-16.wav";
            
            top.Left += hız_gen;
            top.Top += hız_top;
            if (top.Top >= raket.Top && top.Bottom <= raket.Bottom && top.Left >= raket.Left && top.Right <= raket.Right)
            {
                hız_top += 1;
                hız_gen += 1;
                hız_top = -hız_top;
                carpses.Play();
            }
            if (top.Left <= arkaTahta.Left)
            {
                hız_gen = -hız_gen;
                carpses.Play();
            }
            if (top.Right >= arkaTahta.Right)
            {
                hız_gen = -hız_gen;
                carpses.Play();
            }
            if (top.Top <= arkaTahta.Top)
            {
                hız_top = -hız_top;
                carpses.Play();
            }
            if (top.Bottom >= arkaTahta.Bottom)
            {
                oyunsonuSes.Play();
                zaman.Enabled = false;
                sayac.Enabled = false;
                ustTahta.Visible = true;
                top.Visible = false;
                Cursor.Show();
               // MessageBox.Show(saniye.ToString() + ":" + milisaniye.ToString());

                grbSkor.Visible = true;


                
                hız_gen = 2;
                hız_top = -2;

                {//
                    grbSkor.Visible = true;



                }//
            }

        }

        private void arkaTahta_MouseMove(object sender, MouseEventArgs e)
        {
            mouseX = e.X;
            mouseX -= raket.Width / 2;
            if (mouseX <= 5)
            {
                mouseX = 5;
            }
            if (mouseX >=690)
                mouseX =690 ;
            raket.Left = mouseX;
        }

        private void sayac_Tick(object sender, EventArgs e)
        {
            milisaniye++;
            if (milisaniye % 10 == 0)
            {
                salise++;
                lblzaman.Text = saniye.ToString() + ":" + salise.ToString();
            }
            if (milisaniye % 100 == 0)
            {
                saniye++;
                lblzaman.Text = saniye.ToString() + ":" + salise.ToString();

            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void arkaTahta_Paint(object sender, PaintEventArgs e)
        {

        }

        private void tamam_Click(object sender, EventArgs e)
        {
            try
            {
                StreamReader Dosya = File.OpenText(@"C:\Users\sadık\Desktop\Ders notları\c# notları\Oyun\Oyun\dosya.txt");//Dosyayı açmaya çalış olmaz ise catch bloğuan geç
                Dosya.Close();
            }
            catch
            {

                StreamWriter Dosya = File.CreateText(@"C:\Users\sadık\Desktop\Ders notları\c# notları\Oyun\Oyun\dosya.txt");// yeni dosya oluştur.
                Dosya.Close();
            }
            StreamWriter dosya = File.AppendText(@"C:\Users\sadık\Desktop\Ders notları\c# notları\Oyun\Oyun\dosya.txt");//Dosyayı appendText ile yazmak için açtık
            dosya.WriteLine(ad.Text +"  " + saniye.ToString() + ":" + milisaniye.ToString()); // Dosya.WriteLine ile dosyaya isim ve soyisim text kutularındaki değerleri aralrına bir tab boşluk bırakarak ekledik.
            dosya.Close(); // Dosya yı kapattık.
            grbSkor.Visible = false;
        }

        private void vazgec_Click(object sender, EventArgs e)
        {
            grbSkor.Visible = false;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btntamam_Click(object sender, EventArgs e)
        {
            skorTahta.Visible = false;
        }

        private void skor_Click(object sender, EventArgs e)
        {
            skorTahta.Visible = true;
            lstListem.Items.Clear();
            StreamReader dosya = File.OpenText(@"C:\Users\sadık\Desktop\Ders notları\c# notları\Oyun\Oyun\dosya.txt");//Stream Reader ile Dosyayı okuyoruz.
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
