#ifndef DIKDORTGEN_HPP
#define DIKDORTGEN_HPP

#include "Sekil.hpp"

class Dikdortgen : public Sekil{
    public:
        Dikdortgen(int gen, int yuk, int x, int y, int z, char k);
        ~Dikdortgen();
        void Cizdir() override;
        char GetType() override;

};

#endif