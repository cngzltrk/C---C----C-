namespace Tatil_Günleri
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
            this.cbbResmi = new System.Windows.Forms.ComboBox();
            this.mtcGun = new System.Windows.Forms.MonthCalendar();
            this.lsbTatil = new System.Windows.Forms.ListBox();
            this.btnEkle = new System.Windows.Forms.Button();
            this.btnCık = new System.Windows.Forms.Button();
            this.btnSon = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(26, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(59, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Resmi Tatil";
            // 
            // cbbResmi
            // 
            this.cbbResmi.FormattingEnabled = true;
            this.cbbResmi.Items.AddRange(new object[] {
            "Ramazan Bayramı",
            "kurban bayramı"});
            this.cbbResmi.Location = new System.Drawing.Point(12, 45);
            this.cbbResmi.Name = "cbbResmi";
            this.cbbResmi.Size = new System.Drawing.Size(121, 21);
            this.cbbResmi.TabIndex = 1;
            // 
            // mtcGun
            // 
            this.mtcGun.Location = new System.Drawing.Point(12, 97);
            this.mtcGun.Name = "mtcGun";
            this.mtcGun.TabIndex = 2;
            // 
            // lsbTatil
            // 
            this.lsbTatil.FormattingEnabled = true;
            this.lsbTatil.Location = new System.Drawing.Point(345, 45);
            this.lsbTatil.Name = "lsbTatil";
            this.lsbTatil.Size = new System.Drawing.Size(170, 186);
            this.lsbTatil.TabIndex = 3;
            // 
            // btnEkle
            // 
            this.btnEkle.Location = new System.Drawing.Point(258, 43);
            this.btnEkle.Name = "btnEkle";
            this.btnEkle.Size = new System.Drawing.Size(75, 23);
            this.btnEkle.TabIndex = 4;
            this.btnEkle.Text = "Ekle";
            this.btnEkle.UseVisualStyleBackColor = true;
            this.btnEkle.Click += new System.EventHandler(this.btnEkle_Click);
            // 
            // btnCık
            // 
            this.btnCık.Location = new System.Drawing.Point(258, 97);
            this.btnCık.Name = "btnCık";
            this.btnCık.Size = new System.Drawing.Size(75, 23);
            this.btnCık.TabIndex = 5;
            this.btnCık.Text = "Çıkar";
            this.btnCık.UseVisualStyleBackColor = true;
            this.btnCık.Click += new System.EventHandler(this.btnCık_Click);
            // 
            // btnSon
            // 
            this.btnSon.Location = new System.Drawing.Point(258, 158);
            this.btnSon.Name = "btnSon";
            this.btnSon.Size = new System.Drawing.Size(75, 23);
            this.btnSon.TabIndex = 6;
            this.btnSon.Text = "Çık";
            this.btnSon.UseVisualStyleBackColor = true;
            this.btnSon.Click += new System.EventHandler(this.btnSon_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(386, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Resmi Tatil";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(527, 261);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btnSon);
            this.Controls.Add(this.btnCık);
            this.Controls.Add(this.btnEkle);
            this.Controls.Add(this.lsbTatil);
            this.Controls.Add(this.mtcGun);
            this.Controls.Add(this.cbbResmi);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cbbResmi;
        private System.Windows.Forms.MonthCalendar mtcGun;
        private System.Windows.Forms.ListBox lsbTatil;
        private System.Windows.Forms.Button btnEkle;
        private System.Windows.Forms.Button btnCık;
        private System.Windows.Forms.Button btnSon;
        private System.Windows.Forms.Label label2;
    }
}

