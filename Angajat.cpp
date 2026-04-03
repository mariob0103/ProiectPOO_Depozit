#include "Angajat.h"
#include <iostream>

Angajat::Angajat(std::string nume, std::string cnp, std::string adresa, int varsta,
                 int id, double salariu, std::string data_angajare, int ore_lucru)
                 : Persoana(nume, cnp, adresa, varsta),
                 id(id), salariu(salariu),data_angajare(data_angajare), ore_lucru(ore_lucru) {}

Angajat:: ~Angajat() {}

std::string Angajat::getNume() const {return nume;}
std::string Angajat::getCNP() const {return cnp;}
std::string Angajat::getAdresa() const {return adresa;}
int Angajat::getVarsta() const {return varsta;}
int Angajat::getId() const {return id;}
double Angajat::getSalariuBaza() const {return salariu;}
std::string Angajat::getDataAngajare() const {return data_angajare;}
int Angajat::getOreLucru() const {return ore_lucru;}

//1.3
double Angajat::calcul_salariu() const {
    return salariu;
}

void Angajat::afisare() const {
    std::cout << "Angajat: " << nume << ", ID: " << id << ", Data angajare: " << data_angajare
    << ", Ore lucrate: " << ore_lucru << "\n";
}