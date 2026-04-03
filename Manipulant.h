#ifndef PROIECT_POO_MANIPULANT_H
#define PROIECT_POO_MANIPULANT_H

#include "Angajat.h"

class Manipulant : public Angajat{
private:
    bool permis_stivuitor;
    std::string echipament;

public:
    Manipulant(std::string nume, std::string cnp, std::string adresa, int varsta,
               int id, double salariu, std::string data_angajare, int ore_lucru,
               bool permis_stivuitor, std::string echipament);
    ~Manipulant();

    bool getPermisStivuitor() const;
    std::string getEchipament() const;
};


#endif
