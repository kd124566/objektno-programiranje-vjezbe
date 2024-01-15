
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T>
class Skup {
private:
    vector<T> elementi;
public:
    void dodaj(const T& element) {
        if (!provjera(element)) {
            elementi.push_back(element);
            cout << "Element " << element << " dodan" << endl;
        }
        else {
            cout << "Element postoji." << endl;
        }
    }
    void izbaci(const T& element) {
        typename vector<T>::iterator it = find(elementi.begin(), elementi.end(), element);

        if (it != elementi.end()) {
            elementi.erase(it);
            cout << "Element " << element << " izbacen" << endl;
        }
        else {
            cout << "Element nije naden" << endl;
        }
    }

    bool provjera(const T& element) const {
        return find(elementi.begin(), elementi.end(), element) != elementi.end();
    }
};
int main() {
    Skup<int> skup;
    skup.dodaj(5);
    skup.dodaj(10);
    skup.dodaj(5);
    skup.izbaci(10);
    skup.izbaci(8);
    return 0;
}
