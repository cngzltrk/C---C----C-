using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
namespace g140910048
{
    class raket:Button
    {
        int konumX;
        int konumY;
        public raket(int genislikpnl,int yükseklikpnl)//alınandeğerleri
        {
            this.Width=genislikpnl/6;//panelin genişliğinin 6 kat kküçüğü olarak ayarladım
            this.Height=20;//yükseklik sabit 
            konumY = yükseklikpnl - this.Height;//konum y si sayfa büyüdüğündede alt kısımda olmasın sağlamak için 
            SetBounds(genislikpnl/3, konumY, this.Width, this.Height);//raketimizi bastırıyoruz
            this.BackColor = Color.Aqua;//renkgimizi werdik
        }
        public void hareketEt(int x,int xs)//moussenin ve panelin değerlerini alıp
        {
            konumX = x;//mouse nin x konumunu atıp
            konumX -= this.Width / 2;//mosuse nin tam ortasında olması için raket
            if (konumX <= 0)//soltarafa girmemesi için
            {
                konumX = 0;
            }
            if (konumX >= (xs - this.Width))//sağ tarafa girmemesi için
                konumX = xs - this.Width;
            this.Left = konumX;//ve ekrana da hareketini buna göre değişmesi için
        }



    }
}
