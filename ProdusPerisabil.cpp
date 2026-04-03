#include "ProdusPerisabil.h"
#include<iostream>

ProdusPerisabil::ProdusPerisabil(int id, std::string nume, double pret, int stoc, double greutate,
                                 double calorii, bool este_bio, std::string alergii,
                                 std::string data_expirare, double temperatura_depozitare)
                                 : Produs(id, nume, pret, stoc, greutate),
                                 ProdusFood(id, nume, pret, stoc, greutate, calorii, este_bio, alergii),
                                 data_expirare(data_expirare), temperatura_depozitare(temperatura_depozitare) {}

ProdusPerisabil::~ProdusPerisabil() {}

double ProdusPerisabil::getTemperaturaDepozitare() const { return temperatura_depozitare;}

void ProdusPerisabil::afisare() const {
    std::cout << "Perisabil: " << nume << " | Expira la: " << data_expirare << "\n";
}

//2.2
std::string ProdusPerisabil::getDataExpirare() const {
    return data_expirare;
}