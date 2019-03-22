using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Oyun
{
    public partial class AnaPencerem : Form
    {
        raket sopa = new raket();
        int mouseX;
        int mouseY;
        Graphics cizRaket;
        public AnaPencerem()
        {
            InitializeComponent();
            this.FormBorderStyle = FormBorderStyle.SizableToolWindow;

        }

        private void AnaPencerem_Load(object sender, EventArgs e)
        {
            MouseClick += AnaPencere_MouseClick;
            
        }

        private void AnaPencere_MouseClick(object sender, MouseEventArgs e)
        {
            Paint += AnaPencere_Paint;
            MouseMove += AnaPencere_MouseMove;
        }

        private void AnaPencere_MouseMove(object sender, MouseEventArgs e)
        {
            mouseX = e.X;
            mouseY = e.Y;
            Text = mouseX.ToString() + "," + mouseY.ToString();
            Invalidate();
        }

        private void AnaPencere_Paint(object sender, PaintEventArgs e)
        {
            cizRaket = this.CreateGraphics();
            sopa.cizimAraci(cizRaket, mouseX);
        }
    }
}
