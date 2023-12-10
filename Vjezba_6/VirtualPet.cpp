#include "Virtualpet.h"
#include <iostream>
#include <string>

Virtualpet::Virtualpet(const std::string& ime, const std::string& vrsta)
    : ime(ime), vrsta(vrsta), bodovigladi(50), bodovisrece(50), budnost(1) {}

void Virtualpet::jede() {
    if (budnost == 1) {
        bodovigladi -= 10;
        bodovisrece += 10;
        std::cout << ime << " je jeo. Glad - 10, sreca + 10." << std::endl;
    }
    if (bodovigladi >= 70) {
        budnost = 0; 
        std::cout << ime << " je sit i ide na spavanje." << std::endl;
    }
 else {
     std::cout << ime << " spava" << std::endl;
    }
}

void Virtualpet::spava() {
    if (budnost == 0) {
        bodovigladi += 10;
        bodovisrece += 10;
        std::cout << ime << " spava. Glad + 10, sreca + 10." << std::endl;
    }
    else {
        std::cout << ime << " spava" << std::endl;
    }
}

void Virtualpet::igra() {
    if (budnost == 1) {
        bodovigladi += 10;
        bodovisrece += 10;
        std::cout << ime << " se igra. Glad + 10, a sreca + 10." << std::endl;
    }
    else {
        std::cout << ime << " spava" << std::endl;
    }
}

int Virtualpet::sreca() const {
    return bodovisrece;
}

const std::string& Virtualpet::Ime() const {
    return ime;

}
