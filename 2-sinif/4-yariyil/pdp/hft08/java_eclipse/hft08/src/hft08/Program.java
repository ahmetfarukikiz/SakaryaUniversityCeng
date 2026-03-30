package hft08;

public class Program {
	public static void main(String[] args) {
		int []s = {100,20,50,40,70};
//		Topluluk t = new Koleksiyon(s); //topluluk türüyle sınırlandırılmış bir koleksiyon getirir.
		Koleksiyon k = new Koleksiyon(s);
		System.out.println(k);
	
		
		Topluluk t1 = new Topluluk(s);
		Topluluk t2 = new Topluluk(s);
		if(t1 == t2) System.out.println("Nesneler eşit");
		else System.out.println("Nesneler eşit değil"); //eşit değil çıkar çünkü nesne referansları eşit değil
		
		//equals'ı override edersek değer karşılaştırması yapabiliriz
		if(t1.equals(t2)) System.out.println("Nesneler eşit"); 
		else System.out.println("Nesneler eşit değil");
		
	}
}
