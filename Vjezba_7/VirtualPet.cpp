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

int operator==(const Virtualpet& pet1, const Virtualpet& pet2)
{
    if (pet1.ime == pet2.ime && pet1.vrsta == pet2.vrsta && pet1.bodovigladi == pet2.bodovigladi && pet1.bodovisrece == pet2.bodovisrece && pet1.budnost == pet2.budnost)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int operator!=(const Virtualpet& pet1, const Virtualpet& pet2)
{
    if (pet1.ime == pet2.ime && pet1.vrsta == pet2.vrsta && pet1.bodovigladi == pet2.bodovigladi && pet1.bodovisrece == pet2.bodovisrece && pet1.budnost == pet2.budnost)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
Virtualpet& Virtualpet::operator=(const Virtualpet& cpy)
{
    if (this != &cpy) {
    ime = cpy.ime;
    vrsta = cpy.vrsta;
    bodovigladi = cpy.bodovigladi;
    bodovisrece = cpy.bodovisrece;
    budnost = cpy.budnost;
}
return *this;
}
Virtualpet& Virtualpet::operator++() {
    bodovigladi += 10;
    return *this;
}

Virtualpet Virtualpet::operator++(int) {
    Virtualpet temp = *this;
    bodovigladi += 10;
    return temp;
}

int operator<(const Virtualpet& pet1, const Virtualpet& pet2) {
    if (pet1.sreca() < pet2.sreca())
    {
        return 1;
    }
}

int operator>(const Virtualpet& pet1, const Virtualpet& pet2) {
    if (pet1.sreca() > pet2.sreca())
    {
        return 1;
    }
}
int operator<=(const Virtualpet& pet1, const Virtualpet& pet2) {
    if (pet1.sreca() <= pet2.sreca())
    {
        return 1;
    }
}
int operator>=(const Virtualpet& pet1, const Virtualpet& pet2) {
    if (pet1.sreca() >= pet2.sreca())
    {
        return 1;
    }
}
std::ostream& operator<<(std::ostream& os, const Virtualpet& obj) {
    os << obj.ime;
    os << obj.vrsta;
    os << obj.bodovigladi;
    os << obj.bodovisrece;
    os << obj.budnost;
    return os;
}



