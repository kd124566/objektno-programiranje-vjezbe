#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "VirtualPet.h"
#include "Owner.h"

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
        return 0;  
    }

 



