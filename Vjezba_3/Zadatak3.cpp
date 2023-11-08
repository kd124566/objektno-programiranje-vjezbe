#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v {2, 1, 3};
    int len = v.size();
    int najm = v[0];
    int brojac = 0;
    for(int i = 0; i < len; i++)
    {
        cout << "originalni niz: "<< v[i] << "\n";
        brojac += v[i];
        if(v[i] < najm)
        {
            najm = v[i];
        }
    }
    sort(v.begin(), v.end());
    v.push_back(brojac);
    v.insert(v.begin(), 0);
    int duljina = v.size();
    for(int i = 0; i < duljina; i++)
    {
        cout << "modificirani niz" << v[i] << "\n";
    }

    return 0;
}
