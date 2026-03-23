package hft07;

public class Kisi {
	private String isim;
	private int yas;
	private float boy;
	private float kilo;

	public Kisi(String isim, float boy, float kilo) {
		this.isim = isim;
		this.boy = boy;
		this.kilo = kilo;
		this.yas = 0;
	}

	private void sindirimSistemi(float kalori) {
		this.kilo += (kalori / 1000);
		if (this.yas < 20)
			this.boy++;
	}

	public void yemekYe(float kalori) {
		sindirimSistemi(kalori);
	}

	public void yaslan(int yil) {
		this.yas += yil;
	}

	public String getIsim() {
		return isim;
	}

	public float getKilo() {
		return kilo;
	}

}
