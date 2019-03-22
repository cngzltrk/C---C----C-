namespace Listeleme
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
            this.lsbSecenek = new System.Windows.Forms.CheckedListBox();
            this.btnListele = new System.Windows.Forms.Button();
            this.btnSon = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lsbSiparis = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // lsbSecenek
            // 
            this.lsbSecenek.FormattingEnabled = true;
            this.lsbSecenek.Items.AddRange(new object[] {
            "AutoCad 14",
            "visual Basic .NET",
            "c#",
            "c++",
            "Java",
            "HTML5",
            "CSS",
            "jQery"});
            this.lsbSecenek.Location = new System.Drawing.Point(26, 46);
            this.lsbSecenek.Name = "lsbSecenek";
            this.lsbSecenek.Size = new System.Drawing.Size(124, 94);
            this.lsbSecenek.TabIndex = 0;
            // 
            // btnListele
            // 
            this.btnListele.Location = new System.Drawing.Point(66, 159);
            this.btnListele.Name = "btnListele";
            this.btnListele.Size = new System.Drawing.Size(75, 23);
            this.btnListele.TabIndex = 1;
            this.btnListele.Text = "Sipariş Listesi";
            this.btnListele.UseVisualStyleBackColor = true;
            this.btnListele.Click += new System.EventHandler(this.btnListele_Click);
            // 
            // btnSon
            // 
            this.btnSon.Location = new System.Drawing.Point(235, 159);
            this.btnSon.Name = "btnSon";
            this.btnSon.Size = new System.Drawing.Size(75, 23);
            this.btnSon.TabIndex = 2;
            this.btnSon.Text = "Son";
            this.btnSon.UseVisualStyleBackColor = true;
            this.btnSon.Click += new System.EventHandler(this.btnSon_Click);
            // 
            // label1
            // 
            this.label1.BackColor = System.Drawing.SystemColors.Control;
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label1.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(210, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(100, 23);
            this.label1.TabIndex = 3;
            this.label1.Text = "Sipariş Listesi";
            // 
            // label2
            // 
            this.label2.BackColor = System.Drawing.SystemColors.Control;
            this.label2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label2.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(23, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(100, 23);
            this.label2.TabIndex = 4;
            this.label2.Text = "Liste";
            // 
            // lsbSiparis
            // 
            this.lsbSiparis.FormattingEnabled = true;
            this.lsbSiparis.Location = new System.Drawing.Point(216, 46);
            this.lsbSiparis.Name = "lsbSiparis";
            this.lsbSiparis.Size = new System.Drawing.Size(120, 95);
            this.lsbSiparis.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(358, 194);
            this.Controls.Add(this.lsbSiparis);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnSon);
            this.Controls.Add(this.btnListele);
            this.Controls.Add(this.lsbSecenek);
            this.Name = "Form1";
            this.Text = "Kitap Listesi";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckedListBox lsbSecenek;
        private System.Windows.Forms.Button btnListele;
        private System.Windows.Forms.Button btnSon;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListBox lsbSiparis;
    }
}

