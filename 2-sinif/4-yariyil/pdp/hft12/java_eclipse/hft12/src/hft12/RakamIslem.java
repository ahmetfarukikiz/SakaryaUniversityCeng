package hft12;

public class RakamIslem implements Runnable {
	private int sonSayi;
	public RakamIslem(int sonSayi) {
		this.sonSayi = sonSayi;
	}
	
	@Override
	public void run() {
		for(int i= 1; i <= sonSayi; i++) {
//			try {
//				Thread.sleep(1);
//			} catch (InterruptedException e) {
//				e.printStackTrace();
//			}
			System.out.print(i);
		}
		
	}

	
}
