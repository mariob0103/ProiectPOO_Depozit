#include "Client.h"
#include <iostream>

Client::Client(int id, std::string nume, int total_comenzi, int puncte_loialitate)
    : id(id), nume(nume), total_comenzi(total_comenzi), puncte_loialitate(puncte_loialitate) {}

Client::~Client() {}

int Client::getId() const { return id; }
std::string Client::getNume() const { return nume; }
int Client::getPuncte() const { return puncte_loialitate; }
int Client::getTotalComenzi() const { return total_comenzi; }

void Client::afisare() const {
    std::cout << "Client: " << nume << ", ID: " << id << ", Comenzi: " << total_comenzi
    << ", Puncte: " << puncte_loialitate << "\n";
}


