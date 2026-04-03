In acest proiect am simulat o aplicatie pentru gestionarea unui depozit. Scopul principal este organizarea produselor, angajatilor si clientilor, folosind concepte de programare orientata pe obiect.

In cadrul aplicatiei exista mai multe clase principale, acestea reprezentand “pilonii” aplicatiei, urmand ca mai departe sa fie create pe baza lor alte entitati, care le mostenesc caracteristicile generale:
    - Depozit – clasa principala a proiectului, care contine informatiile generale, despre nume, adresa si capacitate maxima. 		De asemenea, aici vor fi gestionate toate functionalitatile, intrucat se pot accesa:
		  - lista de produse (inventar)
		  - lista de angajati
		  - lista de clienti
    - Produs – clasa de baza pentru toate produsele din depozit, care retine informatii generale precum id, nume, pret, stoc si greutate.
		     Din aceasta deriva mai multe tipuri:
		  - Produse food (cu calorii, bio, alergii)
		  - Produse non-food (cu material si garantie)
		  - Produse perisabile (cu data de expirare si temperatura)
		  - Produse fragile (cu instructiuni de manipulare si cost de asigurare)
    - Persoana – clasa de baza, care contine date generale (nume, CNP, adresa, varsta).
		     Din aceasta deriva:
		  - Angajat – cu informatii despre salariu, ore lucrate etc.
		    - tipuri de angajati: Picker, Gestionar, Manipulant
    - Client – cu informatii despre comenzi si puncte de loialitate
	    	- tipuri de clienti: ClientUE si ClientNonUE


Am implementat, in principiu in Depozit.cpp, mai multe functionalitati, pe care le-am integrat si in meniul interactiv. De asemenea, le-am numerotat pe fiecare pentru a fi mai usor de urmarit implementarea propriu zisa in cod si in functie de “domeniul” de care se leaga; Ce se afla cu - pus langa idee este de fapt locul unde am definit functiile ajutatoare pentru realizarea task-ului. (Am notat doar acolo unde am facut o alta functie fata de getterele clasice)
Astfel, functionalitatile sunt urmatoarele:

	1.1 Calcul Taxe Import (Vama/UE) - Client + (ClientNonUE + ClientUE) 
	1.2 Valoarea Totala a Inventarului - Produs + (ProdusFragil)
	1.3 Simulator de Salarii (De mentionat aici ca fiecare angajat are un salariu diferit, in functie de munca pe care o face. La Picker, in functie de “rata_eroare” ii mai scade din salariu, Gestionarul are mai mult decat Picker oricum si ii poate creste in functie de “nr_comenz”i, iar la Manipulant am cel mai mic salariu si este mereu constant)  - Angajat + (Gestionar + Picker)

	2.1 Verificarea Capacitatii (Aici am aruncat exceptie daca depaseste capacitatea totala a depozituli - exceptie implementata si definita in Depozit) 
	2.2 Raport Produse Perisabile

	3.1 Sistem de Recompense (pentru clientii fideli, care au ajuns la un anumit numar de puncte loialitate)

	4.1 Alerta Mentenanta/Garantie: (produsele care au “data_expirare“ + 2 luni >= data curenta au nevoie de atentie speciala)
	4.2 Alerta Expirare (cu aruncare de exceptii, daca un produs e expirat se arunca exceptia - exceptie implementata si definita in Depozit)

	5.1 Cautare "Bio"
	5.2 Cautare dupa Alergii


Ultima parte este meniul interactiv. Acesta arata in felul urmator:

Meniu 
1. Adaugare produs 
	1. Produs alimentar
	2. Produs non-food
	3. Produs perisabil
	4. Produs fragil
2. Afisare produse filtrate 
	1. Produse BIO
	2. Produse cu alergii
	3. Raport produse perisabile
	4. Alerta garantie produse non-food
3. Afisare inventar 
4. Adaugare angajat 
5. Adaugare client 
6. Lista de fidelitate 
7. Detalii administrative 
	1. Total taxe import
	2. Valoare totala inventar
	3. Total salarii angajati
	4. Raport produse perisabile
	5. Verificare termen valabilitate
0. Iesire
