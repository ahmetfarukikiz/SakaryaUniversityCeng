package hft11;

import java.io.IOException;

public class YakalanmasiZorunluHata extends IOException {
	private String mesaj;
	public YakalanmasiZorunluHata() {
		super("Hatalı Mİktar");
		this.mesaj = "Hatalı Mesaj";
	}
	
	public YakalanmasiZorunluHata(String mesaj) {
		super(mesaj);
		this.mesaj = mesaj;
	}
}




