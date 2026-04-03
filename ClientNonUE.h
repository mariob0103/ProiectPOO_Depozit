#ifndef PROIECT_POO_CLIENTNONUE_H
#define PROIECT_POO_CLIENTNONUE_H

#include "Client.h"

class ClientNonUE : public Client{
private:
    std::string nr_vamal;
    double taxa_vamala;

public:
    ClientNonUE(int id, std::string nume, int total_comenzi, int puncte_loialitate,
                std::string nr_vamal, double taxa_vamala);
    ~ClientNonUE();

    std::string getNrVamal() const;
    double getTaxaVamala() const;

    double calcul_taxe() const override;    //1.1
};


#endif
