#include "Owner.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

Owner::Owner(const std::string& ime) : ime(ime) {}

void Owner::dodaj(const Virtualpet& pet) {
    pets.push_back(pet);
}

void Owner::radnja() {
    for (Virtualpet& pet : pets) {
        int nasumicno = std::rand() % 3;
        
        if (nasumicno == 0) {
            pet.jede();
        }
        else if (nasumicno == 1) {
            pet.spava();
        }
        else {
            pet.igra();
        }
    }
}

Virtualpet Owner::najsretniji() const {
    Virtualpet naj = pets[0];

    for (Virtualpet pet : pets) {
        if (pet.sreca() > naj.sreca()) {
            naj = pet;
        }
    }
    return naj;
}

const std::string& Owner::Ime() const {
    return ime;
}
void Owner::postaviIme(const std::string& novo) {
    ime = novo;
}