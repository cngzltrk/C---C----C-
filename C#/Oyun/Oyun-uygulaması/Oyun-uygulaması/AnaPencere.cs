using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
namespace Oyun_uygulaması
{
    public partial class AnaPencere : Form
    {
        raket sopa = new raket();
        top topp = new top();
        int mouseX;
        int mouseY;
        Graphics cizRaket, cizTop;
        public AnaPencere()
        {

            InitializeComponent();
            timer1.Enabled = true;
            
        }

        private void btnSkor_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            MouseClick += AnaPencere_MouseClick;

            
            
        }

        void AnaPencere_MouseClick(object sender, MouseEventArgs e)
        {
            //Cursor.Hide();
            Paint += AnaPencere_Paint;
            MouseMove += AnaPencere_MouseMove;

        }

        void AnaPencere_MouseMove(object sender, MouseEventArgs e)
        {
            mouseX=e.X;
            mouseY=e.Y;
            Text = mouseX.ToString()+","+mouseY.ToString();
            Invalidate();
        }

        void AnaPencere_Paint(object sender, PaintEventArgs e)
        {
            cizRaket = this.CreateGraphics();
            cizTop = this.CreateGraphics();
            sopa.cizimAraci(cizRaket, mouseX);
            topp.cizimAraci(cizTop, mouseX);
           

        }

        private void pnlTahta_Paint(object sender, PaintEventArgs e)
        {
            
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            
        }
    }
}
