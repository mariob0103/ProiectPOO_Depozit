#include "Depozit.h"
#include "ProdusPerisabil.h"
#include "ProdusNonFood.h"
#include "ProdusFood.h"
#include <iostream>
#include <fstream>

Depozit::Depozit(std::string nume, std::string adresa, double capacitate_max)
        : nume(nume), adresa(adresa), capacitate_max(capacitate_max) {}

Depozit::~Depozit() {
    for (Produs* p : inventar) {
        delete p;
    }
    for (Angajat* a : echipa) {
        delete a;
    }
    for (Client* c : clienti) {
        delete c;
    }
}

void Depozit::adaugaProdus(Produs* p) {
    verifica_spatiu(p);   //2.1
    inventar.push_back(p);
}
void Depozit::adaugaAngajat(Angajat* a) {
    echipa.push_back(a);
}
void Depozit::adaugaClient(Client* c) {
    clienti.push_back(c);
}

void Depozit::afiseaza_inventar_complet() const {
    std::cout << "\n Inventar: \n";
    if (inventar.empty()) {
        std::cout << "Depozitul este gol. \n";
        return;
    }
    for (const auto& p : inventar)
        p->afisare();
    std::cout << "Capacitate totala: " << capacitate_max << " kg\n";
    std::cout << "Valoare totala marfa: " << cost_inventar() << " RON\n";
}

//1.1
double Depozit::total_taxe() const {
    double total = 0;
    for(Client* c : clienti)
        total += c->calcul_taxe();   //apel polimorfic
    return total;
}

//1.2
double Depozit::cost_inventar() const {
    double total = 0;
    for (Produs* p : inventar)
        total += p->cost_produs();
    return total;
}

//1.3
double Depozit::total_salarii() const {
    double total = 0;
    for(Angajat* a : echipa)
        total += a->calcul_salariu();
    return total;
}

//2.1
void Depozit::verifica_spatiu(Produs* p) const {
    double ocupat = 0;
    for(Produs* prod : inventar)
        ocupat += prod->getGreutate() * prod->getStoc();
    if (ocupat + (p->getGreutate() * p->getStoc()) > capacitate_max)
        throw capacitate_Exception();
}

//2.2
void Depozit::raport_perisabile() const {
    std::cout << "\n Raport produse perisabile:\n";
    bool gasit = false;
    for(Produs* p : inventar) {
        ProdusPerisabil* perisabil = dynamic_cast<ProdusPerisabil*>(p);
        if (perisabil != nullptr) {
            std::cout << "Produs: " << p->getNume() << "\nData expirare: " << perisabil->getDataExpirare() <<"\n";
            gasit = true;
        }
    }
    if (!gasit)
        std::cout << "Nu exista produse perisabile in depozit. \n";
}

//3.1
void Depozit::lista_fidelitate(int puncte) const{
    std::cout << "\n Lista clienti fideli: \n";
    bool gasit = false;
    for(Client* c : clienti) {
        if (c->getPuncte() >= puncte) {
            std::cout << "Client: " << c->getNume() << "\nPuncte acumulate: " << c->getPuncte() <<"\n";
            gasit = true;
        }
    }
    if (!gasit)
        std::cout << "Niciun client nu se afla pe lista la acest moment. \n";
}

//4.1
void Depozit::atentie_garantie(int luni) const {
    std::cout << "\n Alerta garantie \n";
    bool gasit = false;
    for(Produs* p : inventar) {
        ProdusNonFood* nf = dynamic_cast<ProdusNonFood*>(p);
        if (nf != nullptr && nf->getGarantie() <= luni) {
            std::cout << "Produs: " << p->getNume() << " ;garantie ramasa: " << nf->getGarantie() << " luni \n";
            gasit = true;
        }
    }
    if (!gasit)
        std::cout << "Toate produsele sunt in parametri optimi de garantie.\n";
}

//4.2
void Depozit::verifica_termen_valabilitate(std::string data_curenta) const {
    for (Produs* p : inventar){
        ProdusPerisabil* perisabil = dynamic_cast<ProdusPerisabil*>(p);
        if (perisabil != nullptr)
            if (perisabil->getDataExpirare() < data_curenta)
                throw produs_expirat_Exception();
    }
}

//5.1
void Depozit::afiseaza_produse_bio() const {
    std::cout << "\n Lista produse BIO: \n";
    bool gasit = false;
    for (Produs* p : inventar) {
        ProdusFood* pf = dynamic_cast<ProdusFood*>(p);
        if (pf != nullptr && pf->getBio()) {
            std::cout << "Produs: " << p->getNume() << "\n";
            gasit = true;
        }
    }
    if (!gasit)
        std::cout << "Nu exista produse BIO in stoc. \n";
}

// 5.2
void Depozit::cauta_alergii(std::string ingredient) const {
    std::cout << "\n Produse care contin " << ingredient << ": \n";
    bool gasit = false;
    for (Produs* p : inventar){
        ProdusFood* pf = dynamic_cast<ProdusFood*>(p);
        if (pf != nullptr)
            if (pf->getAlergii().find(ingredient) != std::string::npos) {
                std::cout << p->getNume() << " contine " << ingredient << " \n";
                gasit = true;
            }
    }
    if (!gasit)
        std::cout << "Nu au fost gasite produse care sa contina acest ingredient.\n";
}


void Depozit::salveaza_date(std::string nume_fisier) const {
    std::ofstream out(nume_fisier);
    if (!out.is_open())
        return;
    out << inventar.size() << "\n";
    for (Produs* p : inventar)
        out << p->getNume() << " " << p->getPret() << " " << p->getStoc() << " " << p->getGreutate() << "\n";
    out.close();
}

void Depozit::incarca_date(std::string nume_fisier) {
    std::ifstream in(nume_fisier);
    if (!in.is_open())
        return;
    for (Produs* p : inventar)
        delete p;
    inventar.clear();
    int nrProduse;
    in >> nrProduse;
    for (int i = 0; i < nrProduse; i++) {
        std::string nume;
        double pret, greutate;
        int stoc;
        in >> nume >> pret >> stoc >> greutate;
        inventar.push_back(new ProdusFood(i + 1, nume, pret, stoc, greutate, 0, false, "fara"));
    }
    in.close();
}