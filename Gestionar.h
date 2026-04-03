#ifndef PROIECT_POO_GESTIONAR_H
#define PROIECT_POO_GESTIONAR_H

#include "Angajat.h"

class Gestionar : public Angajat {
private:
    int nr_comenzi;
    std::string sectiune;

public:
    Gestionar(std::string nume, std::string cnp, std::string adresa, int varsta,
              int id, double salariu, std::string data_angajare, int ore_lucru,
              int nr_comenzi, std::string sectiune);
    ~Gestionar();

    int getNrComenzi() const;
    std::string getSectiune() const;

    double calcul_salariu() const override;  //1.3
};


#endif
