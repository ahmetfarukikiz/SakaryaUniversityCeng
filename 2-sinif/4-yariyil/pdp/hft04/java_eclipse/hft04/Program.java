package hft04;

import java.util.Scanner;

public class Program {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		
		int secenek = in.nextInt();
		switch (secenek) {
		case 1:  //break kullanılmazsa girdiği caseten durmadan aşağıya doğru tüm caseleri gerçekleştirir.
			System.out.println("1.secenek");
			break;
		case 2: {
			System.out.println("2.secenek");
			//return; //erişilemeyen satır hatasına sebep verir
			break;
		}
		case 3: case 4:
			System.out.println("3 veya 4 gelirse çalıştır");
			break;
		default:
			System.out.println("desteklenmeyen secenek");
		}
		
		int secenekk = in.nextInt();
		String sonuc;
		
		//koşullu atama örneği
		sonuc = secenekk % 2 == 0 ? "Sayı Çift" : "Sayı Tek";
		
		if(secenekk%2 == 0) { //yukarıdakiyle aynı işi yapar
			sonuc = "Sayı Çift";
		}
		else {
			sonuc = "Sayı Tek";
		}
		
		System.out.println(sonuc);

	}

}
