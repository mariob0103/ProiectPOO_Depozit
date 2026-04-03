#ifndef PROIECT_POO_CLIENTUE_H
#define PROIECT_POO_CLIENTUE_H

#include "Client.h"

class ClientUE : public Client{
private:
    std::string tara;
    double taxa_intracomunitara;

public:
    ClientUE(int id, std::string nume, int total_comenzi, int puncte_loialitate,
             std::string tara, double taxa_intracomunitara);
    ~ClientUE();

    std::string getTara() const;
    double getTaxaIntracomunitara() const;

    double calcul_taxe() const override;    //1.1
};


#endif
