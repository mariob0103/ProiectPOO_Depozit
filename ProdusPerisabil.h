#ifndef PROIECT_POO_PRODUSPERISABIL_H
#define PROIECT_POO_PRODUSPERISABIL_H

#include "ProdusFood.h"

class ProdusPerisabil: public ProdusFood {
private:
    std::string data_expirare;
    double temperatura_depozitare;

public:
    ProdusPerisabil(int id, std::string nume, double pret, int stoc, double greutate,
                    double calorii, bool este_bio, std::string alergii,
                    std::string data_expirare, double temperatura_depozitare);
    ~ProdusPerisabil();

    void afisare() const override;
    std::string getDataExpirare() const;   //2.2
    double getTemperaturaDepozitare() const;
};


#endif
