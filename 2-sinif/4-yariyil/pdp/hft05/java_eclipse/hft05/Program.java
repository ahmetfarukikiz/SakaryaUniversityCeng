package hft05;

import java.util.Iterator;
import java.util.Scanner;

public class Program {

	public static void main(String[] args) {
		 //ilk kısım başta 1 kez çalışır. ikinci kısım her döngüde kontrol edilir, 
		//3.kısım her döngü sonunda çalıştırılır
		int sayilar[] = {10, 20, 30 ,40 ,50};
		//int index = 0; bu şekil başa da yazılabilir
		for(int index = 0; index < 5; index++) {
			System.out.println(sayilar[index]);
		}
		
		
		for(int sayi : sayilar) {
			System.out.printf("%d\n",sayi);
		}
		
		
		int sayi;
		Scanner in = new Scanner(System.in);
		do {
			System.out.println("Pozitif Tam Sayı:");
			sayi = in.nextInt();
		}while(sayi<0);
		System.out.println("Girilen sayı pozitif tam sayıdır");
		
		
		System.out.println("Çarpım Tablosu");
		System.out.print("     ");
		for(int i = 1; i<=9; i++) System.out.print(i+"  ");
		System.out.println("\n------------------------------------------------------");
		for(int i = 1; i <= 9; i++) {
			System.out.print(i+" |");
			for(int j = 1; j<=9; j++) {
				if(i*j<10) System.out.print("  "+(i*j));
				else System.out.print(" "+(i*j));
			}
			System.out.println();
		}
		
		
		//durum etiketleri
		//bu etki c'de goto ile verilebilir
		outer:
		for(int i=1;i<=9;i++){
			inner:
			for(int j=1;j<=9;j++){
				if(i*j >= 10) break outer; //durum etiketi dıştaki döngüyü sonlandırır
				System.out.print(" " + i*j);
			}
		}
		System.out.println();
			 
		disdongu:
		for(int i=1;i<=9;i++){
			inner:
			for(int j=1;j<=9;j++){
				if(i*j >= 10) continue disdongu;
				System.out.print(" " + i*j);
			}
		}
		System.out.println();
		
		
	}

}
