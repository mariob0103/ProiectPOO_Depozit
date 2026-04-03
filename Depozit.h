#ifndef PROIECT_POO_DEPOZIT_H
#define PROIECT_POO_DEPOZIT_H

#include "Produs.h"
#include "Angajat.h"
#include "Client.h"

#include <fstream>
#include <vector>
#include <string>
#include <exception>

//2.1
class capacitate_Exception : public std::exception {
public:
    const char* what() const throw() {
        return "Produsul nu are loc in depozit la momentul actual.";
    }
};

//4.2
class produs_expirat_Exception : public std::exception {
public:
    const char* what() const throw() {
        return "Nu se poate lichida un produs care depaseste termenul de valabilitate!";
    }
};

class Depozit {
private:
    std::string nume;
    std::string adresa;
    double capacitate_max;
    std::vector<Produs*> inventar;
    std::vector<Angajat*> echipa;
    std::vector<Client*> clienti;

public:
    Depozit(std::string nume, std::string adresa, double capacitate_max);
    ~Depozit();

    void adaugaProdus(Produs* p);
    void adaugaAngajat(Angajat* a);
    void adaugaClient(Client* c);

    void salveaza_date(std::string nume_fisier) const;
    void incarca_date(std::string nume_fisier);

    void afiseaza_inventar_complet() const;
    double total_taxe() const;    //1.1 ~ parcurg toti clientii si adun taxele
    double cost_inventar() const;    //1.2 ~ parcurg toate produsele si adun costurile
    double total_salarii() const;   //1.3 ~ parcurg toti angajatii si adun salariile
    void verifica_spatiu(Produs* p) const;   //2.1 ~ arunca exceptie daca e plin
    void raport_perisabile() const;  //2.2 - afiseaza doar produsele care expira
    void lista_fidelitate(int puncte) const;   //3.1 - afiseaza clientii fideli
    void atentie_garantie(int luni) const;  //4.1 - produse Non-Food cu garantie mica
    void verifica_termen_valabilitate(std::string data_curenta) const;   //4.2
    void afiseaza_produse_bio() const;  //5.1
    void cauta_alergii(std::string ingredient) const;  //5.2
};


#endif
