using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ödev1
{
    class program
    {
        int boyut;
        int[] dizimiz;
        public program()//kurucu fonksiyonumuzu göstermelik yaptım
        {         
        }
        public void diziboyut()
        {
            Console.Write("Dizi Boyutu giriniz lütfen ...:");
            boyut = int.Parse(Console.ReadLine());
            this.dizimiz = new int[boyut];
        }
        public void diziAtama()
        {
            Random rnd = new Random();
            for (int i = 0; i < boyut; i++)
            {
                this.dizimiz[i] = rnd.Next(1, 10);
            }
            DiziYazdır();
        }
        private void DiziYazdır()
        {
            Console.Write("Dizi..:");
            for (int i = 0; i < dizimiz.Length; i++)
            {
                Console.Write(" {0} ", dizimiz[i]);
            }
        }
        public void top()
        {
            bool kontrol;
            int soltop = 0, sagtop = 0,aratop=0,index1,index2,temp;
            do
            {
                Console.Write("\nBirinci index  girin....: ");
                index1 = int.Parse(Console.ReadLine());
                Console.Write("İkinci index  girin....: ");
                index2 = int.Parse(Console.ReadLine());
                if (this.dizimiz.Length > index1 && index1 > 0 && this.dizimiz.Length > index2 && index2 > 0)
                {
                    if (index1 > index2)
                    {
                        temp = index1;
                        index1 = index2;
                        index2 = index1;
                    }                      

                    kontrol = false;
                    for (int i = 0; i < dizimiz.Length; i++)
                    {
                        if (i < index1)
                            soltop += this.dizimiz[i];
                        else if (i > index2)
                            sagtop += this.dizimiz[i];
                        else
                            aratop += this.dizimiz[i];
                    }
                    Console.WriteLine("Sol Toplam ..: " + soltop);
                    Console.WriteLine("Sağ Toplam ..: " + sagtop);
                    Console.WriteLine("Ara Toplam ..: " + aratop);
                }
                else
                {
                    kontrol = true;
                    Console.WriteLine("İndex Sayısı diziyi aştı lütfen tekrar deneyin");
                }
            } while (kontrol);
        }

        static void Main(string[] args)
        {
            program d1 = new program();
            d1.diziboyut();
            d1.diziAtama();
            d1.top();
            Console.ReadKey();

        }
    }
}
