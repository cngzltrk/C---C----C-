using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mouse
{
    public class raket:Button
    {
        int mouseX;

        public raket()
        {
            this.Width = 200;
            this.Height = 20;
            this.BackColor = Color.Red;
            this.SetBounds(250, 450, this.Width, this.Height);

        }

        public void hareketEt(int x)
        {
            mouseX =x ;
            mouseX -= this.Width / 2;
            if (mouseX <= 0)
            {
                mouseX = 0;
            }
            if (mouseX >= 800)
            {
                mouseX = 800;
            }
            this.Left = mouseX;

        }

    }
}
