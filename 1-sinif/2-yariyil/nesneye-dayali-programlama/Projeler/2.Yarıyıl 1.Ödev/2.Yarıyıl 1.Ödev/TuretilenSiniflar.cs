using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace _2.Yarıyıl_1.Ödev
{
    class Meyve : Yiyecek
    {
        private double _kalori;

        public double Kalori => _kalori;


        public Meyve()
        {
            _adi = "";
            _cins = "";
            _fiyat = 0;
            _kdvOrani = 0;
            _kalori = 0;
        }

        public Meyve(string adi, string cins, double fiyat, double kdvOrani, double kalori) : base(adi, cins, fiyat, kdvOrani)
        {
            _adi = adi;
            _cins = cins;
            _fiyat = fiyat;
            _kdvOrani = kdvOrani;
            _kalori = kalori;
        }

        public override string Yazdir()
        {
            return this.GetType().Name + "  " + base.Yazdir() + "   " + Kalori + "cal";
        }



    }

    class Salata : Yiyecek
    {
        public Salata()
        {
            _adi = "";
            _cins = "";
            _fiyat = 0;
            _kdvOrani = 0;
            _kalori = 0;
        }

        public Salata(string adi, string cins, double fiyat, double kdvOrani, double kalori) : base(adi, cins, fiyat, kdvOrani)
        {
            _adi = adi;
            _cins = cins;
            _fiyat = fiyat;
            _kdvOrani = kdvOrani;
            _kalori = kalori;
        }

        private double _kalori;

        public double Kalori => _kalori;



        public override string Yazdir()
        {
            return this.GetType().Name + "  " + base.Yazdir() +"   " + Kalori + "cal"; ;
        }
    }

    class Tatli : Yiyecek
    {
        public Tatli()
        {
            _adi = "";
            _cins = "";
            _fiyat = 0;
            _kdvOrani = 0;
            _kalori = 0;
        }

        public Tatli(string adi, string cins, double fiyat, double kdvOrani, double kalori) : base(adi, cins, fiyat, kdvOrani)
        {
            _adi = adi;
            _cins = cins;
            _fiyat = fiyat;
            _kdvOrani = kdvOrani;
            _kalori = kalori;
        }

        private double _kalori;

        public double Kalori => _kalori;


        public override string Yazdir()
        {
            return this.GetType().Name + "  " + base.Yazdir() + "   " + Kalori + "cal";
        }
    }

    class Icecek : Yiyecek
    {
        public Icecek()
        {
            _adi = "";
            _cins = "";
            _fiyat = 0;
            _kdvOrani = 0;
            _kalori = 0;
        }

        public Icecek(string adi, string cins, double fiyat, double kdvOrani, double kalori) : base(adi, cins, fiyat, kdvOrani)
        {
            _adi = adi;
            _cins = cins;
            _fiyat = fiyat;
            _kdvOrani = kdvOrani;
            _kalori = kalori;
        }

        private double _kalori;

        public double Kalori => _kalori;

        public override string Yazdir()
        {
            return this.GetType().Name + "  " + base.Yazdir() + "   " + Kalori + "cal";
        }
    }




}
