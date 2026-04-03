#ifndef PROIECT_POO_PRODUSNONFOOD_H
#define PROIECT_POO_PRODUSNONFOOD_H

#include "Produs.h"

class ProdusNonFood :virtual public Produs{
protected:
    std::string material;
    int garantie_luni;

public:
    ProdusNonFood(int id, std::string nume, double pret, int stoc, double greutate,
                  std::string material, int garantie_luni);
    virtual ~ProdusNonFood();

    void afisare() const override;
    int getGarantie() const;
    std::string getMaterial() const;
};


#endif
