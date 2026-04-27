package hft12;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ProgramHesapOrn {

	public static void main(String[] args) {
		Hesap yardimKasasi = new Hesap();
		ExecutorService havuz = Executors.newFixedThreadPool(5); 
		for(int i = 0; i< 100; i++) {
			havuz.execute(new ParaYatirma(yardimKasasi, 1));
		}
		havuz.shutdown();
		while(!havuz.isTerminated()) {
			
		}
		System.out.println("Toplanan Yardım Parası: " + yardimKasasi.getBakiye());
	}

}



