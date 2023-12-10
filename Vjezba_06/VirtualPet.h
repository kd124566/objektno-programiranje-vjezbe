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
    

};

#endif