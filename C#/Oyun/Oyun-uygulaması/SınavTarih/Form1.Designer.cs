namespace SınavTarih
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
            this.lsbListe = new System.Windows.Forms.ListBox();
            this.cbbDers = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.dtpZaman = new System.Windows.Forms.DateTimePicker();
            this.SuspendLayout();
            // 
            // lsbListe
            // 
            this.lsbListe.FormattingEnabled = true;
            this.lsbListe.Location = new System.Drawing.Point(27, 127);
            this.lsbListe.Name = "lsbListe";
            this.lsbListe.Size = new System.Drawing.Size(214, 95);
            this.lsbListe.TabIndex = 0;
            // 
            // cbbDers
            // 
            this.cbbDers.FormattingEnabled = true;
            this.cbbDers.Items.AddRange(new object[] {
            "Mat",
            "Nesne programlama",
            "html"});
            this.cbbDers.Location = new System.Drawing.Point(97, 23);
            this.cbbDers.Name = "cbbDers";
            this.cbbDers.Size = new System.Drawing.Size(121, 21);
            this.cbbDers.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(40, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Dersler";
            // 
            // dtpZaman
            // 
            this.dtpZaman.Location = new System.Drawing.Point(27, 75);
            this.dtpZaman.MaxDate = new System.DateTime(2016, 4, 30, 0, 0, 0, 0);
            this.dtpZaman.MinDate = new System.DateTime(2016, 4, 1, 0, 0, 0, 0);
            this.dtpZaman.Name = "dtpZaman";
            this.dtpZaman.Size = new System.Drawing.Size(200, 20);
            this.dtpZaman.TabIndex = 3;
            this.dtpZaman.Value = new System.DateTime(2016, 4, 29, 0, 0, 0, 0);
            this.dtpZaman.ValueChanged += new System.EventHandler(this.dateTimePicker1_ValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(275, 238);
            this.Controls.Add(this.dtpZaman);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cbbDers);
            this.Controls.Add(this.lsbListe);
            this.Name = "Form1";
            this.Text = "Sınav Tarihleri";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox lsbListe;
        private System.Windows.Forms.ComboBox cbbDers;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DateTimePicker dtpZaman;
    }
}

