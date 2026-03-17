#ifndef YILDIZ_HPP
#define YILDIZ_HPP

#include "Sekil.hpp"

class Yildiz : public Sekil{
    public:
        Yildiz(int gen, int yuk, int x, int y, int z, char k);
        ~Yildiz();
        void Cizdir() override;
        char GetType() override;
};

#endif