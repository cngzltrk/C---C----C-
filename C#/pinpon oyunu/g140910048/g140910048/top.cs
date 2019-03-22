using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Media;
namespace g140910048
{
    class top:PictureBox//kalıtımı pictur box tan aldık
    {
        SoundPlayer carpses = new SoundPlayer();//çarptığında ses vermesi için
        SoundPlayer oyunsonu = new SoundPlayer();//oyun sonu ses vermesi için
        Random rasgele = new Random();//buda raket topu ilk başladığında rasgele sağtarafamı gitsin yoksa sol tarafamı
        int konumX, konumY;//topun konumu
        int hız_X = 5, hız_Y = -5;//topun  hızı
        float hız=5,artıHız;//buda çarptığında %10 artmasını sağlamak için değişkenlerimiz
        public top() 
        {
            this.BackColor = Color.Transparent;//topun arka kısmı transparan yaptık 
            this.BackgroundImage = Image.FromFile(@"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\resim\top.png");//arka kısma resmimizi attık
            this.Width = 20;
            this.Height = 20;
        }
        public void konumlama(int x, int y,int rgen)//raketin konumunu alıp, rgen raketin genişliği
        {
            if (1 == rasgele.Next(3))//burda top sağ veya sola doğru rastgele başlaması için
                hız_X = -hız_X;
            konumY = y - 20;//y başlangıcı raketin hemen üstünden
            konumX = x+(rgen/2);//topun x konumunuda raketin olduğu noktadan  
            this.SetBounds(konumX, konumY, this.Width, this.Height);//ekrana basıp
            this.Visible = true;//görünürlüğünü true  yapıyoruz
        }
        //fonksiyonumuz bool türünde olması oyunda yanıp yanmadığı belirlemek için
        public bool hareketEt(int rTop, int rBottom, int rLeft, int rRight, int pnlTop, int pnlBottom, int pnlLeft, int pnlRight)
        {
            //ses dosyalarımızı konumunu atıp
            carpses.SoundLocation = @"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\ses\button-16.wav";
            oyunsonu.SoundLocation = @"C:\Users\Cengo\Desktop\Ders notları\c# notları\Proje\g140910048\g140910048\ses\button-4.wav";
            
            this.Left += hız_X;//hızımız x

            this.Top += hız_Y;//hızımız y
            //burda topun alt kısmı raketin altkısmı ve topun sol  kısmı ile raketin sol kısmı ve topun sağı ile raketin sağ kısmı 
            //yani top raketini konumuna göre raketin üstüne gelecek şekilde olması olursa 
            if (this.Bottom >= rTop && this.Bottom <= rBottom && this.Left >= rLeft && this.Right <= rRight)
            {

                artıHız = hız /10;//topun hıznı hız değişkenine göre % nunu al
                hız = hız + artıHız;//ve hızın float değişkeninin elmizde tutmak için
                hız_X += (int)artıHız;//flotaı inte çevirip hızını artırıyoruz
                hız_Y += (int)artıHız;
                hız_Y = -hız_Y;//hızın y kısmını - yaparak yukarıya doğru çıkmasını sağlıyoruz
                carpses.Play();//ses çıkmasını sğlamak için oynatıyoruz
            }
            if (this.Left <= pnlLeft)//eğer topun solkısmı panelin sol kısmına eşit ve ya paneli geçerse
            {
                hız_X = -hız_X;//x konumunu döndürmesi 
                carpses.Play();//ve ses çıkarması için



            }
            if (this.Right >= pnlRight)//aynı şekilde
            {
                hız_X = -hız_X;
                carpses.Play();

            }
            if (this.Top <= (pnlTop + 50))//burda da üstde bulunan skor tahtasının arka kısmına girmemesi için sınırlama yaptım
            {
                hız_Y = -hız_Y;
                carpses.Play();

            }
            if (this.Bottom >= pnlBottom)//eğerki top paneli geçerse bitir
            {
                //değerlerie eskiye haline çevirip
                hız_X = 5;
                hız_Y = -5;
                hız=5;
                oyunsonu.Play();//oyun sonu uyarı sesini çıkarıp
                this.Visible = false;// topun görünürlüğünü false yapıp
                return false;//geriye oyunu durdurması için false gönderiyoruz
            }
                

            return true;//ğer oyun sonu gelmediyse topun hareketinin devamı için true döndürüyoruz



        }

    }
}
