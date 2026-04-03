#ifndef PROIECT_POO_PERSOANA_H
#define PROIECT_POO_PERSOANA_H

#include <string>

class Persoana {
protected:
    std::string nume;
    std::string cnp;
    std::string adresa;
    int varsta;

public:
    Persoana(std::string nume, std::string cnp, std::string adresa, int varsta);
    virtual ~Persoana();

    std::string getNume() const { return nume; }
    std::string getCNP() const { return cnp; }
    std::string getAdresa() const { return adresa; }
    int getVarsta() const { return varsta; }

    virtual void afisare() const;
};

#endif
