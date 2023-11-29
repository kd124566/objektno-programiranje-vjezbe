#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class karta
{public:
    int broj;
    int zog;
};
class deck
{public:
    vector<karta> nizkarata;
    void promijesajKarte()
    {
        random_shuffle(nizkarata.begin(), nizkarata.end());
    }

    vector<karta> podijeliKarte(int brojigraca)
{
    int brkarata = 10;

    vector<karta> ruka;

    for (int i = 0; i < brojigraca; i++)
    {
        for(int j = 0; j < brkarata; j++)
        {
        ruka.push_back(nizkarata[i * 10 + j]);
    }}
    nizkarata.erase(nizkarata.begin(), nizkarata.begin() + brkarata * brojigraca);
    return ruka;
}
};
class igrac
{public:
    string ime;
    vector<karta> ruka;
    int broj_bodova;
};

int main()
{
    srand(time(0));
    int brojigraca;
    cout << "unesite broj igraca (2 ili 4): \n";
    cin >> brojigraca;


    vector<igrac> igraci;
    for(int i = 0; i < brojigraca; ++i)
    {
        igrac objekt1;
        cout << "unesite ime igraca: \n";
        cin >> objekt1.ime;
        igraci.push_back(objekt1);
    }

    deck objekt2;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            karta nizkarata;
            nizkarata.broj = i;
            nizkarata.zog = j;
            objekt2.nizkarata.push_back(nizkarata);
        }
    }
    objekt2.promijesajKarte();
    cout << "Prije podjele ima " << objekt2.nizkarata.size() << " karata" << endl;

for (int i = 0; i < brojigraca; i++)
{
    igraci[i].ruka = objekt2.podijeliKarte(1);
}

cout << "Nakon podjele ima " << objekt2.nizkarata.size() << " karata" << endl;

    for (int i = 0; i < brojigraca; i++)
    {
        cout << igraci[i].ime << "\n";
        for (int j = 0; j < 10; j++)
        {
            cout << "karta " << igraci[i].ruka[j].broj << " " << "zog " << igraci[i].ruka[j].zog << "\n";
        }
        cout << "\n";
    }
    igrac objekt3;
    objekt3.broj_bodova = 0;
    int brojac1 = 0;
    int brojac2 = 0;
    int brojac3 = 0;
    for (int i = 0; i < brojigraca; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(igraci[i].ruka[j].broj == 1 && igraci[i].ruka[j].broj == 2 && igraci[i].ruka[j].broj == 3)
            {
                if(igraci[i].ruka[j].zog == 1 || igraci[i].ruka[j].zog == 2 || igraci[i].ruka[j].zog == 3 || igraci[i].ruka[j].zog == 4)
                {
                    objekt3.broj_bodova+=3;
                }
            }
            if(igraci[i].ruka[j].broj == 1){
                    if(igraci[i].ruka[j].zog == 1 || igraci[i].ruka[j].zog == 2 || igraci[i].ruka[j].zog == 3 || igraci[i].ruka[j].zog == 4){
                brojac1 +=1;
        }}


            if(igraci[i].ruka[j].broj == 2){
                    if(igraci[i].ruka[j].zog == 1 || igraci[i].ruka[j].zog == 2 || igraci[i].ruka[j].zog == 3 || igraci[i].ruka[j].zog == 4){
                brojac2 +=1;

            }}


            if(igraci[i].ruka[j].broj == 3){
                    if(igraci[i].ruka[j].zog == 1 || igraci[i].ruka[j].zog == 2 || igraci[i].ruka[j].zog == 3 || igraci[i].ruka[j].zog == 4){
                brojac3 +=1;

            }}}


            if(brojac1 == 3 || brojac2 == 3 || brojac3 == 3 )
            {
                objekt3.broj_bodova+=3;
            }
            if(brojac1 == 4 || brojac2 == 4 || brojac3 == 4)
            {
                objekt3.broj_bodova+=4;
            }
        cout << "\n";
        cout << "bodovi iz akuze: \n" << objekt3.broj_bodova;
        objekt3.broj_bodova = 0;
        brojac1 = 0;
        brojac2 = 0;
        brojac3 = 0;
}
    return 0;
}











