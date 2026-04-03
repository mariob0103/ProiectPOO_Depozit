#include "ProdusNonFood.h"
#include<iostream>


ProdusNonFood::ProdusNonFood(int id, std::string nume, double pret, int stoc, double greutate,
                             std::string material, int garantie_luni)
                             : Produs(id, nume, pret, stoc, greutate),
                             material(material), garantie_luni(garantie_luni) {}

ProdusNonFood::~ProdusNonFood() {}

std::string ProdusNonFood::getMaterial() const {return material;}
int ProdusNonFood::getGarantie() const { return garantie_luni;}

void ProdusNonFood::afisare() const {
    std::cout << "Produs: " << nume << " | Pret: " << pret << " RON | Garantie: " << garantie_luni << " luni\n";
}