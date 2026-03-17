using System.Net.Quic;
using System.Security.Cryptography.X509Certificates;

namespace _2.Yarıyıl_1.Ödev
{

    public partial class AnaForm : Form
    {
        private double maxKalori;
        private double butce;

        private Yiyecek s;
        private Menu m = new();

        public AnaForm()
        {
            s = new();
            InitializeComponent();
        }

        private void ListeyeEkleButton(object sender, EventArgs e)
        {
            if (yiyecekSecComboBox.SelectedItem == null) { MessageBox.Show("Lütfen bir yiyecek türü seçin", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning); return; } //henüz yiyecek seç kısmında bir eleman seçilmediyse bu button çalışmaz.

            if (!GirisGecerliMi()) return; //geçersizse çalıştırma

            double.TryParse(butceTextBox.Text, out butce);
            double.TryParse(maxKaloriTextBox.Text, out maxKalori);


            if (butce < TutarHesaplayici() + Convert.ToDouble(fiyatiTextBox.Text)) { MessageBox.Show("Butce Sınırı Aşılmıştır!", "Ekleme Başarısız", MessageBoxButtons.OK, MessageBoxIcon.Warning); return; }
            if (maxKalori < ToplamKaloriHesaplayici() + Convert.ToDouble(kaloriTextBox.Text)) { MessageBox.Show("Kalori Sınırı Aşılmıştır!", "Ekleme Başarısız", MessageBoxButtons.OK, MessageBoxIcon.Warning); return; }

            s = YiyecekAtama();

            m.Ekle(s);

            MessageBox.Show($"{s.Adi} Başarıyla listeye eklendi. Tüm listeyi ekranda görmek için Menüyü Yazdır butonuna basınız", "Bilgilendirme", MessageBoxButtons.OK, MessageBoxIcon.Information);



        }

        private void yazdirButton_Click(object sender, EventArgs e)
        {
            if (m.MenuYazdir().Count == 0) { MessageBox.Show("Menüye yazdırmadan önce listeye bir şeyler ekleyin", "Liste Boş", MessageBoxButtons.OK, MessageBoxIcon.Error); return; }

            siparisMenusuListBox.Items.Clear();
            foreach (var yemek in m.MenuYazdir())
            {
                siparisMenusuListBox.Items.Add(yemek.Yazdir());
            }

            tutarTextBox.Text = Convert.ToString(Math.Round(TutarHesaplayici(), 2)) + "TL" + "    " + Convert.ToString(Math.Round(ToplamKaloriHesaplayici(), 2) + "cal");

        }

        private void ListedenSilButton(object sender, EventArgs e)
        {
            if (siparisMenusuListBox.SelectedItem == null) { MessageBox.Show("Silmek için bir eleman seçin", "Silinemedi", MessageBoxButtons.OK, MessageBoxIcon.Warning); return; }
            var silinecekIndex = siparisMenusuListBox.SelectedIndex;
            siparisMenusuListBox.Items.RemoveAt(silinecekIndex);
            m.Sil(silinecekIndex);

            tutarTextBox.Text = Convert.ToString(Math.Round(TutarHesaplayici(), 2)) + "TL" + "    " + Convert.ToString(Math.Round(ToplamKaloriHesaplayici(), 2) + "cal");

        }


        private Yiyecek YiyecekAtama()
        {
            string adi = adiTextBox.Text;
            string cins = cinsiTextBox.Text;
            double fiyat; double.TryParse(fiyatiTextBox.Text, out fiyat);
            double kdvOrani; double.TryParse(kdvOraniTextBox.Text, out kdvOrani);
            double kalori; double.TryParse(kaloriTextBox.Text, out kalori);

            return yiyecekSecComboBox.SelectedIndex switch
            {
                0 => new Meyve(adi, cins, fiyat, kdvOrani, kalori),
                1 => new Salata(adi, cins, fiyat, kdvOrani, kalori),
                2 => new Tatli(adi, cins, fiyat, kdvOrani, kalori),
                3 => new Icecek(adi, cins, fiyat, kdvOrani, kalori),
                _ => throw new ArgumentException("Lütfen geçerli bir yiyecek türü seçiniz") //gereksiz çünkü bir index seçilmeden buraya ulaşılamaz 
            };
        }

