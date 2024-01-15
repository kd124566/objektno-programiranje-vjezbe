#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool funkcijaslova(char a, char b) {
    return tolower(a) < tolower(b);
}
template <typename T>
void sortiraj(T* niz, int velicina) {
    sort(niz, niz + velicina);
}

template <>
void sortiraj<char>(char* niz, int velicina) {
    sort(niz, niz + velicina, funkcijaslova);
}

int main() {
    int brojevi[] = { 5, 2, 8, 1, 3 };
    int velicinaBr = sizeof(brojevi) / sizeof(brojevi[0]);
    sortiraj(brojevi, velicinaBr);

    cout << "Sortirani niz: ";
    for (int i = 0; i < velicinaBr; i++) {
        cout << brojevi[i] << " ";
    }
    cout << endl;

    char slova[] = { 'c', 'B', 'a', 'D' };
    int velicinaSl = sizeof(slova) / sizeof(slova[0]);
    sortiraj(slova, velicinaSl);

    cout << "Sortirani niz2: ";
    for (int i = 0; i < velicinaSl; i++) {
        cout << slova[i] << " ";
    }
    cout << endl;
    return 0;
}
