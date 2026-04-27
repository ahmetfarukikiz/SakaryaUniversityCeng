package hft12;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class Program {

	public static void main(String[] args) {
		ExecutorService havuz = Executors.newFixedThreadPool(3); // 3 thread 3 ü de atılan işlerde çalışabilir.
		havuz.execute(new KarakterIslem('a',100));
		havuz.execute(new KarakterIslem('b',100));
		havuz.execute(new RakamIslem(100));
		
/*			
 *  
 *  	//eski örnek
		// burası seri olmalı çünkü burası işlem tanımlama yeri.
		KarakterIslem aYaz = new KarakterIslem('a', 100);
		KarakterIslem bYaz = new KarakterIslem('b', 100);
		RakamIslem rakamIslem = new RakamIslem(100);
		
		// her thread oluşturulurken görevleri bellidir ve bu satırlar da seridir.
		Thread thread1 = new Thread(aYaz);
		Thread thread2 = new Thread(bYaz);
		Thread thread3 = new Thread(rakamIslem);
		
		//paralel mantık burdan sonra artık hangisinin önce biteceği belli değildir.
		thread1.start();
		thread2.start();
		thread3.start();
		
		while(thread1.isAlive() || thread2.isAlive() || thread3.isAlive()) {
			// ana thread'i oyalıyoruz.
		}
		
*/	
		
		havuz.shutdown(); // ana threadte bu yazılsa dahi aslında işlemler bitene kadar devam eder sonra kapanır havuz.
		
		while(!havuz.isTerminated()) {
			//işlemler bitmediyse ana thread'i oyala
		}
		
		System.out.println("tüm işlemler kesin olarak bitti.");

	}

}


