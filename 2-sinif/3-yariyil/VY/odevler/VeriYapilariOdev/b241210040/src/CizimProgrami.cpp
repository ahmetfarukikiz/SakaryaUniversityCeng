/**
* @file CizimProgrami.cpp
* @description Programın hayati fonksiyonlarını ve sınıflarını yöneten ana sınıfı
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 16.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/CizimProgrami.hpp"

CizimProgrami::CizimProgrami()
{	
	_anaekran = new AnaEkran(); 
	_solmenu = new SolMenu();
	_altmenu = new AltMenu();
	_analiste  = new AnaListe();
	_canvas = new Canvas();
	_anaListItr = NULL;
	_sekilListItr = NULL;

	degisiklik = true; //en başta ana ekranı çiz
	aktifMenu = 'D'; //ilk aktif olması gereken menu D
}

CizimProgrami::~CizimProgrami()
{
	delete _anaekran;
	delete _solmenu;
	delete _altmenu;
	delete _analiste;
	delete _canvas;

	if(_anaListItr != NULL) delete _anaListItr;
	if(_sekilListItr != NULL) delete _sekilListItr;
}

void CizimProgrami::baslat()
{
	BaslangicSorusu();

	_altmenu->Guncelle(aktifMenu);
	_solmenu->Guncelle(_analiste, _anaListItr->getCurrent());
	_canvas->Guncelle(_anaListItr->getCurrent()->item);

	bool cikis = false;

	while(1){ 
	
		if(degisiklik == true) { //ekrani sadece degisiklik olursa ciz
			system("cls");  
			AnaEkraniCiz(); 
			degisiklik = false;
		} 

		if(_analiste->Size() == 0) { cout <<"Hic dugum kalmadi program sonlandiriliyor"; dosyayaYaz(); break; }

		if(aktifMenu == 'D') cikis = DugumMenu();
		else if (aktifMenu == 'S') SekilMenu();
		
		if(cikis == true) break;
	}

}

//cikisa basilirsa true doner
bool CizimProgrami::DugumMenu()
{
	switch (_getch())
	{
	case 'w':
	case 'W':
		_anaListItr->prev();
		_SekilListItrGuncelle();
		_solmenu->Guncelle(_analiste, _anaListItr->getCurrent());
		_canvas->Guncelle(_anaListItr->getCurrent()->item);

		degisiklik = true;
		break;
	
	case 's':
	case 'S':
		_anaListItr->next();
		_SekilListItrGuncelle();
		_solmenu->Guncelle(_analiste, _anaListItr->getCurrent());
		_canvas->Guncelle(_anaListItr->getCurrent()->item);

		degisiklik = true;
		break;

	case 'f':
	case 'F':
		aktifMenu = 'S';
		_altmenu->Guncelle(aktifMenu);
		degisiklik = true;
		break;

	case 'c':
	case 'C':
	{
		degisiklik = true;
		AnaDugumSil();
		
		_solmenu->Guncelle(_analiste, _anaListItr->getCurrent()); 

		if(_anaListItr->getCurrent() != NULL) _canvas->Guncelle(_anaListItr->getCurrent()->item);
		else _canvas->Guncelle(NULL); //hic dugum kalmadıysa NULL yollanır içerde temizle() çalışır return edilir.

		break;
	}

	case 'x': //cikis
	case 'X':
		dosyayaYaz(); //otomatik kaydetme
			return true;
		break;

	case 'k': //kaydetme
	case 'K':
		degisiklik =true;
		dosyayaYaz();
		cout << "Program Basariyla Kaydedildi!";
		_getch(); 
		break;
	
	
	default:
		break;
	}

	return false;

}

void CizimProgrami::SekilMenu()
{
	SekilListe* suankiSklList = _anaListItr->getCurrent()->item;
	//suanki sekil
	Sekil *sS = _sekilListItr->getCurrent()->item;
	
	switch (_getch())
	{
	case 'w':
	case 'W':
		degisiklik = true;
		sS->Yukari();
		_canvas->Guncelle(suankiSklList);
		break;

	case 'a':
	case 'A':
		degisiklik = true;
		sS->Sol();
		_canvas->Guncelle(suankiSklList);
		break;
	
	case 's':
	case 'S':
		degisiklik = true;
		sS->Asagi(_canvas->satir);
		_canvas->Guncelle(suankiSklList);
		break;

	case 'd':
	case 'D':
		degisiklik = true;
		sS->Sag(_canvas->sutun);
		_canvas->Guncelle(suankiSklList);
		break;

	case 'q':
	case 'Q':
		_sekilListItr->prev(); //bastan dolasir bi oncekine gelir
		break;

	case 'e':
	case 'E':
		_sekilListItr->next();
		
		break;

	case 'c':
	case 'C':{
		degisiklik = true;

	
		SekilDugumSil(suankiSklList);
		if(suankiSklList->IsEmpty()) {
			AnaDugumSil(); 
			aktifMenu = 'D';
			_altmenu->Guncelle(aktifMenu);
		}
		
		
		
		_solmenu->Guncelle(_analiste, _anaListItr->getCurrent());
		
		if(_anaListItr->getCurrent() != NULL) _canvas->Guncelle(_anaListItr->getCurrent()->item);
		else _canvas->Guncelle(NULL); //hic dugum kalmadıysa NULL yollanır içerde temizle() çalışır return edilir.

		break;
	}
	case 'g':
	case 'G':
		aktifMenu = 'D';
		_altmenu->Guncelle(aktifMenu);
		degisiklik = true;
		break;


	default:
		break;
	}
}

void CizimProgrami::AnaEkraniCiz() 
{
	if(_canvas == NULL || _solmenu == NULL || _altmenu == NULL || _anaekran == NULL) return;
	
	_anaekran->Entegre(_canvas, _solmenu, _altmenu);
	
    cout << _anaekran; //özel operatör içerisinde ekranı stringe atayıp cout ile basıyor.
}


void CizimProgrami::BaslangicSorusu(){
	bool devam = true;
	while (devam) {
		system("cls");

		cout << "dosyadan oku (1), rastgele olustur (2)" << endl;
		switch (_getch()) {
		case '1':
		 	devam = dosyadanOku();
			break;

		case '2':
			devam = rastgeleOlustur();
			break;

		default:
			break;
		}

	}
}

//her anadüğümü ve her anadüğüm içindeki her şekil düğümü iç içe döngüyle dolaşır
//2 adet iteratör kullanır. 
void CizimProgrami::dosyayaYaz() 
{

	ofstream dosya("programdata.txt", ios::out | ios::trunc);

    if (!dosya.is_open()) return;

	//AnaDugum sayısını yazıyorum ki okurken kolaylaşsın
	dosya << _analiste->Size() << endl;

	//Her iki liste için yeni itr oluşturdum çünkü önceki iteratörlerin bozulmaması gerek
    AnaListe::Iterator* gecAnaListItr = new AnaListe::Iterator(_analiste->GetIterator());

    // Ana Liste Döngüsü
    while (gecAnaListItr->getCurrent() != NULL) // Liste bitene kadar
    {
        SekilListe* aktifSekilListesi = gecAnaListItr->getCurrent()->item;
		
		dosya << "ANADUGUM" << " " 						// Her Ana Düğüm için başlık
			  << aktifSekilListesi->Size() << endl; 	//İçinde kaç düğüm tutulduğu

		//Sekil Liste iteratörü
        SekilListe::Iterator* gecsklListItr = new SekilListe::Iterator(aktifSekilListesi->GetIterator());

        // Şekil Liste Döngüsü
        while (gecsklListItr->getCurrent() != NULL)
        {
            Sekil* s = gecsklListItr->getCurrent()->item;

			// Tür GEN YUK X Y Z Char şeklinde yazılır
            dosya << s->GetType() << " " 
                  << s->GetGen() << " " 
                  << s->GetYuk() << " " 
                  << s->GetX() << " " 
                  << s->GetY() << " " 
                  << s->GetZ() << " " 
                  << s->GetKar() << endl;

            if (gecsklListItr->hasNext()) {gecsklListItr->next();}
            else break;
        }
        delete gecsklListItr; 

        if (gecAnaListItr->hasNext()) {gecAnaListItr->next();}
		//iteratörün hasNext'i sonraki eleman NULL'sa ilerletmeyeceğinden ve while koşulu NULL olması olduğundan break ile çıkıyoruz
        else break; 
    }
    delete gecAnaListItr;

    dosya.close();
}

bool CizimProgrami::dosyadanOku() 
{	
	ifstream dosya("programdata.txt");

    if (!dosya.is_open()) {
		cout << "Dosya hic olusturulmadi veya dugum verisi yok" << endl;
		cout << "Once rastgele dugum olusturup tekrar deneyin" << endl;
        cout << "Devam etmek icin bir tusa basin...";
        _getch();
        return true; // dosya yok döngüye devam
    }

	dosya >> AnaDugumSayisi; //ilk satır
	if(AnaDugumSayisi == 0) {
		cout << endl << "Dosyada dugum verisi yok" << endl;
		cout << "Rastgele dugum olusturup tekrar deneyin" << endl;
        cout << "Devam etmek icin bir tusa basin...";
        _getch();
		return true; //veri yok döngüye devam
	}

	for(int i = 0; i < AnaDugumSayisi; i++){
		string etiket;
        int sekilSayisi = 0;
		dosya >> etiket; 
		if(etiket != "ANADUGUM") continue; //eğer sırada okunacak veri ANADUGUM değilse atla
		dosya >> sekilSayisi;
	
		SekilListe* skllist = new SekilListe();
		skllist->DosyadanSekilOlustur(dosya,sekilSayisi);
		_analiste->Add(skllist);
	}

    dosya.close();
    
    if (_anaListItr != NULL) delete _anaListItr; //itr null degilse sil bastan olustur
	_anaListItr = new AnaListe::Iterator(_analiste->GetIterator());
	_SekilListItrGuncelle();

    return false; // döngü devam etmesin program başlasın.
}

bool CizimProgrami::rastgeleOlustur()
{
	AnaDugumSayisi = 20;
	
	for(int i = 0; i < AnaDugumSayisi; i++){ //20 adet SekilListesi olusturur icine 2-7 arasi sekil olusturur.
		SekilListe* skllist = new SekilListe();
		skllist->RastgeleSekilOlustur(rastgele(2,7), _canvas->satir, _canvas->sutun);
		_analiste->Add(skllist);
	}


	if (_anaListItr != NULL) delete _anaListItr; //itr null degilse sil bastan olustur
	_anaListItr = new AnaListe::Iterator(_analiste->GetIterator());


	_SekilListItrGuncelle();

	return false; //başlangıç sorusu tekrar sorulmasın, program başlasın
}


void CizimProgrami::AnaDugumSil()
{
	AnaDugum* silinecekDugum = _anaListItr->getCurrent();
		if (silinecekDugum != NULL) {

			if (_anaListItr->hasNext()) {
				_anaListItr->next(); 
				_SekilListItrGuncelle();
				_analiste->Remove(silinecekDugum->item); 
			}
			else if (_anaListItr->hasPrev()) {
				_anaListItr->prev();
				_SekilListItrGuncelle();
				_analiste->Remove(silinecekDugum->item);
			}
			else {
				_analiste->Remove(silinecekDugum->item);
				delete _anaListItr;
				_anaListItr = new AnaListe::Iterator(_analiste->GetIterator());
			}
		}
}

void CizimProgrami::SekilDugumSil(SekilListe* suankiSklList)
{
	SekilDugum* silinecekDugum = _sekilListItr->getCurrent();
		if (silinecekDugum != NULL) {
			//varsa bir sonraki şekile atla
			if (_sekilListItr->hasNext()) { 
				_sekilListItr->next(); 
				suankiSklList->Remove(silinecekDugum->item); 
			}
			//varsa bir önceki şekile atla 
			else if (_sekilListItr->hasPrev()) { 
				_sekilListItr->prev(); 
				suankiSklList->Remove(silinecekDugum->item); 
			}
			 //şekil kalmadıysa iteratörü sil tekrar olustur.
			else {
				suankiSklList->Remove(silinecekDugum->item);
				delete _sekilListItr;
				_sekilListItr = new SekilListe::Iterator(suankiSklList->GetIterator());
			}
		}

}


void CizimProgrami::_SekilListItrGuncelle(){
	if(_sekilListItr!= NULL) delete _sekilListItr;
	SekilListe* suankiSklList = _anaListItr->getCurrent()->item;
	_sekilListItr = new SekilListe::Iterator(suankiSklList->GetIterator());
}

