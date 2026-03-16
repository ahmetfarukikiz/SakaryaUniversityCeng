package hft06;

public class Sayi {

	public int deger;
	private int uzunluk;
	
	public Sayi(int deger) {
		this.deger = deger;
		uzunluk = String.valueOf(deger).length();
	}
	
	public boolean asalMi(int... bolen) { //0'dan sonsuza kadar parametre sayısı yazılabilir
		if(bolen.length == 0) return asalMi(2); //başlangıç noktası
		if(deger == 1 || deger == bolen[0]) return true;
		if(deger % bolen[0] == 0) return false;
		return asalMi(bolen[0]+1);
	}
	
	public short[] rakamlar() {
		int tmp = deger;
		short[] basamaklar = new short[uzunluk];
		for(int index = uzunluk-1; tmp > 0; index--, tmp/=10) {
			basamaklar[index] = (short)(tmp%10);
		}
		return basamaklar;
	}
	
	public int getUzunluk() {
		return uzunluk;
	}
	
	public int getDeger() {
		return deger;
	}
	
	
	public int setDeger(int d) {
		return deger = d;
	}
}