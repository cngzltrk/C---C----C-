using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fonksiyon_aşırıyükeleme
{
    class Program
    {//3 sılaş sonucu çıkan yorum satırı bize main içinde çağrılan fonksiyon hakkında alt bilgi verir
        /// <summary>
        /// karenin alanı hesaplar
        /// </summary>
        /// <param name="boyut"></param>
        /// <returns></returns>
        static int alanhesapla(int boyut)
        {
            return boyut * boyut;
        }
        /// <summary>
        /// bu bize dikdötgen alanı hesaplar
        /// </summary>
        /// <param name="yük"></param>
        /// <param name="gen"></param>
        /// <returns></returns>
        static int alanhesapla(int yük,int gen)
        {
            return yük*gen;
        }//varsıyılan değerler her zaman soldan sağa doğru ilerler varsayılan değerli parametlreler her zman en sonda olmalıdır eğer varsayılan olmayan değerleri başa yazarsak 
        //derleyici bize hata verir
        //bu fonksiyon bize önceden tanımlı değer alır yani eğer değersiz göndersek bile önceden tanımlı değeride alır
        static int alanhesapla(int yük=10, int gen=15)
        {
            return yük * gen;
        }

        static void Main(string[] args)
        {
            int x = alanhesapla(2);
        }
    }
}
