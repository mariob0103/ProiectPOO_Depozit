#include <iostream>
#include <limits>
#include <string>
#include "Depozit.h"
#include "ProdusFood.h"
#include "ProdusNonFood.h"
#include "ProdusPerisabil.h"
#include "ProdusFragil.h"
#include "Picker.h"
#include "Gestionar.h"
#include "Manipulant.h"
#include "ClientUE.h"
#include "ClientNonUE.h"

using namespace std;

const string NUME_FISIER = "date_depozit.txt";

void afiseazaMeniu() {
    cout << "\n Meniu \n";
    cout << "1. Adaugare produs \n";
    cout << "2. Afisare produse filtrate \n";
    cout << "3. Afisare inventar \n";
    cout << "4. Adaugare angajat \n";
    cout << "5. Adaugare client \n";
    cout << "6. Lista de fidelitate \n";
    cout << "7. Detalii administrative \n";
    cout << "0. Iesire \n";
    cout << "Alege optiunea: ";
}

void adaugaProdusMeniu(Depozit& depozit) {
    int tip;
    cout << "\n Adaugare produs \n";
    cout << "1. Produs alimentar\n";
    cout << "2. Produs non-food\n";
    cout << "3. Produs perisabil\n";
    cout << "4. Produs fragil\n";
    cout << "Alege tipul produsului: ";
    cin >> tip;

    int id, stoc;
    string nume;
    double pret, greutate;
    cout << "ID produs: ";
    cin >> id;
    cout << "Nume produs: ";
    cin >> nume;
    cout << "Pret: ";
    cin >> pret;
    cout << "Stoc: ";
    cin >> stoc;
    cout << "Greutate/unitate: ";
    cin >> greutate;

    Produs* p = nullptr;
    if (tip == 1) {
        double calorii;
        bool bio;
        string alergii;
        cout << "Calorii: ";
        cin >> calorii;
        cout << "Este bio? (1 = da, 0 = nu): ";
        cin >> bio;
        cout << "Alergii: ";
        cin >> alergii;
        p = new ProdusFood(id, nume, pret, stoc, greutate, calorii, bio, alergii);
    }
    else if (tip == 2) {
        string material;
        int garantie_luni;
        cout << "Material: ";
        cin >> material;
        cout << "Garantie (luni): ";
        cin >> garantie_luni;
        p = new ProdusNonFood(id, nume, pret, stoc, greutate, material, garantie_luni);
    }
    else if (tip == 3) {
        double calorii, temperatura_depozitare;
        bool bio;
        string alergii, data_expirare;
        cout << "Calorii: ";
        cin >> calorii;
        cout << "Este bio? (1 = da, 0 = nu): ";
        cin >> bio;
        cout << "Alergii: ";
        cin >> alergii;
        cout << "Data expirare (YYYY-MM-DD): ";
        cin >> data_expirare;
        cout << "Temperatura depozitare: ";
        cin >> temperatura_depozitare;
        p = new ProdusPerisabil(id, nume, pret, stoc, greutate,
                                calorii, bio, alergii,
                                data_expirare, temperatura_depozitare);
    }
    else if (tip == 4) {
        double calorii, cost_asigurare;
        bool bio;
        string alergii, material, instructiuni_manipulare;
        int garantie_luni;
        cout << "Calorii: ";
        cin >> calorii;
        cout << "Este bio? (1 = da, 0 = nu): ";
        cin >> bio;
        cout << "Alergii: ";
        cin >> alergii;
        cout << "Material: ";
        cin >> material;
        cout << "Garantie (luni): ";
        cin >> garantie_luni;
        cout << "Instructiuni manipulare: ";
        cin >> instructiuni_manipulare;
        cout << "Cost asigurare: ";
        cin >> cost_asigurare;
        p = new ProdusFragil(id, nume, pret, stoc, greutate,
                             calorii, bio, alergii,
                             material, garantie_luni,
                             instructiuni_manipulare, cost_asigurare);
    }
    else {
        cout << "Tip invalid.\n";
        return;
    }

    try {
        depozit.adaugaProdus(p);
        depozit.salveaza_date(NUME_FISIER);
        cout << "Produs adaugat cu succes.\n";
    }
    catch (const capacitate_Exception& e) {
        cout << "Eroare: " << e.what() << "\n";
        delete p;
    }
    catch (...) {
        cout << "A aparut o eroare la adaugarea produsului.\n";
        delete p;
    }
}

