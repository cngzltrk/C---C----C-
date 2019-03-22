namespace Oyun
{
    partial class AnaPencere
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
            this.skorTahta = new System.Windows.Forms.GroupBox();
            this.btntamam = new System.Windows.Forms.Button();
            this.lstListem = new System.Windows.Forms.ListBox();
            this.grbSkor = new System.Windows.Forms.GroupBox();
            this.tamam = new System.Windows.Forms.Button();
            this.vazgec = new System.Windows.Forms.Button();
            this.ad = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.lblzaman = new System.Windows.Forms.Label();
            this.ustTahta = new System.Windows.Forms.Panel();
            this.skor = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.top = new System.Windows.Forms.PictureBox();
            this.raket = new System.Windows.Forms.PictureBox();
            this.zaman = new System.Windows.Forms.Timer(this.components);
            this.sayac = new System.Windows.Forms.Timer(this.components);
            this.label2 = new System.Windows.Forms.Label();
            this.arkaTahta.SuspendLayout();
            this.skorTahta.SuspendLayout();
            this.grbSkor.SuspendLayout();
            this.ustTahta.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.top)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.raket)).BeginInit();
            this.SuspendLayout();
            // 
            // arkaTahta
            // 
            this.arkaTahta.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.arkaTahta.Controls.Add(this.skorTahta);
            this.arkaTahta.Controls.Add(this.grbSkor);
            this.arkaTahta.Controls.Add(this.lblzaman);
            this.arkaTahta.Controls.Add(this.ustTahta);
            this.arkaTahta.Controls.Add(this.top);
            this.arkaTahta.Controls.Add(this.raket);
            this.arkaTahta.Dock = System.Windows.Forms.DockStyle.Fill;
            this.arkaTahta.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.arkaTahta.Location = new System.Drawing.Point(0, 0);
            this.arkaTahta.Name = "arkaTahta";
            this.arkaTahta.Size = new System.Drawing.Size(846, 449);
            this.arkaTahta.TabIndex = 0;
            this.arkaTahta.Paint += new System.Windows.Forms.PaintEventHandler(this.arkaTahta_Paint);
            this.arkaTahta.MouseClick += new System.Windows.Forms.MouseEventHandler(this.arkaTahta_MouseClick);
            this.arkaTahta.MouseMove += new System.Windows.Forms.MouseEventHandler(this.arkaTahta_MouseMove);
            // 
            // skorTahta
            // 
            this.skorTahta.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.skorTahta.Controls.Add(this.btntamam);
            this.skorTahta.Controls.Add(this.lstListem);
            this.skorTahta.Location = new System.Drawing.Point(22, 71);
            this.skorTahta.Name = "skorTahta";
            this.skorTahta.Size = new System.Drawing.Size(368, 261);
            this.skorTahta.TabIndex = 5;
            this.skorTahta.TabStop = false;
            this.skorTahta.Text = "Skorlar";
            // 
            // btntamam
            // 
            this.btntamam.Location = new System.Drawing.Point(254, 224);
            this.btntamam.Name = "btntamam";
            this.btntamam.Size = new System.Drawing.Size(108, 31);
            this.btntamam.TabIndex = 1;
            this.btntamam.Text = "Tamam";
            this.btntamam.UseVisualStyleBackColor = true;
            this.btntamam.Click += new System.EventHandler(this.btntamam_Click);
            // 
            // lstListem
            // 
            this.lstListem.FormattingEnabled = true;
            this.lstListem.ItemHeight = 23;
            this.lstListem.Location = new System.Drawing.Point(6, 26);
            this.lstListem.Name = "lstListem";
            this.lstListem.Size = new System.Drawing.Size(346, 188);
            this.lstListem.TabIndex = 0;
            // 
            // grbSkor
            // 
            this.grbSkor.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.grbSkor.Controls.Add(this.label2);
            this.grbSkor.Controls.Add(this.tamam);
            this.grbSkor.Controls.Add(this.vazgec);
            this.grbSkor.Controls.Add(this.ad);
            this.grbSkor.Controls.Add(this.label3);
            this.grbSkor.Location = new System.Drawing.Point(442, 126);
            this.grbSkor.Name = "grbSkor";
            this.grbSkor.Size = new System.Drawing.Size(317, 190);
            this.grbSkor.TabIndex = 4;
            this.grbSkor.TabStop = false;
            this.grbSkor.Text = "Skor";
            // 
            // tamam
            // 
            this.tamam.Location = new System.Drawing.Point(215, 147);
            this.tamam.Name = "tamam";
            this.tamam.Size = new System.Drawing.Size(96, 32);
            this.tamam.TabIndex = 4;
            this.tamam.Text = "Tamam";
            this.tamam.UseVisualStyleBackColor = true;
            this.tamam.Click += new System.EventHandler(this.tamam_Click);
            // 
            // vazgec
            // 
            this.vazgec.Location = new System.Drawing.Point(113, 147);
            this.vazgec.Name = "vazgec";
            this.vazgec.Size = new System.Drawing.Size(96, 32);
            this.vazgec.TabIndex = 3;
            this.vazgec.Text = "Vazgeç";
            this.vazgec.UseVisualStyleBackColor = true;
            this.vazgec.Click += new System.EventHandler(this.vazgec_Click);
            // 
            // ad
            // 
            this.ad.Location = new System.Drawing.Point(75, 92);
            this.ad.Name = "ad";
            this.ad.Size = new System.Drawing.Size(161, 30);
            this.ad.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(109, 66);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(82, 23);
            this.label3.TabIndex = 1;
            this.label3.Text = "ADINIZ";
            // 
            // lblzaman
            // 
            this.lblzaman.AutoSize = true;
            this.lblzaman.Font = new System.Drawing.Font("Times New Roman", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblzaman.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.lblzaman.Location = new System.Drawing.Point(12, 46);
            this.lblzaman.Name = "lblzaman";
            this.lblzaman.Size = new System.Drawing.Size(55, 22);
            this.lblzaman.TabIndex = 3;
            this.lblzaman.Text = "00:00";
            // 
            // ustTahta
            // 
            this.ustTahta.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(128)))), ((int)(((byte)(255)))));
            this.ustTahta.Controls.Add(this.skor);
            this.ustTahta.Controls.Add(this.label1);
            this.ustTahta.Location = new System.Drawing.Point(6, 3);
            this.ustTahta.Name = "ustTahta";
            this.ustTahta.Size = new System.Drawing.Size(840, 40);
            this.ustTahta.TabIndex = 2;
            this.ustTahta.MouseClick += new System.Windows.Forms.MouseEventHandler(this.arkaTahta_MouseClick);
            // 
            // skor
            // 
            this.skor.BackColor = System.Drawing.Color.Teal;
            this.skor.Font = new System.Drawing.Font("Modern No. 20", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.skor.ForeColor = System.Drawing.Color.Cornsilk;
            this.skor.Location = new System.Drawing.Point(45, 5);
            this.skor.Name = "skor";
            this.skor.Size = new System.Drawing.Size(162, 31);
            this.skor.TabIndex = 1;
            this.skor.Text = "Yüksek Skorlar";
            this.skor.UseVisualStyleBackColor = false;
            this.skor.Click += new System.EventHandler(this.skor_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Comic Sans MS", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label1.Location = new System.Drawing.Point(557, 6);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(271, 27);
            this.label1.TabIndex = 0;
            this.label1.Text = "Oyunu başlamak için Tek tık";
            // 
            // top
            // 
            this.top.BackColor = System.Drawing.Color.Transparent;
            this.top.Image = global::Oyun.Properties.Resources.asdasd;
            this.top.Location = new System.Drawing.Point(178, 317);
            this.top.Name = "top";
            this.top.Size = new System.Drawing.Size(15, 15);
            this.top.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.top.TabIndex = 1;
            this.top.TabStop = false;
            // 
            // raket
            // 
            this.raket.BackColor = System.Drawing.Color.Teal;
            this.raket.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.raket.Location = new System.Drawing.Point(162, 338);
            this.raket.Name = "raket";
            this.raket.Size = new System.Drawing.Size(150, 20);
            this.raket.TabIndex = 0;
            this.raket.TabStop = false;
            // 
            // zaman
            // 
            this.zaman.Interval = 10;
            this.zaman.Tick += new System.EventHandler(this.zaman_Tick);
            // 
            // sayac
            // 
            this.sayac.Interval = 1;
            this.sayac.Tick += new System.EventHandler(this.sayac_Tick);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.label2.Location = new System.Drawing.Point(6, 26);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(298, 23);
            this.label2.TabIndex = 5;
            this.label2.Text = "Tebrikler Yüksek skor yaptınız";
            // 
            // AnaPencere
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(846, 449);
            this.Controls.Add(this.arkaTahta);
            this.Name = "AnaPencere";
            this.Text = "Oyun";
            this.Load += new System.EventHandler(this.AnaPencere_Load);
            this.arkaTahta.ResumeLayout(false);
            this.arkaTahta.PerformLayout();
            this.skorTahta.ResumeLayout(false);
            this.grbSkor.ResumeLayout(false);
            this.grbSkor.PerformLayout();
            this.ustTahta.ResumeLayout(false);
            this.ustTahta.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.top)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.raket)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel arkaTahta;
        private System.Windows.Forms.Timer zaman;
        private System.Windows.Forms.PictureBox raket;
        private System.Windows.Forms.PictureBox top;
        private System.Windows.Forms.Panel ustTahta;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblzaman;
        private System.Windows.Forms.Timer sayac;
        private System.Windows.Forms.Button skor;
        private System.Windows.Forms.GroupBox grbSkor;
        private System.Windows.Forms.Button vazgec;
        private System.Windows.Forms.TextBox ad;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button tamam;
        private System.Windows.Forms.GroupBox skorTahta;
        private System.Windows.Forms.Button btntamam;
        private System.Windows.Forms.ListBox lstListem;
        private System.Windows.Forms.Label label2;
    }
}

