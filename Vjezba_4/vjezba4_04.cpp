
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string prijevodrijeci(string &rijec) {
    char prvi = tolower(rijec[0]);

    if (prvi == 'a' || prvi == 'e' || prvi == 'i' || prvi == 'o' || prvi == 'u') {
        return rijec + "hay";
    } else {
        size_t poz = rijec.find_first_of("aeiou");

        if (poz != string::npos) {
            return rijec.substr(poz) + rijec.substr(0, poz) + "ay";
        } else {
            return rijec + "ay";
        }
    }
}

void unosenje(vector<string> &vek) {
    for (int i = 0; i < 2; i++) {
        string str;
        cout << "Unesite string: ";
        getline(cin, str);

        for (char &slovo : str) {
            slovo = tolower(slovo);
        }

        vek.push_back(str);
    }

    for (string &recenica : vek) {
        string Recenica;
        string rijec;
        for (char slovo : recenica) {
            if (isalpha(slovo) || slovo == '\'') {
                rijec.push_back(slovo);
            } else {
                if (!rijec.empty()) {
                    Recenica += prijevodrijeci(rijec) + slovo;
                    rijec.clear();
                } else {
                    Recenica += slovo;
                }
            }
        }
        recenica = Recenica;
    }}

int main() {
    vector<string> vek;

    unosenje(vek);

    cout << "Prevedene recenice:\n";
    for (string &Recenica : vek) {
        cout << Recenica << "\n";
    }
    srand(time(0));
    int sl  = rand() % vek.size();
    cout << "Slucajna recenica: " << vek[sl] << "\n";

    return 0;
}
