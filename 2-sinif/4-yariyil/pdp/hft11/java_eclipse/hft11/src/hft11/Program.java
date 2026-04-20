package hft11;

public class Program {

	public static void main(String[] args) {
		Hesap hesap = new Hesap();

		try {
			hesap.paraYatir(5000);
			hesap.paraCek(500);	
		} 
		catch (ArithmeticException e) {
			System.out.println(e.getMessage());
		} 
		catch (IllegalArgumentException e) {
			System.out.println(e.getMessage());
		}
		catch (YakalanmasiZorunluHata e) {
			System.out.println(e.getMessage());
		}

		System.out.println(hesap);
	}

}



