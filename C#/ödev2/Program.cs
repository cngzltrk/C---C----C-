/***************************************************************
**								SAKARYA ÜNİVERSİTESİ
**						BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**							BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**								PROGRAMLAMA GİRİŞ DERSİ
**								  2015-2016 GÜZ DÖNEMİ
**
**						ÖDEV NUMARASI........:	ÖDEV 1
**						ÖĞRENCİ ADI..........:	CENGİZ ALTÜRK
**						ÖĞRENCİ NUMARASI.....:	G140910048
**						DERSİN ALINDIĞI GRUP.:  2.ÖĞRETİM C
******************************************************************/





using System;

namespace ödev
{
    class matris
    {
        int x, y;
        int[,] matrisimiz;
        int satır, sutun;

        public matris()
        {
            do{
                Console.Write("Satır sayısını giriniz...:");
                y = int.Parse(Console.ReadLine());
                Console.Write("Sütun sayısını giriniz...:");
                x = int.Parse(Console.ReadLine());
                if(x!=y)
                {
                    Console.WriteLine("Matris kare olmalı (satır = sütun)");
                }
            }while(x != y);
            matrisimiz=new int[y,x];
        } 
        public void ekranayaz()
        {
            int temp = 0;
            for (int i = 0; i <= x; i++)
            {
                if (i == 0)
                {
                    Console.Write("   ");
                    continue;
                }

                Console.Write(" {0} ", i);
            }
            Console.Write("\n");
            for (int i = 0; i < y; i++)
            {
                Console.Write("\n {0} ", ++temp);
                for (int j = 0; j < x; j++)
                {
                    Console.Write(" {0} ", this.matrisimiz[i, j]);
                }
                Console.Write("\n");
            }
            Console.WriteLine("boyut.." + matrisimiz.GetLength(1));
        }
        public void matrisYazdır()
        {        
            Random rnd = new Random();
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {  
                    this.matrisimiz[i, j] = rnd.Next(1, 9);
                }
            }
        }
        public void degistir()
        {
            Console.Write("Yer değiştirilmesi istenen Satır sayısını giriniz...:");
            this.satır = int.Parse(Console.ReadLine());
            Console.Write("Yer değiştirilmesi istenen Sütun sayısını giriniz...:");
            this.sutun = int.Parse(Console.ReadLine());          
        }
        static void Main(string[] args)
        {
            matris dizi = new matris();
            dizi.matrisYazdır();
            dizi.ekranayaz();
            dizi.degistir();

            Console.ReadKey();
        }
    }
}
