package hft06prrr;

import java.util.Random;

public class Mat {

	public double PIdeger(double denemeSayisi) {
		int basariliVurus = 0;
		Random rnd = new Random();
		for(double i = 0; i < denemeSayisi; i++) {
			double x = rnd.nextDouble();
			double y = rnd.nextDouble();
			double uzunluk = Math.sqrt(Math.pow(x,2) + Math.pow(y,2));
			if(uzunluk<1) basariliVurus++;
		}
		return 4*(basariliVurus/denemeSayisi);
	}
}
