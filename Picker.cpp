#include "Picker.h"

Picker::Picker(std::string nume, std::string cnp, std::string adresa, int varsta,
               int id, double salariu, std::string data_angajare, int ore_lucru,
               int comenzi_finalizate, double rata_eroare)
               : Angajat(nume, cnp, adresa, varsta, id, salariu, data_angajare, ore_lucru),
               comenzi_finalizate(comenzi_finalizate), rata_eroare(rata_eroare) {}

Picker::~Picker() {}

int Picker::getComenziFinalizate() const {return comenzi_finalizate;}
double Picker::getRataEroare() const {return rata_eroare;}

//1.3
double Picker::calcul_salariu() const {
    return salariu - salariu * rata_eroare / 100.0;
}