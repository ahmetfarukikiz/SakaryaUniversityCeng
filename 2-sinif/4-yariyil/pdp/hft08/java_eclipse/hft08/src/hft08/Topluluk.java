package hft08;

public class Topluluk {
	protected int[] sayilar;
	
	public Topluluk(int[] sayilar) {
		this.sayilar = new int[sayilar.length]; //direkt = sayilar yazsaydik ilk elemanın adresi gelirdi
		for(int i = 0; i < sayilar.length; i++) { //kopyalama işlemi
			this.sayilar[i] = sayilar[i];
		}
	}
	public int[] sirala() { //bubbleSort algoritması
		for(int i =0; i< sayilar.length-1; i++) {
			for(int j=1; j<sayilar.length-i;j++) {
				if(sayilar[j] < sayilar[j-1]) {
					int yedek = sayilar[j];
					sayilar[j] = sayilar[j-1];
					sayilar[j-1] = yedek;
				}
			}
			
		}
		return sayilar;
	}	
	
	@Override 
	public String toString() {
		sirala();
		String str="";
		for(int sayi : sayilar) {
			str+= sayi + " ";
		}
		return str;
	}	
	
	@Override
	public boolean equals(Object obj) {
		if(obj == null) return false;
		if(getClass() != obj.getClass()) return false;
		final Topluluk rhs = (Topluluk)obj; //üstteki kontrollerden sonra gelen prm'nin Topluluk olduğuna eminiz
		if(this.sayilar.length!= rhs.sayilar.length) return false;
		for(int i = 0; i<sayilar.length; i++) {
			if(sayilar[i] != rhs.sayilar[i]) return false;
		}
		return true;
	
	}
	
}

