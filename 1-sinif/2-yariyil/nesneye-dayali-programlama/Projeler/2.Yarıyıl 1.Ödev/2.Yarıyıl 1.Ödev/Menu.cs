using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2.Yarıyıl_1.Ödev
{

    class Menu
    {

        private List<Yiyecek> liste = new List<Yiyecek>();


        public void Ekle(Yiyecek eklenecek)

        {
            if (eklenecek == null) return;  //boş değilse listeye ekle
            liste.Add(eklenecek);
        }

        public void Sil(int silinecek) //gönderilen indexi silen method         
        {
            liste.RemoveAt(silinecek);
        }

        public List<Yiyecek> MenuYazdir()  //listeyi döndürür
        {
            return liste;
        }
    }
}
