namespace _2.Yarıyıl_1.Ödev
{
    partial class AnaForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AnaForm));
            yiyecekSecLabel = new Label();
            adiLabel = new Label();
            cinsiLabel = new Label();
            fiyatiLabel = new Label();
            kdvOraniLabel = new Label();
            kaloriLabel = new Label();
            yiyecekSecComboBox = new ComboBox();
            siparisMenusuListBox = new ListBox();
            siparisMenusuLabel = new Label();
            tutarTextBox = new TextBox();
            listeyeEkleButton = new Button();
            adiTextBox = new TextBox();
            cinsiTextBox = new TextBox();
            fiyatiTextBox = new TextBox();
            kdvOraniTextBox = new TextBox();
            kaloriTextBox = new TextBox();
            adiError = new ErrorProvider(components);
            cinsiError = new ErrorProvider(components);
            fiyatiError = new ErrorProvider(components);
            kdvOraniError = new ErrorProvider(components);
            kaloriError = new ErrorProvider(components);
            listedenSilButton = new Button();
            yiyecekSecError = new ErrorProvider(components);
            yazdirButton = new Button();
            butceTextBox = new TextBox();
            maxKaloriTextBox = new TextBox();
            butceLabel = new Label();
            maxKaloriLabel = new Label();
            sınırlamalarLabel = new Label();
            maxKaloriError = new ErrorProvider(components);
            butceError = new ErrorProvider(components);
            aciklamaLabel = new Label();
            ((System.ComponentModel.ISupportInitialize)adiError).BeginInit();
            ((System.ComponentModel.ISupportInitialize)cinsiError).BeginInit();
            ((System.ComponentModel.ISupportInitialize)fiyatiError).BeginInit();
            ((System.ComponentModel.ISupportInitialize)kdvOraniError).BeginInit();
            ((System.ComponentModel.ISupportInitialize)kaloriError).BeginInit();
            ((System.ComponentModel.ISupportInitialize)yiyecekSecError).BeginInit();
            ((System.ComponentModel.ISupportInitialize)maxKaloriError).BeginInit();
            ((System.ComponentModel.ISupportInitialize)butceError).BeginInit();
            SuspendLayout();
            // 
            // yiyecekSecLabel
            // 
            yiyecekSecLabel.AutoSize = true;
            yiyecekSecLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            yiyecekSecLabel.ForeColor = Color.Navy;
            yiyecekSecLabel.Location = new Point(66, 63);
            yiyecekSecLabel.Name = "yiyecekSecLabel";
            yiyecekSecLabel.Size = new Size(97, 24);
            yiyecekSecLabel.TabIndex = 0;
            yiyecekSecLabel.Text = "Yiyecek Seç";
            // 
            // adiLabel
            // 
            adiLabel.AutoSize = true;
            adiLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            adiLabel.ForeColor = Color.Navy;
            adiLabel.Location = new Point(66, 123);
            adiLabel.Name = "adiLabel";
            adiLabel.Size = new Size(36, 24);
            adiLabel.TabIndex = 1;
            adiLabel.Text = "Adı";
            // 
            // cinsiLabel
            // 
            cinsiLabel.AutoSize = true;
            cinsiLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            cinsiLabel.ForeColor = Color.Navy;
            cinsiLabel.Location = new Point(66, 187);
            cinsiLabel.Name = "cinsiLabel";
            cinsiLabel.Size = new Size(48, 24);
            cinsiLabel.TabIndex = 2;
            cinsiLabel.Text = "Cinsi";
            // 
            // fiyatiLabel
            // 
            fiyatiLabel.AutoSize = true;
            fiyatiLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            fiyatiLabel.ForeColor = Color.Navy;
            fiyatiLabel.Location = new Point(66, 254);
            fiyatiLabel.Name = "fiyatiLabel";
            fiyatiLabel.Size = new Size(54, 24);
            fiyatiLabel.TabIndex = 3;
            fiyatiLabel.Text = "Fiyatı";
            // 
            // kdvOraniLabel
            // 
            kdvOraniLabel.AutoSize = true;
            kdvOraniLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            kdvOraniLabel.ForeColor = Color.Navy;
            kdvOraniLabel.Location = new Point(66, 320);
            kdvOraniLabel.Name = "kdvOraniLabel";
            kdvOraniLabel.Size = new Size(89, 24);
            kdvOraniLabel.TabIndex = 4;
            kdvOraniLabel.Text = "Kdv Oranı";
            // 
            // kaloriLabel
            // 
            kaloriLabel.AutoSize = true;
            kaloriLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            kaloriLabel.ForeColor = Color.Navy;
            kaloriLabel.Location = new Point(66, 382);
            kaloriLabel.Name = "kaloriLabel";
            kaloriLabel.Size = new Size(57, 24);
            kaloriLabel.TabIndex = 5;
            kaloriLabel.Text = "Kalori";
            // 
            // yiyecekSecComboBox
            // 
            yiyecekSecComboBox.BackColor = Color.Lavender;
            yiyecekSecComboBox.FormattingEnabled = true;
            yiyecekSecComboBox.Items.AddRange(new object[] { "Meyve", "Salata", "Tatlı", "İçecek" });
            yiyecekSecComboBox.Location = new Point(183, 63);
            yiyecekSecComboBox.Name = "yiyecekSecComboBox";
            yiyecekSecComboBox.Size = new Size(263, 28);
            yiyecekSecComboBox.TabIndex = 6;
            yiyecekSecComboBox.SelectedIndexChanged += yiyecekSecComboBox_SelectedIndexChanged;
            // 
            // siparisMenusuListBox
            // 
            siparisMenusuListBox.BackColor = Color.Lavender;
            siparisMenusuListBox.Font = new Font("Segoe UI Semibold", 10F);
            siparisMenusuListBox.ForeColor = Color.MidnightBlue;
            siparisMenusuListBox.FormattingEnabled = true;
            siparisMenusuListBox.Location = new Point(521, 91);
            siparisMenusuListBox.Name = "siparisMenusuListBox";
            siparisMenusuListBox.Size = new Size(467, 280);
            siparisMenusuListBox.TabIndex = 12;
            // 
            // siparisMenusuLabel
            // 
            siparisMenusuLabel.AutoSize = true;
            siparisMenusuLabel.Font = new Font("Segoe UI", 12F, FontStyle.Bold);
            siparisMenusuLabel.ForeColor = Color.Navy;
            siparisMenusuLabel.Location = new Point(521, 48);
            siparisMenusuLabel.Name = "siparisMenusuLabel";
            siparisMenusuLabel.Size = new Size(156, 28);
            siparisMenusuLabel.TabIndex = 13;
            siparisMenusuLabel.Text = "Sipariş Menüsü";
            // 
            // tutarTextBox
            // 
            tutarTextBox.BackColor = Color.Lavender;
            tutarTextBox.Font = new Font("Segoe UI Emoji", 9F);
            tutarTextBox.ForeColor = Color.MidnightBlue;
            tutarTextBox.Location = new Point(521, 382);
            tutarTextBox.Name = "tutarTextBox";
            tutarTextBox.ReadOnly = true;
            tutarTextBox.Size = new Size(467, 27);
            tutarTextBox.TabIndex = 14;
            // 
            // listeyeEkleButton
            // 
            listeyeEkleButton.BackColor = Color.SteelBlue;
            listeyeEkleButton.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            listeyeEkleButton.ForeColor = SystemColors.ControlLightLight;
            listeyeEkleButton.Location = new Point(316, 426);
            listeyeEkleButton.Name = "listeyeEkleButton";
            listeyeEkleButton.Size = new Size(130, 35);
            listeyeEkleButton.TabIndex = 15;
            listeyeEkleButton.Text = "Listeye Ekle";
            listeyeEkleButton.UseVisualStyleBackColor = false;
            listeyeEkleButton.Click += ListeyeEkleButton;
            // 
            // adiTextBox
            // 
            adiTextBox.BackColor = Color.Lavender;
            adiTextBox.Location = new Point(183, 123);
            adiTextBox.Name = "adiTextBox";
            adiTextBox.ReadOnly = true;
            adiTextBox.Size = new Size(263, 27);
            adiTextBox.TabIndex = 16;
            // 
            // cinsiTextBox
            // 
            cinsiTextBox.BackColor = Color.Lavender;
            cinsiTextBox.Location = new Point(183, 187);
            cinsiTextBox.Name = "cinsiTextBox";
            cinsiTextBox.ReadOnly = true;
            cinsiTextBox.Size = new Size(263, 27);
            cinsiTextBox.TabIndex = 17;
            // 
            // fiyatiTextBox
            // 
            fiyatiTextBox.BackColor = Color.Lavender;
            fiyatiTextBox.Location = new Point(183, 254);
            fiyatiTextBox.Name = "fiyatiTextBox";
            fiyatiTextBox.ReadOnly = true;
            fiyatiTextBox.Size = new Size(263, 27);
            fiyatiTextBox.TabIndex = 18;
            // 
            // kdvOraniTextBox
            // 
            kdvOraniTextBox.BackColor = Color.Lavender;
            kdvOraniTextBox.Location = new Point(183, 320);
            kdvOraniTextBox.Name = "kdvOraniTextBox";
            kdvOraniTextBox.ReadOnly = true;
            kdvOraniTextBox.Size = new Size(263, 27);
            kdvOraniTextBox.TabIndex = 19;
            // 
            // kaloriTextBox
            // 
            kaloriTextBox.BackColor = Color.Lavender;
            kaloriTextBox.Location = new Point(183, 382);
            kaloriTextBox.Name = "kaloriTextBox";
            kaloriTextBox.ReadOnly = true;
            kaloriTextBox.Size = new Size(263, 27);
            kaloriTextBox.TabIndex = 20;
            // 
            // adiError
            // 
            adiError.BlinkStyle = ErrorBlinkStyle.NeverBlink;
            adiError.ContainerControl = this;
            // 
            // cinsiError
            // 
            cinsiError.BlinkStyle = ErrorBlinkStyle.NeverBlink;
            cinsiError.ContainerControl = this;
            // 
            // fiyatiError
            // 
            fiyatiError.BlinkStyle = ErrorBlinkStyle.NeverBlink;
            fiyatiError.ContainerControl = this;
            // 
            // kdvOraniError
            // 
            kdvOraniError.BlinkStyle = ErrorBlinkStyle.NeverBlink;
            kdvOraniError.ContainerControl = this;
            // 
            // kaloriError
            // 
            kaloriError.BlinkStyle = ErrorBlinkStyle.NeverBlink;
            kaloriError.ContainerControl = this;
            // 
            // listedenSilButton
            // 
            listedenSilButton.BackColor = Color.SteelBlue;
            listedenSilButton.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            listedenSilButton.ForeColor = Color.AliceBlue;
            listedenSilButton.Location = new Point(885, 48);
            listedenSilButton.Name = "listedenSilButton";
            listedenSilButton.Size = new Size(103, 34);
            listedenSilButton.TabIndex = 21;
            listedenSilButton.Text = "Sil";
            listedenSilButton.UseVisualStyleBackColor = false;
            listedenSilButton.Click += ListedenSilButton;
            // 
            // yiyecekSecError
            // 
            yiyecekSecError.BlinkStyle = ErrorBlinkStyle.NeverBlink;
            yiyecekSecError.ContainerControl = this;
            // 
            // yazdirButton
            // 
            yazdirButton.BackColor = Color.SteelBlue;
            yazdirButton.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            yazdirButton.ForeColor = Color.AliceBlue;
            yazdirButton.Location = new Point(752, 48);
            yazdirButton.Name = "yazdirButton";
            yazdirButton.Size = new Size(127, 34);
            yazdirButton.TabIndex = 22;
            yazdirButton.Text = "Menüyü Yazdır";
            yazdirButton.UseVisualStyleBackColor = false;
            yazdirButton.Click += yazdirButton_Click;
            // 
            // butceTextBox
            // 
            butceTextBox.BackColor = Color.Lavender;
            butceTextBox.Location = new Point(316, 556);
            butceTextBox.Name = "butceTextBox";
            butceTextBox.ReadOnly = true;
            butceTextBox.Size = new Size(130, 27);
            butceTextBox.TabIndex = 26;
            // 
            // maxKaloriTextBox
            // 
            maxKaloriTextBox.BackColor = Color.Lavender;
            maxKaloriTextBox.Location = new Point(180, 556);
            maxKaloriTextBox.Name = "maxKaloriTextBox";
            maxKaloriTextBox.ReadOnly = true;
            maxKaloriTextBox.Size = new Size(130, 27);
            maxKaloriTextBox.TabIndex = 27;
            // 
            // butceLabel
            // 
            butceLabel.AutoSize = true;
            butceLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            butceLabel.ForeColor = Color.Navy;
            butceLabel.Location = new Point(316, 529);
            butceLabel.Name = "butceLabel";
            butceLabel.Size = new Size(53, 24);
            butceLabel.TabIndex = 28;
            butceLabel.Text = "Bütçe";
            // 
            // maxKaloriLabel
            // 
            maxKaloriLabel.AutoSize = true;
            maxKaloriLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            maxKaloriLabel.ForeColor = Color.Navy;
            maxKaloriLabel.Location = new Point(180, 529);
            maxKaloriLabel.Name = "maxKaloriLabel";
            maxKaloriLabel.Size = new Size(95, 24);
            maxKaloriLabel.TabIndex = 29;
            maxKaloriLabel.Text = "Max Kalori";
            // 
            // sınırlamalarLabel
            // 
            sınırlamalarLabel.AutoSize = true;
            sınırlamalarLabel.Font = new Font("Sitka Subheading Semibold", 10F);
            sınırlamalarLabel.ForeColor = Color.Navy;
            sınırlamalarLabel.Location = new Point(66, 556);
            sınırlamalarLabel.Name = "sınırlamalarLabel";
            sınırlamalarLabel.Size = new Size(107, 24);
            sınırlamalarLabel.TabIndex = 30;
            sınırlamalarLabel.Text = "Sınırlamalar";
            // 
            // maxKaloriError
            // 
            maxKaloriError.BlinkStyle = ErrorBlinkStyle.NeverBlink;
            maxKaloriError.ContainerControl = this;
            // 
            // butceError
            // 
            butceError.BlinkStyle = ErrorBlinkStyle.NeverBlink;
            butceError.ContainerControl = this;
            // 
            // aciklamaLabel
            // 
            aciklamaLabel.AutoSize = true;
            aciklamaLabel.Font = new Font("Sitka Subheading Semibold", 11F);
            aciklamaLabel.ForeColor = Color.Navy;
            aciklamaLabel.Location = new Point(521, 468);
            aciklamaLabel.Name = "aciklamaLabel";
            aciklamaLabel.Size = new Size(497, 112);
            aciklamaLabel.TabIndex = 31;
            aciklamaLabel.Text = resources.GetString("aciklamaLabel.Text");
            // 
            // AnaForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.LightSkyBlue;
            ClientSize = new Size(1074, 641);
            Controls.Add(aciklamaLabel);
            Controls.Add(sınırlamalarLabel);
            Controls.Add(maxKaloriLabel);
            Controls.Add(butceLabel);
            Controls.Add(maxKaloriTextBox);
            Controls.Add(butceTextBox);
            Controls.Add(yazdirButton);
            Controls.Add(listedenSilButton);
            Controls.Add(kaloriTextBox);
            Controls.Add(kdvOraniTextBox);
            Controls.Add(fiyatiTextBox);
            Controls.Add(cinsiTextBox);
            Controls.Add(adiTextBox);
            Controls.Add(listeyeEkleButton);
            Controls.Add(tutarTextBox);
            Controls.Add(siparisMenusuLabel);
            Controls.Add(siparisMenusuListBox);
            Controls.Add(yiyecekSecComboBox);
            Controls.Add(kaloriLabel);
            Controls.Add(kdvOraniLabel);
            Controls.Add(fiyatiLabel);
            Controls.Add(cinsiLabel);
            Controls.Add(adiLabel);
            Controls.Add(yiyecekSecLabel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "AnaForm";
            Text = "  Yemek Menüsü";
            Load += AnaForm_Load;
            ((System.ComponentModel.ISupportInitialize)adiError).EndInit();
            ((System.ComponentModel.ISupportInitialize)cinsiError).EndInit();
            ((System.ComponentModel.ISupportInitialize)fiyatiError).EndInit();
            ((System.ComponentModel.ISupportInitialize)kdvOraniError).EndInit();
            ((System.ComponentModel.ISupportInitialize)kaloriError).EndInit();
            ((System.ComponentModel.ISupportInitialize)yiyecekSecError).EndInit();
            ((System.ComponentModel.ISupportInitialize)maxKaloriError).EndInit();
            ((System.ComponentModel.ISupportInitialize)butceError).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label yiyecekSecLabel;
        private Label adiLabel;
        private Label cinsiLabel;
        private Label fiyatiLabel;
        private Label kdvOraniLabel;
        private Label kaloriLabel;
        private ComboBox yiyecekSecComboBox;
        private ListBox siparisMenusuListBox;
        private Label siparisMenusuLabel;
        private TextBox tutarTextBox;
        private Button listeyeEkleButton;
        private TextBox adiTextBox;
        private TextBox cinsiTextBox;
        private TextBox fiyatiTextBox;
        private TextBox kdvOraniTextBox;
        private TextBox kaloriTextBox;
        private ErrorProvider adiError;
        private ErrorProvider cinsiError;
        private ErrorProvider fiyatiError;
        private ErrorProvider kdvOraniError;
        private ErrorProvider kaloriError;
        private Button listedenSilButton;
        private ErrorProvider yiyecekSecError;
        private Button yazdirButton;
        private Label maxKaloriLabel;
        private Label butceLabel;
        private TextBox maxKaloriTextBox;
        private TextBox butceTextBox;
        private Label sınırlamalarLabel;
        private ErrorProvider maxKaloriError;
        private ErrorProvider butceError;
        private Label aciklamaLabel;
    }
}
