package hft12;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

//hesapta veriler tutulduğu için asıl işlem yapılan sınıf değildir runnable imp mantıksız olur.
//ParaYatirma diye ayrı bir sınıf yapıcaz
public class Hesap {
	private int bakiye;
	private final Lock bolge;
	public Hesap() {
		bolge = new ReentrantLock();
		bakiye = 0;
	}
	
	// bolge.lock ve unlock() ile burayı kritik bölge belirleyip 
	public void paraYatir(int miktar) {
		bolge.lock();
		int yeniToplam = bakiye + miktar;
		try {
			Thread.sleep(1);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		bakiye = yeniToplam;
		bolge.unlock();
	}
	
	public int getBakiye() {
		return bakiye;
	}
}







