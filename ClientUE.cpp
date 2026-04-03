#include "ClientUE.h"

ClientUE::ClientUE(int id, std::string nume, int total_comenzi, int puncte_loialitate,
                   std::string tara, double taxa_intracomunitara)
                   : Client(id, nume, total_comenzi, puncte_loialitate),
                   tara(tara), taxa_intracomunitara(taxa_intracomunitara) {}

ClientUE::~ClientUE() {}

std::string ClientUE::getTara() const { return tara; }
double ClientUE::getTaxaIntracomunitara() const { return taxa_intracomunitara; }

//1.1
double ClientUE::calcul_taxe() const {
    return taxa_intracomunitara;
}