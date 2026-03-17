#ifndef UCGEN_HPP
#define UCGEN_HPP

#include "Sekil.hpp"

class Ucgen : public Sekil{
    public:
        Ucgen(int gen, int yuk, int x, int y, int z, char k);
        ~Ucgen();
        void Cizdir() override;
        char GetType() override;

};

#endif