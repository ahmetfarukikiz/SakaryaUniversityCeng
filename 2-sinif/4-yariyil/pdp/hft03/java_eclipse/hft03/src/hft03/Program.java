package hft03;

public class Program {

	public static void main(String[] args) {
		//direkt atanmamış dizi oluşturulamaz bu şekil yapılması için heapte oluşurulmalıdır
		//int sayilar[10]; 
		int[] sayilarHeap = new int[5];
		//ya da
		int sayilarStack[] = {1,2};
		System.out.println(sayilarStack);
		
		//s Sayi nesnesinin bellek adresini döndürücek (pointer mantığı)
		Sayi s = new Sayi(500);
		System.out.println(s);
		
		//Javada her şey objectten miras alır
		double a = 10.5;
		Object obj= a;
		obj = "Sakarya"; //hata vermez.

		
		
	}

}
