#ifndef PROIECT_POO_CLIENT_H
#define PROIECT_POO_CLIENT_H

#include <string>

class Client {
protected:
    int id;
    std::string nume;
    int total_comenzi;
    int puncte_loialitate;

public:
    Client(int id, std::string nume, int total_comenzi, int puncte_loialitate);
    virtual ~Client();

    int getId() const;
    std::string getNume() const;
    int getTotalComenzi() const;
    int getPuncte() const;

    virtual void afisare() const;
    virtual double calcul_taxe() const = 0;    //metoda virtuala pura - 1.1 calcul taxe import
};


#endif
