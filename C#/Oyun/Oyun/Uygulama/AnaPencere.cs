using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Uygulama
{
    public partial class AnaPencere : Form
    {
        raket r=new raket();
        public AnaPencere()
        {
            InitializeComponent();
            //this.FormBorderStyle = FormBorderStyle.SizableToolWindow;
            Controls.Add(r);
        }

        private void AnaPencere_Load(object sender, EventArgs e)
        {


        }
    }
}
