#ifndef PROIECT_POO_PRODUS_H
#define PROIECT_POO_PRODUS_H

#include <string>

class Produs {
protected:
    int id;
    std::string nume;
    double pret;
    int stoc;
    double greutate;

public:
    Produs(int id, std::string nume, double pret, int stoc, double greutate);
    virtual ~Produs();

    int getId() const;
    std::string getNume() const;
    double getPret() const;
    int getStoc() const;
    double getGreutate() const;

    virtual void afisare() const = 0;
    virtual double cost_produs() const;  //metoda virtuala - 1.2 val totala inventar
};


#endif
