#ifndef PROIECT_POO_PRODUSFOOD_H
#define PROIECT_POO_PRODUSFOOD_H

#include "Produs.h"

class ProdusFood : virtual public Produs {
protected:
    double calorii;
    bool este_bio;
    std::string alergii;

public:
    ProdusFood(int id, std::string nume, double pret, int stoc, double greutate,
               double calorii, bool este_bio, std::string alergii);
    virtual ~ProdusFood();

    double getCalorii() const;

    void afisare() const override;
    bool getBio() const;   //5.1
    std::string getAlergii() const;   //5.2
};


#endif
