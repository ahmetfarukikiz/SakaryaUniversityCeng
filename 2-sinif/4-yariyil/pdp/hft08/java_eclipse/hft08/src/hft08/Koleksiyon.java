package hft08;

//ilk Topluluktan nesne oluşacak sonra Koleksiyondan
public class Koleksiyon extends Topluluk { //kalıtım alırken yukarı bilgi göndericek bir kurucu şarttır
	public Koleksiyon(int[] sayilar) {
		super(sayilar); //kurucu func'ın ilk satırında yukarı bilgi gönderilmelidir.
	}
	
	public double ortalama() {
		double toplam =0; 
		for(int sayi : sayilar) {
			toplam += sayi;
		}
		return toplam/sayilar.length; //protected olduğundan erişebildik
	}
	
	@Override
	public String toString() {
		return super.toString() + "\nOrtalama: " + ortalama();
	}
}
