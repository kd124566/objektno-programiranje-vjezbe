#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cctype>
#include <fstream>
#include <iterator>
#include <functional>
#include <string>

void zadatak1() {
    std::ifstream otvori("words.txt");
    if (!otvori) {
        std::cout << "Datoteka nije otvorena" << std::endl;
        return;
    }
    std::vector<std::string> rijeci;
    std::copy(std::istream_iterator<std::string>(otvori), std::istream_iterator<std::string>(), std::back_inserter(rijeci));

    std::string trazenaRijec = "objektno";
    std::vector<int> pozicije;
    std::vector<std::string>::iterator it = std::find(rijeci.begin(), rijeci.end(), trazenaRijec);
    while (it != rijeci.end()) {
         int index = std::distance(rijeci.begin(), it);
         pozicije.push_back(index);
         std::cout << "Rijec nadena na poziciji " << index << std::endl;
         it = std::find(++it, rijeci.end(), trazenaRijec);
    }

    bool imasubstring(const std::string& str, const std::string& podstring) {
    return str.find(podstring) != std::string::npos;}

    std::string podstring = "prog";
    rijeci.erase(std::remove_if(rijeci.begin(), rijeci.end(), imasubstring), rijeci.end());

    for (std::string& str : rijeci) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    }

    std::copy(rijeci.begin(), rijeci.end(), std::ostream_iterator<std::string>(std::cout, " "));

    otvori.close();
}

int main() {
    zadatak1();
    return 0;
}
