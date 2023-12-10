#ifndef OWNER_H
#define OWNER_H


#include <string>
#include <vector>
#include "Virtualpet.h"

class Owner {
private:
    std::string ime;
    std::vector<Virtualpet> pets;

public:
    Owner(const std::string& ime);

    void dodaj(const Virtualpet& pet);
    void radnja();
    Virtualpet najsretniji() const;

    const std::string& Ime() const;

    void postaviIme(const std::string& novo);
};

#endif
