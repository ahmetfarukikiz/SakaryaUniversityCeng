#include <iostream>
#include "Ogrenci.hpp"

using namespace std;

Ogrenci::Ogrenci() : _yas(5), _boy(170) {}  // default değerler

int Ogrenci::GetYas() {
    return _yas;
}

int Ogrenci::GetBoy() {
    return _boy;
}