void afisareFiltreMeniu(Depozit& depozit) {
    int opt;
    cout << "\n Produse filtrate \n";
    cout << "1. Produse BIO\n";
    cout << "2. Produse cu alergii\n";
    cout << "3. Raport produse perisabile\n";
    cout << "4. Alerta garantie produse non-food\n";
    cout << "Alege optiunea: ";
    cin >> opt;
    if (opt == 1) {
        depozit.afiseaza_produse_bio();
    }
    else if (opt == 2) {
        string ingredient;
        cout << "Ingredient / alergen cautat: ";
        cin >> ingredient;
        depozit.cauta_alergii(ingredient);
    }
    else if (opt == 3) {
        depozit.raport_perisabile();
    }
    else if (opt == 4) {
        int luni;
        cout << "Afiseaza produsele cu garantie <= cate luni? ";
        cin >> luni;
        depozit.atentie_garantie(luni);
    }
    else
        cout << "Optiune invalida.\n";
}

void adaugaAngajatMeniu(Depozit& depozit) {
    int tip;
    cout << "\n Adaugare angajat \n";
    cout << "1. Picker\n";
    cout << "2. Gestionar\n";
    cout << "3. Manipulant\n";
    cout << "Alege tipul angajatului: ";
    cin >> tip;

    string nume, cnp, adresa, data_angajare;
    int varsta, id, ore_lucru;
    double salariu;
    cout << "Nume: ";
    cin >> nume;
    cout << "CNP: ";
    cin >> cnp;
    cout << "Adresa: ";
    cin >> adresa;
    cout << "Varsta: ";
    cin >> varsta;
    cout << "ID angajat: ";
    cin >> id;
    cout << "Salariu baza: ";
    cin >> salariu;
    cout << "Data angajare: ";
    cin >> data_angajare;
    cout << "Ore lucrate: ";
    cin >> ore_lucru;
    if (tip == 1) {
        int comenzi_finalizate;
        double rata_eroare;
        cout << "Comenzi finalizate: ";
        cin >> comenzi_finalizate;
        cout << "Rata eroare (%): ";
        cin >> rata_eroare;
        depozit.adaugaAngajat(new Picker(nume, cnp, adresa, varsta, id, salariu,
                                         data_angajare, ore_lucru,
                                         comenzi_finalizate, rata_eroare));
        depozit.salveaza_date(NUME_FISIER);
        cout << "Picker adaugat cu succes.\n";
    }
    else if (tip == 2) {
        int nr_comenzi;
        string sectiune;
        cout << "Numar comenzi gestionate: ";
        cin >> nr_comenzi;
        cout << "Sectiune: ";
        cin >> sectiune;
        depozit.adaugaAngajat(new Gestionar(nume, cnp, adresa, varsta, id, salariu,
                                            data_angajare, ore_lucru,
                                            nr_comenzi, sectiune));
        depozit.salveaza_date(NUME_FISIER);
        cout << "Gestionar adaugat cu succes.\n";
    }
    else if (tip == 3) {
        bool permis_stivuitor;
        string echipament;
        cout << "Permis stivuitor? (1 = da, 0 = nu): ";
        cin >> permis_stivuitor;
        cout << "Echipament: ";
        cin >> echipament;
        depozit.adaugaAngajat(new Manipulant(nume, cnp, adresa, varsta, id, salariu,
                                             data_angajare, ore_lucru,
                                             permis_stivuitor, echipament));
        depozit.salveaza_date(NUME_FISIER);
        cout << "Manipulant adaugat cu succes.\n";
    }
    else
        cout << "Tip invalid.\n";
}

