#include "zadatak1.hpp"
#include <iostream>
#include <vector>

void funkcija1(vector<int> &v, int n) {
    int broj;
    cout << "Unesite brojeve za prvi vektor\n";
    for (int i = 0; i < n; i++) {
            cin >> broj;
            v.push_back(broj);
}}

void ispis1(vector<int> &v)
{
    cout << "Ispis prvog vektora\n";
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
}

void funkcija2(vector<int> &vec, int a, int b)
{
    int br;
    cout << "\n" << "Unesite brojeve za drugi vektor\n";
    while(1) {
            cin >> br;
            if(br > a && br < b){
            vec.push_back(br);
            }
            if(br < a || br > b)
            {
                break;
            }
}}
void ispis2(vector<int> &vec)
{
    cout << "Ispis drugog vektora\n";
    vector<int>::iterator iti;
    for (iti = vec.begin(); iti != vec.end(); ++iti)
        cout << *iti << " ";
}
