#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

void funkcija3(vector<string>& vektor)
{
    string str;
    for(int i = 0; i < 2; i++){
        cout << "Unesite string: ";
        getline (cin, str);
    }
    vektor.push_back(str);

     for (string &str : vektor) {
        string rev;
        int len = str.length();
        for (int i = len - 1; i >= 0; i--) {
                rev.push_back(str[i]);
        }
        str = rev;
     }
        for (int i = 0; i < vektor.size(); i++) {
        for (int j = i + 1; j < vektor.size(); j++) {
            if (vektor[i] > vektor[j]) {
                swap(vektor[i], vektor[j]);
            }}}
}
int main()
{
    vector<string> vektor;
    funkcija3(vektor);
    for (string &str : vektor) {
        cout << str << endl;
    }
    return 0;
}
