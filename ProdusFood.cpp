#include "ProdusFood.h"
#include<iostream>

ProdusFood::ProdusFood(int id, std::string nume, double pret, int stoc, double greutate,
                       double calorii, bool este_bio, std::string alergii)
                       : Produs(id, nume, pret, stoc, greutate),
                        calorii(calorii), este_bio(este_bio), alergii(alergii) {}

ProdusFood::~ProdusFood() {}

bool ProdusFood::getBio() const { return este_bio; }
double ProdusFood::getCalorii() const {return calorii; }
std::string ProdusFood::getAlergii() const { return alergii; }

void ProdusFood::afisare() const {
    std::cout << "Aliment: " << nume << " | Pret: " << pret << " RON | Stoc: " << stoc << "\n";
}