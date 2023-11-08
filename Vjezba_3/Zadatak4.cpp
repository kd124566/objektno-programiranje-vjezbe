#include <iostream>
#include <vector>

using namespace std;

void ukloni(vector<int>& v, int len){
    for(int i = 0; i < len; i++)
    {
        v[i] = 0;
        v.pop_back();
    }

}
int main()
{
    vector<int> v {2, 1, 3};
    int len = v.size();
    ukloni(v, len);
    int duljina = v.size();
    for(int i = 0; i < duljina; i++)
    {
        cout << "modificirani niz: " << v[i] << "\n";
    }
    if(duljina == 0)
    {
        cout << "vektor je prazan";
    }

    return 0;
}
