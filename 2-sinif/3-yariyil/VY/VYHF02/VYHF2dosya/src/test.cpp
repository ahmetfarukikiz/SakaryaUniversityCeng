#include <iostream>
using namespace std;


class Kisi{
	private:
		string isim;
		int yas;

	public:
	
		Kisi(string isim, int yas){
			this->isim = isim;
			this->yas = yas;
		}

	 friend ostream& operator << (ostream &ekran,Kisi &sag) {
            ekran << sag.isim << " " << sag.yas << endl;
            return ekran;
        }
};

int main(){
	Kisi *ahmet = new Kisi("Ahmet",25);
	Kisi *mehmet = new Kisi("Mehmet",25);

	cout << *ahmet;
	

	return 0;
}