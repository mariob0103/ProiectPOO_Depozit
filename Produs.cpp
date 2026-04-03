#include "Produs.h"
#include <iostream>

Produs::Produs(int id, std::string nume, double pret, int stoc, double greutate)
    : id(id), nume(nume), pret(pret), stoc(stoc), greutate(greutate) {}

Produs::~Produs() {}

int Produs::getId() const { return id; }
std::string Produs::getNume() const { return nume; }
double Produs::getPret() const { return pret; }
int Produs::getStoc() const { return stoc; }
double Produs::getGreutate() const { return greutate; }

//1.2
double Produs::cost_produs() const {
    return pret * stoc;
}