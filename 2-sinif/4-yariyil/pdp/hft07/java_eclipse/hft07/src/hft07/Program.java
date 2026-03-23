package hft07;

public class Program {

	public static void main(String[] args) {
		Kisi k = new Kisi("Ahmet",30,5);
		k.yemekYe(1500);
		System.out.println("isim:"+k.getIsim()+"\nKilo:"+k.getKilo());
	}

}
