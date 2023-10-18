#include <iostream>

using namespace std;

int& refere(int a[], int i)
{
    return a[i];
}
int main()
{
    int a[] = {2, 1, 3, 4, 5};
    int i = 3;

    refere(a, i)++;
    int e = 0;
    while(e < 5)
    {
        cout << a[e] << "\n";

    e++;
    }
}
