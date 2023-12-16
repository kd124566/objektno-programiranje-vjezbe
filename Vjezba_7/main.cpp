#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "VirtualPet.h"
#include "Owner.h"
#include "Food.h"

int main()
{
        srand(time(0));

        Owner owner1("Ivo");
        Virtualpet pet1("Mici", "macka");
        Virtualpet pet2("Jale", "pas");

        owner1.dodaj(pet1);
        owner1.dodaj(pet2);

        Owner owner2 = owner1;
        owner2.postaviIme("Lara");

        owner1.radnja();
        owner2.radnja();

        for (int i = 0; i < 3; ++i) {
            owner1.radnja();
            owner2.radnja();
        }

        Virtualpet najsretniji1 = owner1.najsretniji();
        Virtualpet najsretniji2 = owner2.najsretniji();

        std::cout << "Najsretniji ljubimac " << owner1.Ime() << " je: " << najsretniji1.Ime()
            << " s srecom " << najsretniji1.sreca() << std::endl;

        std::cout << "Najsretniji ljubimac " << owner2.Ime() << " je: " << najsretniji1.Ime()
            << " s srecom " << najsretniji2.sreca() << std::endl;

        if (najsretniji1.sreca() > najsretniji2.sreca())
        {
            std::cout << "najsretniji vlasnik je " << owner1.Ime() << std::endl;
        }
        else if (najsretniji1.sreca() < najsretniji2.sreca())
        {
            std::cout << "najsretniji vlasnik je " << owner2.Ime() << std::endl;
        }



        Food hrana;
        hrana.isprintaj();
        hrana.povecaj();
        hrana.isprintaj();
        hrana.smanji();
        hrana.isprintaj();
        hrana.povecaj();
        hrana.isprintaj();

        std::cout << "Non-member: " << get_counter() << "\n";
     
        std::cout << "operator == " << "\n";
        if (pet1 == pet2) {
            std::cout << "Ljubimci su jednaki." << std::endl;
        }
        else {
            std::cout << "Ljubimci nisu jednaki." << std::endl;
        }
        std::cout << "operator != " << "\n";
        if (pet1 != pet2) {
            std::cout << "Ljubimci nisu jednaki." << std::endl;
        }
        else {
            std::cout << "Ljubimci su jednaki." << std::endl;
        }
        std::cout << "operator = " << std::endl;
        pet1 = pet2;
        std::cout << pet1.Ime() << " " << pet1.vrsta << std::endl;
        std::cout << pet1.bodovigladi << " " << pet1.bodovisrece <<  " " << pet1.budnost << std::endl;
        std::cout << "operator < " << std::endl;
        if (pet1 < pet2) {
            std::cout << "pet1 je manji od pet2" << std::endl;
        }
        else {
            std::cout << "pet 1 je veci." << std::endl;
        }
        std::cout << "operator > " << std::endl;
        if (pet1 > pet2) {
            std::cout << "pet1 je  od veci pet2" << std::endl;
        }
        else {
            std::cout << "pet2 je veci." << std::endl;
        }
        std::cout << "operator<= " << std::endl;
        if (pet1 <= pet2) {
            std::cout << "pet1 je manji ili jednak pet2" << std::endl;
        }
        else {
            std::cout << "pet 1 je veci." << std::endl;
        }
        std::cout << "operator >= " << std::endl;
        if (pet1 >= pet2) {
            std::cout << "pet1 je veci ili jednak pet2" << std::endl;
        }
        else {
            std::cout << "pet2 je veci." << std::endl;
        }
        std::cout << "operator <<" << std::endl;
        std::cout << "Ispis pet1: " << pet1 << std::endl;
        std::cout << "Ispis pet2: " << pet2 << std::endl;
        

        return 0;
}

 



