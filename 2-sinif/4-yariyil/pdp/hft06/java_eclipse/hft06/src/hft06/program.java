package hft06;

import hft06prrr.Mat;


public class program {
	
	public static void degistir(Sayi s) {
		s.setDeger(400);
		System.out.println(s); //adresini bastırır.
		
		//şeklinde yapıırsa yeni bir nesne oluşturup onu s'ye atar. komple adresi değişir.
		//s = new Sayi(4000); 
	}

	public static void main(String[] args) {
		Sayi sy = new Sayi(5912);
		
		short[] rakamlar = sy.rakamlar();
		for(short s : rakamlar) {
			System.out.println(s + " ");
		}
		
		
		System.out.println(sy.getDeger());
		degistir(sy); //adres ile aktarımdır. //dolaylı değişimdir.
		System.out.println(sy.getDeger());
		
		
		if(sy.asalMi()) System.out.println("\nSayı asaldır");
		else System.out.println("\nSayı asal değildir");
		
				
		// PIdeger metodunu çağırıp sonucu değişkene atıyoruz
		double sonuc = Mat.PIdeger(1000000); 
				
		System.out.println("Hesaplanan Pi Değeri: " + sonuc);
		

	}

	
	
}
