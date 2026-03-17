using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2.Yarıyıl_1.Ödev
{
    class Yiyecek
    {
        #region fields
        protected string _adi;
        protected string _cins;
        protected double _fiyat;
        protected double _kdvOrani;
        #endregion

        public Yiyecek() //sıfırlayan kurucu
        {
            _adi = "";
            _cins = "";
            _fiyat = 0;
            _kdvOrani = 0;
        }

        public Yiyecek(string adi, string cins, double fiyat, double kdvOrani) //parametreli kurucu
        {
            _adi = adi;
            _cins = cins;
            _fiyat = fiyat;
            _kdvOrani = kdvOrani;
        }

        public virtual string Yazdir()
        {
            String data = String.Format("{0,-10} {1,-10} {2,10}  %{3, 3} ",
            _adi, _cins, _fiyat, _kdvOrani);

            return data;
        }

        #region property
        public string Adi => _adi;

        public string Cins => _cins;

        public double Fiyat => _fiyat;

        public double KdvOrani => _kdvOrani;
        #endregion


    }
}
