#include <iostream>

using namespace std;

void naj(int a[], int& irefa, int& irefb)
{
    int i = 0;
    while(i < 5)
    {
        cout << a[i] << "\n";
        if(a[i] > irefa)
        {
            irefa = a[i];
        }
        if(a[i] < irefb)
        {
            irefb = a[i];
        }
        i++;
    }
}

int main()
{
    int a[] = {2, 1, 3, 4, 5};
    int najv = a[0];
    int najm = a[0];
    int& irefa = najv;
    int& irefb = najm;

    naj(a, irefa, irefb);
    cout << "najv je " << najv << "\n";
    cout << "najm je" << najm << "\n";
}
