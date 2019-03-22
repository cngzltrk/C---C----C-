using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Oyun_uygulaması
{
    class top
    {
        Random rnd = new Random();
        int sallama;
        SolidBrush firca = new SolidBrush(Color.Black);
        public void cizimAraci(Graphics e, int x)
        {
            //sallama = rnd.Next(0, 1);
            //if (sallama == 0)
            //{

            //}
            e.FillEllipse(firca, x, 420, 25, 25);

        }
    }
}
