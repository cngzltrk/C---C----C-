namespace Ort_hesap
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
            this.label1 = new System.Windows.Forms.Label();
            this.txtSayi = new System.Windows.Forms.TextBox();
            this.lsbSayilar = new System.Windows.Forms.ListBox();
            this.btnHesap = new System.Windows.Forms.Button();
            this.btnTemizle = new System.Windows.Forms.Button();
            this.btnSon = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.lblOrtalama = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.lblSapma = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Sayı gir..:";
            // 
            // txtSayi
            // 
            this.txtSayi.Location = new System.Drawing.Point(12, 54);
            this.txtSayi.Name = "txtSayi";
            this.txtSayi.Size = new System.Drawing.Size(110, 20);
            this.txtSayi.TabIndex = 1;
            this.txtSayi.TextChanged += new System.EventHandler(this.txtSayi_TextChanged);
            this.txtSayi.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtSayi_KeyPress);
            // 
            // lsbSayilar
            // 
            this.lsbSayilar.FormattingEnabled = true;
            this.lsbSayilar.IntegralHeight = false;
            this.lsbSayilar.Location = new System.Drawing.Point(12, 105);
            this.lsbSayilar.Name = "lsbSayilar";
            this.lsbSayilar.Size = new System.Drawing.Size(142, 189);
            this.lsbSayilar.TabIndex = 2;
            // 
            // btnHesap
            // 
            this.btnHesap.Location = new System.Drawing.Point(211, 24);
            this.btnHesap.Name = "btnHesap";
            this.btnHesap.Size = new System.Drawing.Size(75, 23);
            this.btnHesap.TabIndex = 3;
            this.btnHesap.Text = "Hesapla";
            this.btnHesap.UseVisualStyleBackColor = true;
            this.btnHesap.Click += new System.EventHandler(this.btnHesap_Click);
            // 
            // btnTemizle
            // 
            this.btnTemizle.Location = new System.Drawing.Point(211, 74);
            this.btnTemizle.Name = "btnTemizle";
            this.btnTemizle.Size = new System.Drawing.Size(75, 23);
            this.btnTemizle.TabIndex = 4;
            this.btnTemizle.Text = "Temizle";
            this.btnTemizle.UseVisualStyleBackColor = true;
            this.btnTemizle.Click += new System.EventHandler(this.btnTemizle_Click);
            // 
            // btnSon
            // 
            this.btnSon.Location = new System.Drawing.Point(211, 126);
            this.btnSon.Name = "btnSon";
            this.btnSon.Size = new System.Drawing.Size(75, 23);
            this.btnSon.TabIndex = 5;
            this.btnSon.Text = "Son";
            this.btnSon.UseVisualStyleBackColor = true;
            this.btnSon.Click += new System.EventHandler(this.btnSon_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(185, 178);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(43, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Ortlama";
            // 
            // lblOrtalama
            // 
            this.lblOrtalama.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblOrtalama.Location = new System.Drawing.Point(179, 207);
            this.lblOrtalama.Name = "lblOrtalama";
            this.lblOrtalama.Size = new System.Drawing.Size(100, 23);
            this.lblOrtalama.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(176, 251);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(79, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "standart sapma";
            // 
            // lblSapma
            // 
            this.lblSapma.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblSapma.Location = new System.Drawing.Point(179, 278);
            this.lblSapma.Name = "lblSapma";
            this.lblSapma.Size = new System.Drawing.Size(100, 23);
            this.lblSapma.TabIndex = 10;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(324, 322);
            this.Controls.Add(this.lblSapma);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.lblOrtalama);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btnSon);
            this.Controls.Add(this.btnTemizle);
            this.Controls.Add(this.btnHesap);
            this.Controls.Add(this.lsbSayilar);
            this.Controls.Add(this.txtSayi);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Ort hesaplama";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtSayi;
        private System.Windows.Forms.ListBox lsbSayilar;
        private System.Windows.Forms.Button btnHesap;
        private System.Windows.Forms.Button btnTemizle;
        private System.Windows.Forms.Button btnSon;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lblOrtalama;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lblSapma;
    }
}

