#ifndef PROIECT_POO_ANGAJAT_H
#define PROIECT_POO_ANGAJAT_H

#include "Persoana.h"

class Angajat :public Persoana {
protected:
    int id;
    double salariu;
    std::string data_angajare;
    int ore_lucru;

public:
    Angajat(std::string nume, std::string cnp, std::string adresa, int varsta,
            int id, double salariu, std::string data_angajare, int ore_lucru);
    virtual ~Angajat();

    std::string getNume() const;
    std::string getCNP() const;
    std::string getAdresa() const;
    int getVarsta() const;
    int getId() const;
    double getSalariuBaza() const;
    std::string getDataAngajare() const;
    int getOreLucru() const;

    void afisare() const override;
    virtual double calcul_salariu() const;   //1.3 - simulator salarii
};


#endif
