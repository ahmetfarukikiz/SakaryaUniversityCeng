package hft11;

public class Hesap {
	private double bakiye;

	public Hesap() {
		bakiye = 0;
	}

	public void paraYatir(double miktar) throws YakalanmasiZorunluHata {
		if (miktar <= 0)
			throw new YakalanmasiZorunluHata();
		bakiye += miktar;
	}

	public void paraCek(double miktar) {
		if (miktar <= 0 || miktar > bakiye) {
			throw new ArithmeticException("Hatalı Miktar");
		}
		bakiye -= miktar;
	}
	
	@Override
	public String toString() {
		return "Bakiye " + bakiye;
	}
}

