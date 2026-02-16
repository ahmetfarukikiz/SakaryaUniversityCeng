/**
* @file Program.cpp
* @description programın çalışmasını sağlayan temel sınıfları ve fonksiyonları yönetir
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 4.12.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/


#include "Program.hpp"


Program::Program()
{
	kuyrukSayisi = kuyrukSayisiHesapla();

	kuyruklar = new Queue*[kuyrukSayisi];
	for(int i = 0; i < kuyrukSayisi; i++){ //kuyrukları boş ata
		kuyruklar[i] = new Queue();
	}
	cout << kuyrukSayisi;
}

void Program::baslat()
{
	ekraniCiz(0); //bos olarak ekran bir kere çizilsin
	dosyadanOlustur(); 
	ekraniCiz(0); //dolu olarak bir kez daha çizilsin

	cout << endl << endl << "Kac tur olacak?";
	turSayisi = kullanicidanSayiAl(true,4); //4 basamak izin veriliyor

	for(int aktifTur = 1; aktifTur <= turSayisi; aktifTur++){
		if(aktifTur % 2 != 0) tekTur();
		else ciftTur();
		ekraniCiz(aktifTur);
	}

}


void Program::tekTur()
{
	for(int i = 0; i < kuyrukSayisi; i++){
		Queue* alinanKuyruk = kuyruklar[i];
		int verilenIndex = (i + 1) % kuyrukSayisi; //sondaki başa versin
        Queue* verilenKuyruk = kuyruklar[verilenIndex];

		if (alinanKuyruk->isEmpty()) continue;

		int agacUzunlugu = alinanKuyruk->peek()->count();
		int* dagitilanVeriler = alinanKuyruk->postOrderDequeue(); //alinan kuyruktan agaci postordersilerek sök

		if (dagitilanVeriler != nullptr) {
			verilenKuyruk->verilenAgaciDagit(dagitilanVeriler, agacUzunlugu);
            delete[] dagitilanVeriler;
        }
	}


}

void Program::ciftTur()
{
	for(int i = 0; i < kuyrukSayisi; i++){
		Queue* alinanKuyruk = kuyruklar[i];
		int verilenIndex = (i + 1) % kuyrukSayisi; //sondaki başa versin
        Queue* verilenKuyruk = kuyruklar[verilenIndex];

		if (alinanKuyruk->isEmpty()) continue;

		int agacUzunlugu = 0;
		int* dagitilanVeriler = alinanKuyruk->postOrderDequeueMax(agacUzunlugu); //alinan kuyruktan agaci postordersilerek sök

		if (dagitilanVeriler != nullptr) {
			verilenKuyruk->verilenAgaciDagit(dagitilanVeriler, agacUzunlugu);
            delete[] dagitilanVeriler;
        }
	}

}

void Program::ekraniCiz(int aktifTur)
{
	system("cls");
	string ekranst;
	ekranst.reserve(kuyrukSayisi*10);

	for(int i = 0; i < kuyrukSayisi; i++)
    {
        if (kuyruklar[i]->isEmpty()) {
            ekranst += "Bos ";
        } 
        else {
            int deger = kuyruklar[i]->getEkranDegeri();
            ekranst += to_string(deger) + " ";
        }

        // Her 6 elemanda bir alt satıra geç 
        if ((i + 1) % 6 == 0) {
            ekranst += "\n";
        }
    }
	ekranst += "\n";

	if(aktifTur != 0) {
		ekranst += to_string(aktifTur) + ".tur sonu" + "\n";
    	ekranst += "\n";
	} 

    
	cout << ekranst;
}

void Program::dosyadanOlustur(){
	ifstream dosya("data.txt");
	if(!dosya.is_open()) throw "dosya acilamadi";
	
	int sayi;
	string satir;
  	int guncellemeSikligi;

	if(kuyrukSayisi > 1500) guncellemeSikligi = kuyrukSayisi / 30;
	else if(kuyrukSayisi > 800) guncellemeSikligi = kuyrukSayisi / 40;
	else guncellemeSikligi = kuyrukSayisi / 50;

    if (guncellemeSikligi < 1) {
        guncellemeSikligi = 1;
    }
	
	for (int i = 0; i < kuyrukSayisi; i++){

		for(int j = 0; j < 6; j++){ //sabit 6'lı kuyruk
			if (getline(dosya, satir)) { 
                
                // arada satır boşsa atla
                if (satir.empty()) { 
                    j--; // boş satır sayılmasın
                    continue; 
                }

                Bst* bst = new Bst();
                
                stringstream ss(satir); 
                int deger;
                while (ss >> deger) { //aradaki bosluklara göre her bi degeri alıp bst'ye ekle.
                    bst->add(deger);
                }
            
                kuyruklar[i]->enqueue(bst); 
            }
		}
		if ((i + 1) % guncellemeSikligi == 0) {
            ekraniCiz(0); 
        }
	}
	
	dosya.close();	
}

int Program::kuyrukSayisiHesapla(){
	ifstream dosya("data.txt");
	if(!dosya.is_open()) throw "dosya acilamadi";
	
	string satir;
	int sayac = 0;

	while(getline(dosya,satir)){
		if(satir != "") sayac++; //boş satırları sayma
	}

	dosya.close();

	//bazı kısımları boş olan 1 kuyruk daha olabilir
	int artikKuyruk = (sayac % 6 == 0) ? 0 : 1; 

	return sayac / 6 + artikKuyruk;
}


Program::~Program()
{
	if (kuyruklar != nullptr) {
        for(int i = 0; i < kuyrukSayisi; i++){
            if(kuyruklar[i] != nullptr){
                delete kuyruklar[i];
            }
        }
        
        delete [] kuyruklar;
    }
}