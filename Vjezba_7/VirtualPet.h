#ifndef VIRTUALPET_H
#define VIRTUALPET_H
#include <string>
#include <iostream>

class Virtualpet
{
public:
    std::string ime;
    std::string vrsta;
    int bodovigladi;
    int bodovisrece;
    int budnost;
    Virtualpet(const std::string& ime, const std::string& vrsta);

    void jede();
    void spava();
    void igra();

    int sreca() const;
    const std::string& Ime() const;

    friend int operator==(const Virtualpet& pet1, const Virtualpet& pet2);
    friend int operator!=(const Virtualpet& pet1, const Virtualpet& pet2);
    Virtualpet& operator=(const Virtualpet& cpy);
    Virtualpet& operator++();
    Virtualpet operator++(int);   
    friend int operator<(const Virtualpet& pet1, const Virtualpet& pet2);
    friend int operator>(const Virtualpet& pet1, const Virtualpet& pet2);
    friend int operator<=(const Virtualpet& pet1, const Virtualpet& pet2);
    friend int operator>=(const Virtualpet& pet1, const Virtualpet& pet2);

    friend std::ostream& operator<<(std::ostream& os, const Virtualpet& obj);
};


#endif