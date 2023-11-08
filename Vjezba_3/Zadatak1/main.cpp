#include <iostream>
#include <vector>
#include "zadatak1.hpp"
using namespace std;

int main()
{
    vector<int> v;
    int n = 10;

    funkcija1(v, n);

    ispis1(v);

    vector<int> vec;
    int a = 2;
    int b = 10;

    funkcija2(vec, a, b);

    ispis2(vec);

    return 0;
}