        private bool GirisGecerliMi() //girilen değerlerde sıkıntı var mı kontrol eden method 
        {
            bool hataVarMi = false;

            if (string.IsNullOrWhiteSpace(adiTextBox.Text))
            {
                adiError.SetError(adiTextBox, "Bu kısım boş bırakılamaz");
                hataVarMi = true;
            }
            else adiError.Clear();


            if (string.IsNullOrWhiteSpace(cinsiTextBox.Text))
            {
                cinsiError.SetError(cinsiTextBox, "Bu kısım boş bırakılamaz");
                hataVarMi = true;
            }
            else cinsiError.Clear();


            if (!double.TryParse(fiyatiTextBox.Text, out double fiyat) || fiyat < 0)
            {
                fiyatiError.SetError(fiyatiTextBox, "0'dan büyük bir sayı değeri giriniz");
                hataVarMi = true;
            }
            else fiyatiError.Clear();


            if (!double.TryParse(kdvOraniTextBox.Text, out double kdvOrani) || kdvOrani < 0 || kdvOrani > 100)
            {
                kdvOraniError.SetError(kdvOraniTextBox, "Yüzde cinsinden bir sayı giriniz (0-100 arası)");
                hataVarMi = true;
            }
            else kdvOraniError.Clear();


            if (!double.TryParse(kaloriTextBox.Text, out double kalori) || kalori < 0)
            {
                kaloriError.SetError(kaloriTextBox, "0'dan büyük bir sayı değeri giriniz");
                hataVarMi = true;
            }
            else kaloriError.Clear();

            if (!double.TryParse(butceTextBox.Text, out double butce) || butce < 0)
            {
                butceError.SetError(butceTextBox, "0'dan büyük bir sayı değeri giriniz");
                hataVarMi = true;
            }
            else butceError.Clear();

            if (!double.TryParse(maxKaloriTextBox.Text, out double maxKalori) || maxKalori < 0)
            {
                maxKaloriError.SetError(maxKaloriTextBox, "0'dan büyük bir sayı değeri giriniz");
                hataVarMi = true;
            }
            else maxKaloriError.Clear();


            if (hataVarMi == true) return false;  //üstteki iflerde bir sorun çıktıysa false yani "geçersiz" döndürür

            return true; //bir sorun yoksa true yani "geçerli" döndürür
        }

        private void yiyecekSecComboBox_SelectedIndexChanged(object sender, EventArgs e) //bir item seçildiğinde readOnlyleri kapatan method
        {
            if (yiyecekSecComboBox.SelectedItem != null)
            {
                adiTextBox.ReadOnly = false;
                cinsiTextBox.ReadOnly = false;
                fiyatiTextBox.ReadOnly = false;
                kdvOraniTextBox.ReadOnly = false;
                kaloriTextBox.ReadOnly = false;
                maxKaloriTextBox.ReadOnly = false;
                butceTextBox.ReadOnly = false;
                //başka bir yiyecek türüne geçildiğinde textBox.Text'ler sıfırlanıyor
                adiTextBox.Text = "";
                cinsiTextBox.Text = "";
                fiyatiTextBox.Text = "";
                kdvOraniTextBox.Text = "";
                kaloriTextBox.Text = "";
            }
        }




        private double TutarHesaplayici()
        {

            double tutar = 0;

            foreach (var yemek in m.MenuYazdir())
            {
                tutar += yemek.Fiyat * (1 + yemek.KdvOrani / 100);
            }

            return tutar;
        }

        private double ToplamKaloriHesaplayici()
        {
            double toplamKalori = 0;

            foreach (var yemek in m.MenuYazdir())
            {
                switch (yemek)
                {
                    case Icecek icecek:
                        toplamKalori += icecek.Kalori;
                        break;
                    case Tatli tatli:
                        toplamKalori += tatli.Kalori;
                        break;
                    case Salata salata:
                        toplamKalori += salata.Kalori;
                        break;
                    case Meyve meyve:
                        toplamKalori += meyve.Kalori;
                        break;
                    default: break;
                }
            }

            return toplamKalori;
        }

        private void AnaForm_Load(object sender, EventArgs e)
        {

        }

    }
}
