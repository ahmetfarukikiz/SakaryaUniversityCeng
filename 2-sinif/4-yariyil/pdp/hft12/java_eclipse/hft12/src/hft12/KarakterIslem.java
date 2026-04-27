package hft12;

// thread'e atanabilir bir sınıf olması için runnable arayüzü implement edilir.
public class KarakterIslem implements Runnable {
	private char karakter;
	private int sayac;
	
	public KarakterIslem(char karakter, int sayac) {
		this.karakter = karakter;
		this.sayac = sayac;
	}

	
	// run bir veya birden çok thread tarafından gerçekleştirilebilir
	@Override
	public void run() {
		//karakterleri ekrana bas
		for(int i = 0; i< sayac; i++) {
			System.out.print(karakter);
		}
		
	}
	
	
}
