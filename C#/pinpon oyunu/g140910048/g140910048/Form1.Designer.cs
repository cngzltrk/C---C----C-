namespace g140910048
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
            this.skorTahta = new System.Windows.Forms.Panel();
            this.sktTabela = new System.Windows.Forms.Button();
            this.lblzaman = new System.Windows.Forms.Label();
            this.yazi = new System.Windows.Forms.Label();
            this.zaman = new System.Windows.Forms.Timer(this.components);
            this.sayac = new System.Windows.Forms.Timer(this.components);
            this.skorTahta.SuspendLayout();
            this.SuspendLayout();
            // 
            // arkaTahta
            // 
            this.arkaTahta.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.arkaTahta.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.arkaTahta.Dock = System.Windows.Forms.DockStyle.Fill;
            this.arkaTahta.Location = new System.Drawing.Point(0, 0);
            this.arkaTahta.Name = "arkaTahta";
            this.arkaTahta.Size = new System.Drawing.Size(840, 412);
            this.arkaTahta.TabIndex = 0;
            this.arkaTahta.MouseClick += new System.Windows.Forms.MouseEventHandler(this.arkaTahta_MouseClick);
            this.arkaTahta.MouseMove += new System.Windows.Forms.MouseEventHandler(this.arkaTahta_MouseMove);
            // 
            // skorTahta
            // 
            this.skorTahta.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.skorTahta.Controls.Add(this.sktTabela);
            this.skorTahta.Controls.Add(this.lblzaman);
            this.skorTahta.Controls.Add(this.yazi);
            this.skorTahta.Dock = System.Windows.Forms.DockStyle.Top;
            this.skorTahta.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.skorTahta.Location = new System.Drawing.Point(0, 0);
            this.skorTahta.Name = "skorTahta";
            this.skorTahta.Size = new System.Drawing.Size(840, 36);
            this.skorTahta.TabIndex = 1;
            // 
            // sktTabela
            // 
            this.sktTabela.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.sktTabela.Font = new System.Drawing.Font("OCR A Extended", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sktTabela.Location = new System.Drawing.Point(115, 4);
            this.sktTabela.Name = "sktTabela";
            this.sktTabela.Size = new System.Drawing.Size(207, 28);
            this.sktTabela.TabIndex = 2;
            this.sktTabela.Text = "Yüksek Skorlar";
            this.sktTabela.UseVisualStyleBackColor = false;
            this.sktTabela.Click += new System.EventHandler(this.sktTabela_Click);
            // 
            // lblzaman
            // 
            this.lblzaman.AutoSize = true;
            this.lblzaman.Font = new System.Drawing.Font("OCR A Extended", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblzaman.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.lblzaman.Location = new System.Drawing.Point(12, 9);
            this.lblzaman.Name = "lblzaman";
            this.lblzaman.Size = new System.Drawing.Size(69, 20);
            this.lblzaman.TabIndex = 1;
            this.lblzaman.Text = "00:00";
            // 
            // yazi
            // 
            this.yazi.AutoSize = true;
            this.yazi.Dock = System.Windows.Forms.DockStyle.Right;
            this.yazi.Font = new System.Drawing.Font("OCR A Extended", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.yazi.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.yazi.Location = new System.Drawing.Point(498, 0);
            this.yazi.Name = "yazi";
            this.yazi.Size = new System.Drawing.Size(342, 25);
            this.yazi.TabIndex = 0;
            this.yazi.Text = "Yeni oyun için Tek tık";
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
            // AnaPencere
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(840, 412);
            this.Controls.Add(this.skorTahta);
            this.Controls.Add(this.arkaTahta);
            this.MaximumSize = new System.Drawing.Size(1980, 1050);
            this.MinimumSize = new System.Drawing.Size(730, 350);
            this.Name = "AnaPencere";
            this.Text = "Oyun";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.SizeChanged += new System.EventHandler(this.AnaPencere_SizeChanged);
            this.skorTahta.ResumeLayout(false);
            this.skorTahta.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel arkaTahta;
        private System.Windows.Forms.Panel skorTahta;
        private System.Windows.Forms.Timer zaman;
        private System.Windows.Forms.Label yazi;
        private System.Windows.Forms.Button sktTabela;
        private System.Windows.Forms.Label lblzaman;
        private System.Windows.Forms.Timer sayac;
    }
}

