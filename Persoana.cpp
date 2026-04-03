#include "Persoana.h"
#include <iostream>

Persoana::Persoana(std::string nume, std::string cnp, std::string adresa, int varsta)
    : nume(nume), cnp(cnp), adresa(adresa), varsta(varsta) {}

Persoana::~Persoana() {}


void Persoana::afisare() const {
    std::cout << "Nume: " << nume << " | CNP: " << cnp;
}