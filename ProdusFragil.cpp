#include "ProdusFragil.h"
#include<iostream>

ProdusFragil::ProdusFragil(int id, std::string nume, double pret, int stoc, double greutate,
                           double calorii, bool este_bio, std::string alergii,
                           std::string material, int garantie_luni,
                           std::string instructiuni_manipulare, double cost_asigurare)
                           : Produs(id, nume, pret, stoc, greutate),
                           ProdusFood(id, nume, pret, stoc, greutate, calorii, este_bio, alergii),
                           ProdusNonFood(id, nume, pret, stoc, greutate, material, garantie_luni),
                           instructiuni_manipulare(instructiuni_manipulare), cost_asigurare(cost_asigurare) {}

ProdusFragil::~ProdusFragil() {}

void ProdusFragil::afisare() const {
    ProdusNonFood::afisare();
    std::cout << "Produs Fragil! \n";
}

std::string ProdusFragil::getInstructiuniManipulare() const {return instructiuni_manipulare;}
double ProdusFragil::getCostAsigurare() const {return cost_asigurare;}

//1.2
double ProdusFragil::cost_produs() const {
    return pret * stoc + cost_asigurare;
}