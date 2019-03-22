using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ödev2
{
    class Program
    {
        public void menü()//dışardan erişimli fonksiyon yaptım
        {
            bool kontrol=false;//bu kontrolümüz seçenek yanlış girilirse diye
            int secenek;
            Console.WriteLine("1- String bir değişkende,string değer substring kullanmadan ara ");
            Console.WriteLine("2- String bir değişkende,string değer substring kullanarak ara ");
            Console.WriteLine("3-Alfabenin karakterini bir string de ara kaç adet geçiyor bul ve çiz ");
            do//menümüzün yanlış seçenek seçildiğinde döndürmesi için
            {
                Console.Write("Seçenek giriniz ....:");
                secenek = int.Parse(Console.ReadLine());//dışardan girilen değeri int çevirme
                switch (secenek)//menümüzün seçeneklerini yönlendirmek için
                {
                    case 1:
                        secenek1();//fonksiyonumza yönlediriyoruz
                        break;
                    case 2:
                        secenek2();//fonksiyonumza yönlediriyoruz
                        break;
                    case 3:
                        secenek3();//fonksiyonumza yönlediriyoruz
                        break;
                    default://yanlış değer verildiğinde uygulanacaklar
                        Console.WriteLine(" Yanlış seçenek tekrar deneyiniz..:");
                        kontrol = true;
                        break;
                }
              } while (kontrol);
        }
        void secenek1()
        {
            string kelime,metin;
            int sayac = 0;
            Console.Write("Aranacak kelime....:");
            kelime = Console.ReadLine();
            Console.Write("Metni giriniz...:");
            metin = Console.ReadLine();
            for (int i = 0; i < kelime.Length; i++)
            {
                metin = metin + " ";
            }
            for(int i=0;i<metin.Length;i++)//metinimizin tüm indexlerine bakmak için döngümüz
            {
                if (metin[i] == kelime[0])//eğer metinin i ninci indexi ile kelime nin 0 ıncı indexi tutarsa sonrakiindexlerde kontrol edilmesi için
                {
                    sayac = 0;//sayacımız burda eğer kelimenin ve metinin indexleri aynı ise sonradan kelimenin uzunluğu ile karşılaştırıp eğer o kelime metin içinde olduğunu göstermek için
                    for(int j=0;j<kelime.Length;j++)//burda kelimenin uzunluğu kadar kontrol ediyoruz
                    {
                        if(metin[i+j]==kelime[j])//metinin i+j indexi ile metin j indexleri karşılaştırılıyor
                        {
                            sayac+=1;
                        }
                    }
                    if (sayac == kelime.Length)//burda eğer sayaç sayısı ekime ile keime uzunluğu ile eş değerse index i ve kelime yazdırma sı için
                    {
                        Console.WriteLine("Kelime {0} indis....:{1}", kelime,i);
                    }
                }
            }
        }
        void secenek2()
        {
            string kelime, metin, deneme;//deneme bizim supstring ile alcağımız kelime yi içine aktarmak için
            Console.Write("Aranacak kelime....:");
            kelime = Console.ReadLine();
            Console.Write("Metni giriniz...:");
            metin = Console.ReadLine();
            for (int i = 0; i < kelime.Length; i++)
            {
                metin = metin + " ";
            }
            for(int i=0;i<metin.Length;i++)//metnin tüm index lerini kontrol ediyoruz
            {
                if (metin[i] == kelime[0])//metnin indexi ile kelimenin 0 ıncı indexi karşılaştırılıyor eğer doğru ise 
                {
                    deneme = metin.Substring(i, kelime.Length);//hemen substring komutu ile o indexten sonraki kelime uzunluğu kadar karakteri denemeye atıyoruz
                    if (deneme == kelime)//burda attığımız karakterler kelime ile bir tutarsa yazdırma işlemi yapıyoruz
                    {
                        Console.WriteLine("Kelime {0} indis....:{1}", kelime, i);
                    }
                }              
            }
        }
        void secenek3()
        {
            string metin;
            bool kontrol = false;//bu kontrolümüz türkçe karakterler için yaptığımız döngünün sonsuz olmaması için
            char kharf,bharf;//kharf küçük harf bharf büyük harf anlamında
            int sayac = 0;//sayacımız yıldız sayısı için ve karakter sayısı için
            Console.Write("Metni giriniz...:");
            metin = Console.ReadLine();
            Console.WriteLine("\n Karakter sayısı grafik gösterimi");
            Console.WriteLine("--------------------------------------");
            //bu yaptığım döngü bizim kolay okumamızı sağlıyor ama ne yazık ki bilgisayar çok işlem yapıyor bir karakteri araştırıyor o krakter le işlemi bittikden sonra diğerine geçip onu araştırıyor
            for (int j = 65; j <= 90;j++ )//burda ki döngü ascı taplosundan yararlanarak yaptığım döngü harf sayısına göre
            {
                kontrol = false;//bu kontrolümüz sonsuz döngünün engeli için
                       
                bharf = (char)j;//burda j ik 65 sayısını karaktere çevirerek A harfi ni elde etmiş oluruz
                kharf = (char)(j + 32);//burda ise yine ascıde büyük küçük harf farkı 32 olmasından yararlanarak a harfini elde ettik
                bas://bu bizim türkçe karakterlerimiz için döngümüzü başlatacağımız yer
                sayac = 0;   //yıldız için 
                for (int i = 0; i < metin.Length; i++)//metnin tüm indexlerini incelemek için
                {
                    if (metin[i] == kharf || metin[i] ==bharf )//eğer büyük veya küçük harf uyarsa sayacımızı artıtırıyoruz
                    {
                        sayac+= 1;
                    }
                }
                Console.Write("\n{0}, sayısı : {1}", bharf,sayac);//yazdırma işlemi
                for(int k=1;k<=sayac;k++)//yıldızımız için döngü
                {
                    Console.Write(" * ");
                }
                if (kontrol)//burda eğer bi kere türkçe karakter için işlem yaplıdığında bi daha yapaması için 
                    continue;
                if (j == 67)//67 sayısı c ve ondan sonra ascıde ç olmadığından ben bunu yapmak için c den sonra ç eklemesi için
                {
                    bharf = 'Ç';
                    kharf = 'ç';
                    kontrol = true;//kontolü true yaparak bi daha gelip işlem yapması için
                    goto bas;//kolaylık sağladığından goto kulanmak daha iyi oldu
                }
                else if (j == 71)//g den sonra Ğgelmesi için
                {
                    bharf = 'Ğ';
                    kharf = 'ğ';
                    kontrol = true;
                    goto bas;
                }
                else if (j == 79)//aynı şekilde ö için
                {
                    bharf = 'Ö';
                    kharf = 'ö';
                    kontrol = true;
                    goto bas;
                }
                else if (j == 83)//ş için
                {
                    bharf = 'Ş';
                    kharf = 'ş';
                    kontrol = true;
                    goto bas;
                }
                else if (j == 85)//ve son olarakda ü için
                {
                    bharf = 'Ü';
                    kharf = 'ü';
                    kontrol = true;
                    goto bas;
                }
            }
        }
        static void Main(string[] args)
        {
            Program pro = new Program();//nsnemizi oluşturup
            pro.menü();//tek menümüzü çağırarak 
            Console.ReadKey();   //buda ekran hemen kapanmaması için       
        }
    }
}
