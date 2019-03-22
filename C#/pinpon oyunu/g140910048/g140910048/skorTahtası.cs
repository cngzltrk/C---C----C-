using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.IO;

namespace g140910048
{
    class skorTahtası:GroupBox//group boz tan aldık
    {
        int saniye, milisaniye;//bunlar skorları elde tutup kayıda eklememmiziçin
        static int sıra;//buda sadece 5 tane kayıt sağlaması için static değişkenimiz
        Button tamam= new Button();//tamam butumuz skor listesi çıktığında tamama basarak gizlemek için
        ListBox liste = new ListBox();//skorlarımızı liste box ta yazdırıyoruz
        TextBox ad = new TextBox();//buda yüksek kor yaptığında adınız almamız için
        public skorTahtası()//bu skor listesi groub bozını gösterir
        {
            this.Visible = true;//görünür kılıp
            this.Width = 380;//özelliklerini tanımlayıp
            this.Height = 280;
            this.Text = "Yüksek Skor";
            this.BackColor = Color.YellowGreen;
            this.SetBounds(200, 100, this.Width, this.Height);
            this.Font = new Font("OCR A Extended", 15, FontStyle.Bold);
            buton();//buton fonksiyonumuzu çağrıp
            tamam.Click += tamam_Click;//eğer tamama basılırsa fonksiyonumuza yönlendiriyoruz
            lstbox();//buda skorların listede görünmesi için fonksiyona gönderiyoruz


        }
        public skorTahtası(int s,int msn)//2. group bozımız skoru ismini alıp kayıt yapması için
        {
            //değişkenlere atayıp
            saniye = s;//saniye ve mili saniyeyi
            milisaniye = msn;
            //görünür kılıp özelliklerini atayıp
            this.Visible = true;
            this.Width = 320;
            this.Height = 200;
            this.Text = "Yüksek Skor";
            this.BackColor = Color.Yellow;
            this.SetBounds(300, 100, this.Width, this.Height);
            this.Font = new Font("OCR A Extended", 15, FontStyle.Bold);
            //label
            Label lblYazi = new Label();
            Label lblad = new Label();
            lblYazi.Text = "Tebrikler Yüksek skor yaptınız";
            lblYazi.SetBounds(10, 30, 300, 30);
            lblYazi.BackColor = Color.SkyBlue;
            this.Controls.Add(lblYazi);
            lblad.Text = "Adınız";
            lblad.SetBounds(110, 70, 100, 30);
            this.Controls.Add(lblad);
            //textbox
            this.Controls.Add(ad);
            ad.SetBounds(50, 100, 200, ad.Height);
            //buton
            Button kaydet = new Button();
            kaydet.Text = "Kaydet";
            kaydet.BackColor = Color.Wheat;
            kaydet.SetBounds(100, 150, 100, 30);
            this.Controls.Add(kaydet);
            kaydet.Click += kaydet_Click;//kaydet butonuna basıldığında kişiyi kaydetmesi için
        }
        void kaydet_Click(object sender, EventArgs e)
        {
            dosyayaz();//dosya yaz fonksiyonumuzu çağırıp
            this.Visible = false;//burdada kayıt yaptıktan sonra görünürlüğünü kapatıp
        }
        void tamam_Click(object sender, EventArgs e)
        {
            this.Visible = false;//liste tabplosunu görünürünü kaldırıyoruz
        }
        private void buton()
        {
            //buton özellikleri
            tamam.Text = "Tamam";
            tamam.BackColor = Color.Wheat;
            tamam.SetBounds(270, 220, 100, 30);
            this.Controls.Add(tamam);//groupboxta atıp görünmesi için

        }
        private void lstbox()
        {
            //liste
            liste.BackColor = Color.White;
            liste.SetBounds(5, 25, 370, 200);
            this.Controls.Add(liste);
            liste.Font = new Font("OCR A Extended", 20, FontStyle.Bold);
            //dosyam işlemleri
            dosya();//burda eğer dosya yoksa hata vermemesi için dosya oluştutur fonksiyonumuza gönderiyoruz
            StreamReader oku = File.OpenText(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\dosya.txt");//dosya yı aç
            string yazi;//açılan dosyanın satırlarını string deişkene atıyoruz 
            while ((yazi=oku.ReadLine()) != null)//tüm satırları okuması için döngü
            {
                liste.Items.Add(yazi);//listemize ekletiyoruz
            }
            oku.Close();//dosayayı kapatıyoruz


        }
        public bool skor(int sn,int msn)//alınan saniye ve mili saniyeleri 
        {
            dosya();//ilk eğer dosya yok ise oluşturması için fonksiyona gönderiyoruz
            sıra = 1;//burda ki sıra statictir bu bize kaçıncı sırada olduğunu belirlemek için lazım
            StreamReader oku = File.OpenText(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\dosya.txt");//doyayı okuma için aöıp
            string yazi, skorsaniye = "", skormilisaniye = "";//burda dosyadan aldığım değerleri değişkenlerde tutmak için 
            while ((yazi=oku.ReadLine()) != null)//yazimiz bizim dosyamızın içindeki satırlara ulaşabilmemiz için değişken 
            {
                for(int i=0;i<yazi.Length;i++)//burda yazının uzunluğuna göre göngüye sokup
                {
                    if(yazi[i]==' ')//boşluk kısmına kadar veriyi oku
                    {
                        i++;//bir artırıp
                    san://saniyeyi belirlemek
                        if(yazi[i]!=':')//saniye kısmını belirlemek için dosyaya kaydederken böyle kaydediyorum
                        {
                            skorsaniye += yazi[i];//char karekterini skorsaniyeye atıp
                            i++;//bir artırıp sonraki char karakterine geçip
                            goto san;//kolaylık sağladığı için goto kulandım
                        }
                    sal://milisaniyeyi belirlemek
                         i++;//: dan sonra sayı gelmektedir dosyalara öyle yazdırma işlemi yaptım
                        if (yazi[i] != ' ')//yazma işleminin en sonuna boşluk ekledim
                        {
                            skormilisaniye += yazi[i];//mili saniyeyi aktarıp
                            goto sal;
                        }
                    break;//burda satırda bulunan verinin salseni ve mili saniyesini aldık tan sonra for dan çıkması için
                    

                    }
                }
                if(Convert.ToInt32(skorsaniye)<=sn)//burda eğer gönderilen değer kayıtlıdan büyükse saniyesi
                {
                    if (Convert.ToInt32(skormilisaniye) <= msn)//burda milisaniyesi büyükse
                    {
                        saniye = sn;//bir değişkende tutup
                        milisaniye = msn;
                        oku.Close();//dosyamızı kapatıp
                        return true;//return true döndürüyoruz
                    }
                }
                sıra++;
                skorsaniye = "";
                skormilisaniye = "";

            }
            oku.Close();
            return false;
            
        }
        private void dosyayaz()
        {
            StreamWriter temp = File.CreateText(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\temp.txt");//ilk olarak geçici dosya oluşturup
            StreamReader oku = File.OpenText(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\dosya.txt");//dosyamızı okumak için açıp
            string yazi;//okuduklarımızı yazı ya aktarma için
            int i=1;//burda 5 ten fazla yazdırmaması için
            while((yazi=oku.ReadLine())!=null)
            {
                    if(i==sıra)//burda static değişkenimiz kaçıncı olduğunu belirleyip
                    { //aldığı değerleri yazdırıp
                        temp.WriteLine(ad.Text + " " + saniye.ToString() + ":" + milisaniye.ToString() + " "); // Dosya.WriteLine ile dosyaya isim ve soyisim text kutularındaki değerleri aralrına bir tab boşluk bırakarak ekledik.
                    }
                    temp.WriteLine(yazi);//geri kalanıda aynı şekilde aktarıp
                    i++;
                    if (i == 5)// olduğundada çıkması için
                        break;
            }
            
            oku.Close(); // Dosya yı kapattık.
            temp.Close();
            File.Delete(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\dosya.txt");//dosyayaı silip
            //ismini değiştirdik
            File.Move(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\temp.txt", @"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\dosya.txt");
        }
        private void dosya()
        {
            //burda eğer dosya yok ise dosya oluşturmasını sağlamak için try -catch kullandık
            try
            {
                StreamReader Dosya = File.OpenText(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\dosya.txt");//Dosyayı açmaya çalış olmaz ise catch bloğuan geç
                Dosya.Close();
            }
            catch
            {
                StreamWriter Dosya = File.CreateText(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\kayıt\dosya.txt");// yeni dosya oluştur.
                for (int i = 1; i <= 5; i++)//burda ki döngü yeni dosya oluştuğunda ilk 5 tane değerleri boş girdirip
                    Dosya.WriteLine("isimsiz 00:00 ");
                Dosya.Close();
            }
        }  
    }
}
