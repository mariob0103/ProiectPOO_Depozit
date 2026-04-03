#ifndef PROIECT_POO_PRODUSFRAGIL_H
#define PROIECT_POO_PRODUSFRAGIL_H

#include "ProdusFood.h"
#include "ProdusNonFood.h"

class ProdusFragil: public ProdusFood, public ProdusNonFood{
private:
    std::string instructiuni_manipulare;
    double cost_asigurare;

public:
    ProdusFragil(int id, std::string nume, double pret, int stoc, double greutate,
                 double calorii, bool este_bio, std::string alergii,
                 std::string material, int garantie_luni,
                 std::string instructiuni_manipulare, double cost_asigurare);
    ~ProdusFragil();

    void afisare() const override;
    std::string getInstructiuniManipulare() const;
    double getCostAsigurare() const;
    double cost_produs() const override;    //1.2
};


#endif
