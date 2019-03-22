namespace denemeOyun
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.arkaTahta = new System.Windows.Forms.Panel();
            this.raket = new System.Windows.Forms.PictureBox();
            this.top = new System.Windows.Forms.PictureBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.arkaTahta.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.raket)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.top)).BeginInit();
            this.SuspendLayout();
            // 
            // arkaTahta
            // 
            this.arkaTahta.Controls.Add(this.raket);
            this.arkaTahta.Controls.Add(this.top);
            this.arkaTahta.Dock = System.Windows.Forms.DockStyle.Fill;
            this.arkaTahta.Location = new System.Drawing.Point(0, 0);
            this.arkaTahta.Name = "arkaTahta";
            this.arkaTahta.Size = new System.Drawing.Size(590, 400);
            this.arkaTahta.TabIndex = 0;
            this.arkaTahta.Paint += new System.Windows.Forms.PaintEventHandler(this.arkaTahta_Paint);
            // 
            // raket
            // 
            this.raket.BackColor = System.Drawing.SystemColors.ControlDark;
            this.raket.Location = new System.Drawing.Point(35, 328);
            this.raket.Name = "raket";
            this.raket.Size = new System.Drawing.Size(150, 20);
            this.raket.TabIndex = 1;
            this.raket.TabStop = false;
            // 
            // top
            // 
            this.top.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.top.Location = new System.Drawing.Point(111, 83);
            this.top.Name = "top";
            this.top.Size = new System.Drawing.Size(25, 26);
            this.top.TabIndex = 0;
            this.top.TabStop = false;
            // 
            // timer1
            // 
            this.timer1.Interval = 1;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(590, 400);
            this.Controls.Add(this.arkaTahta);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.arkaTahta.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.raket)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.top)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel arkaTahta;
        private System.Windows.Forms.PictureBox raket;
        private System.Windows.Forms.PictureBox top;
        private System.Windows.Forms.Timer timer1;
    }
}

