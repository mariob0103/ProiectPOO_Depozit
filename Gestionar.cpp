#include "Gestionar.h"

Gestionar::Gestionar(std::string nume, std::string cnp, std::string adresa, int varsta,
                     int id, double salariu, std::string data_angajare, int ore_lucru,
                     int nr_comenzi, std::string sectiune)
                     : Angajat(nume, cnp, adresa, varsta, id, salariu, data_angajare, ore_lucru),
                     nr_comenzi(nr_comenzi), sectiune(sectiune) {}

Gestionar::~Gestionar() {}

int Gestionar::getNrComenzi() const {return nr_comenzi;}
std::string Gestionar::getSectiune() const {return sectiune;}

//1.3
double Gestionar::calcul_salariu() const {
    return salariu + nr_comenzi * 10.0;
}