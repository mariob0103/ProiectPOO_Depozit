#ifndef PROIECT_POO_PICKER_H
#define PROIECT_POO_PICKER_H

#include "Angajat.h"

class Picker : public Angajat{
private:
    int comenzi_finalizate;
    double rata_eroare;

public:
    Picker(std::string nume, std::string cnp, std::string adresa, int varsta,
           int id, double salariu, std::string data_angajare, int ore_lucru,
           int comenzi_finalizate, double rata_eroare);
    ~Picker();

    int getComenziFinalizate() const;
    double getRataEroare() const;

    double calcul_salariu() const override;   //1.3
};


#endif
