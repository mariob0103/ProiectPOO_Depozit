#include "Manipulant.h"

Manipulant::Manipulant(std::string nume, std::string cnp, std::string adresa, int varsta,
                       int id, double salariu, std::string data_angajare, int ore_lucru,
                       bool permis_stivuitor, std::string echipament)
                       : Angajat(nume, cnp, adresa, varsta, id, salariu, data_angajare, ore_lucru),
                       permis_stivuitor(permis_stivuitor), echipament(echipament) {}

Manipulant::~Manipulant() {}

bool Manipulant::getPermisStivuitor() const {return permis_stivuitor;}
std::string Manipulant::getEchipament() const {return echipament;}