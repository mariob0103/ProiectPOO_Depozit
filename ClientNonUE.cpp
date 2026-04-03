#include "ClientNonUE.h"

ClientNonUE::ClientNonUE(int id, std::string nume, int total_comenzi, int puncte_loialitate,
                         std::string nr_vamal, double taxa_vamala)
                         : Client(id, nume, total_comenzi, puncte_loialitate),
                         nr_vamal(nr_vamal), taxa_vamala(taxa_vamala) {}

ClientNonUE::~ClientNonUE() {}

std::string ClientNonUE::getNrVamal() const { return nr_vamal; }
double ClientNonUE::getTaxaVamala() const { return taxa_vamala; }

//1.1
double ClientNonUE::calcul_taxe() const {
    return taxa_vamala;
}