void adaugaClientMeniu(Depozit& depozit) {
    int tip;
    cout << "\n Adaugare client \n";
    cout << "1. Client UE\n";
    cout << "2. Client Non-UE\n";
    cout << "Alege tipul clientului: ";
    cin >> tip;

    int id, total_comenzi, puncte;
    string nume, taraSauNrVamal;
    double taxa;
    cout << "ID client: ";
    cin >> id;
    cout << "Nume client: ";
    cin >> nume;
    cout << "Total comenzi: ";
    cin >> total_comenzi;
    cout << "Puncte loialitate: ";
    cin >> puncte;
    if (tip == 1) {
        cout << "Tara: ";
        cin >> taraSauNrVamal;
        cout << "Taxa intracomunitara: ";
        cin >> taxa;
        depozit.adaugaClient(new ClientUE(id, nume, total_comenzi, puncte, taraSauNrVamal, taxa));
        depozit.salveaza_date(NUME_FISIER);
        cout << "Client UE adaugat cu succes.\n";
    }
    else if (tip == 2) {
        cout << "Numar vamal: ";
        cin >> taraSauNrVamal;
        cout << "Taxa vamala: ";
        cin >> taxa;
        depozit.adaugaClient(new ClientNonUE(id, nume, total_comenzi, puncte, taraSauNrVamal, taxa));
        depozit.salveaza_date(NUME_FISIER);
        cout << "Client Non-UE adaugat cu succes.\n";
    }
    else {
        cout << "Tip invalid.\n";
    }
}

void detaliiAdministrativeMeniu(Depozit& depozit) {
    int opt;
    cout << "\n Detalii administrative \n";
    cout << "1. Total taxe import\n";
    cout << "2. Valoare totala inventar\n";
    cout << "3. Total salarii angajati\n";
    cout << "4. Raport produse perisabile\n";
    cout << "5. Verificare termen valabilitate\n";
    cout << "Alege optiunea: ";
    cin >> opt;
    if (opt == 1)
        cout << "Total taxe import: " << depozit.total_taxe() << " RON \n";
    else if (opt == 2)
        cout << "Valoare totala inventar: " << depozit.cost_inventar() << " RON \n";
    else if (opt == 3)
        cout << "Total salarii: " << depozit.total_salarii() << " RON\n";
    else if (opt == 4)
        depozit.raport_perisabile();
    else if (opt == 5) {
        string data_curenta;
        cout << "Introdu data curenta (YYYY-MM-DD): ";
        cin >> data_curenta;
        try {
            depozit.verifica_termen_valabilitate(data_curenta);
            cout << "Nu exista produse expirate.\n";
        }
        catch (const produs_expirat_Exception& e) {
            cout << "Eroare: " << e.what() << "\n";
        }
    }
    else
        cout << "Optiune invalida.\n";
}

int main()
{
    Depozit depozit("Zosoftware", "Bucuresti", 10000);
    depozit.incarca_date(NUME_FISIER);

    int optiune;
    do {
        afiseazaMeniu();
        cin >> optiune;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Te rog introdu un numar valid.\n";
            continue;
        }
        switch (optiune) {
            case 1:
                adaugaProdusMeniu(depozit);
                break;
            case 2:
                afisareFiltreMeniu(depozit);
                break;
            case 3:
                depozit.afiseaza_inventar_complet();
                break;
            case 4:
                adaugaAngajatMeniu(depozit);
                break;
            case 5:
                adaugaClientMeniu(depozit);
                break;
            case 6: {
                int prag;
                cout << "Puncte fidelitate: ";
                cin >> prag;
                depozit.lista_fidelitate(prag);
                break;
            }
            case 7:
                detaliiAdministrativeMeniu(depozit);
                break;
            case 0:
                cout << "Iesire \n";
                break;
            default:
                cout << "Optiune invalida.\n";
        }
    } while (optiune != 0);
    return 0;
}