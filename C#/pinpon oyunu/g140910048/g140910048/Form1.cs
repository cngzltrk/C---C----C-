/***************************************************************
**								SAKARYA ÜNİVERSİTESİ
**						BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**							BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**								NESNEYE DAYALI PROGRAMLAMA
**								  2015-2016 BAHAR DÖNEMİ
**
**						ÖDEV NUMARASI........:	PROJE ÖDEV 
**						ÖĞRENCİ ADI..........:	CENGİZ ALTÜRK
**						ÖĞRENCİ NUMARASI.....:	G140910048
**						DERSİN ALINDIĞI GRUP.:  2.ÖĞRETİM C
******************************************************************/





using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace g140910048
{
    public partial class AnaPencere : Form
    {
        //global değişkenler
        raket r;//nesnemize oluşabilmek için akılda kalıcı değişkenne attık
        top t;//nesnemize oluşabilmek için akılda kalıcı değişkenne attık
        skorTahtası st;//nesnemize oluşabilmek için akılda kalıcı değişkenne attık
        int salise = 0, saniye = 0, milisaniye = 0;
        bool kontrol2 = true;

        int genislikpnl;//panelin genişliği
        int yükseklikpnl;//yüksekliğin genişliği
        public AnaPencere()
        {
            InitializeComponent();
            this.FormBorderStyle = FormBorderStyle.SizableToolWindow;//pencere değişikliği
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            olustur();//form yüklendiğinde nesemizi oluşturan fonksiyonu çağırıyoruz
        }
        private void olustur()
        {
            genislikpnl = arkaTahta.Width;//arka tahta oyun panelimizin name
            yükseklikpnl = arkaTahta.Height;//arka tahta oyun panelimizin name
            r = new raket(genislikpnl, yükseklikpnl);//raketimize panelin genişlik ve yüksekliğini gönderip
            t = new top();//top nesnemizi oluşturduk
            arkaTahta.Controls.Add(r);//raketimizi ekrana bastık
            st = new skorTahtası();//skor tahtamızı oluşturk ilk olrak parametresiz group bozımızı aldık
        }
        private void AnaPencere_SizeChanged(object sender, EventArgs e)
        {
            arkaTahta.Controls.Clear();//her boyutun  değişiminde sayfayı temizle
            olustur();//ve oluştur fonksiyonumuzu çağır
        }

        private void arkaTahta_MouseMove(object sender, MouseEventArgs e)
        {
            r.hareketEt(e.X,arkaTahta.Width);//burda raketin konumunu mousa göre ayarlamak için raketin fonksiyonuna yönlendiriyoruz
        }

        private void arkaTahta_MouseClick(object sender, MouseEventArgs e)
        {
            if (kontrol2)//burda eğer oyun başlarsa  mosue gene tklanırsa oyunun dengesini bozmaması için 
            {
                t.konumlama(r.Left, r.Top, r.Width);//burda topun başlangıcını raketin konumuna göre gönderiyoruz
                arkaTahta.Controls.Add(t);//topu panele ekleyip görünmesi için
                zaman.Enabled = true;//zaman sayacımızı başlatıp
                sayac.Enabled = true;//sayacımızı başlat

            }
            
        }

        private void zaman_Tick(object sender, EventArgs e)
        {
            kontrol2 = false;//burda eğer oyun başlarsa mosue tıkladığında oyunu bozmaması için 
            //bu kontrolümüz top oyundamı değilmi yandımı yanmadımı için fonsikyonumuza gerekli olan parametreleri gönderip geri değer dönümünde bool türünde bi değişkene atıyoruz
            bool kontrol=t.hareketEt(r.Top, r.Bottom, r.Left, r.Right, arkaTahta.Top, arkaTahta.Bottom, arkaTahta.Left, arkaTahta.Right);
           //kontrol eğeryanlış  ise
            if (!kontrol)//burayı doğru yapıp iç kısma gir
            {
                zaman.Enabled = false;//zamanı durdurup
                kontrol2 = true;//mousenin tıkladığında yeni oyun başlatması için true yapıyoruz
                sayac.Enabled = false;//sayacımızı false yapıp
                bool kontrol3 =st.skor(saniye, milisaniye) ;//burda eğer yüksek skor yaptımı yapmadımı kontrolü için  fonksiyona yönlenditriyoruz
                if (kontrol3)//eğer true dönerse
                {
                    st = new skorTahtası(saniye, milisaniye);//2. group bozımızı çağırıyoruz parametreli olanı
                    arkaTahta.Controls.Add(st);// sonra ekrana bastırıyruz
                }
                    milisaniye = salise = saniye = 0;//oyun başladığında eski değerleri atanaması için
            }
        }

        private void sktTabela_Click(object sender, EventArgs e)
        {
            //burda yüksek skor yazılı olan butona tıklandığında
            st = new skorTahtası();// parametresiz groupbozımızı oluştur
            arkaTahta.Controls.Add(st);//ekrana yansıt
        }

        private void sayac_Tick(object sender, EventArgs e)
        {
            //labelde sayacın işlenmesi gösrünmesi için 
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
    }
}
