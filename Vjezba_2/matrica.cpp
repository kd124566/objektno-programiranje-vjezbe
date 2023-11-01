#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct matrica
{
    int m;
    int n;
    float** broj;
};

matrica unos()
{
    matrica unesi;
    unesi.m = 2;
    unesi.n = 2;
    srand(time(0));
    cout << "Unos matrice\n";
    unesi.broj = new float*[unesi.m];
    for(int i = 0; i < unesi.n; i++){
        unesi.broj[i] = new float[unesi.n];
        for(int j = 0; j < unesi.n; j++){
            cout << "Unesite broj: ";
            cin >> unesi.broj[i][j];
}}
    return unesi;
}
matrica generiraj()
{
    matrica gen;
    gen.m = 2;
    gen.n = 2;
    float a = 1.1;
    float b = 4.4;
    cout << "Generirana matrica\n";
    gen.broj = new float*[gen.m];
    for(int i = 0; i < gen.n; i++){
        gen.broj[i] = new float[gen.n];
        for(int j = 0; j < gen.n; j++){

                gen.broj[i][j] = a + (float)rand() / RAND_MAX * (b - a);
        }}
    return gen;
}
matrica zbroj(matrica unesi, matrica gen)
{
    matrica zbr;
    if(unesi.m == gen.m)
    {
        zbr.m = unesi.m;
    }
    else
    {
        cout << "nemoguce zbrojiti, broj redaka nije jednak\n";
    }
    if(unesi.n == gen.n)
    {
        zbr.n = unesi.n;
    }
    else
    {
        cout << "nemoguce zbrojiti, broj stupaca nije jednak\n";
    }
    cout << "Zbrojena matrica\n";
    zbr.broj = new float*[zbr.m];
    for(int i = 0; i < zbr.n; i++){
        zbr.broj[i] = new float[zbr.n];
        for(int j = 0; j < zbr.n; j++){

                zbr.broj[i][j] = unesi.broj[i][j] + gen.broj[i][j];
        }}
    return zbr;

}
matrica oduzmi(matrica unesi, matrica gen)
{
    matrica oduz;
    if(unesi.m == gen.m)
    {
        oduz.m = unesi.m;
    }
    else
    {
        cout << "nemoguce oduzeti, broj redaka nije jednak\n";
    }
    if(unesi.n == gen.n)
    {
        oduz.n = unesi.n;
    }
    else
    {
        cout << "nemoguce oduzeti, broj stupaca nije jednak\n";
    }
    cout << "Oduzeta matrica\n";
    oduz.broj = new float*[oduz.m];
    for(int i = 0; i < oduz.n; i++){
        oduz.broj[i] = new float[oduz.n];
        for(int j = 0; j < oduz.n; j++){

                oduz.broj[i][j] = unesi.broj[i][j] - gen.broj[i][j];
        }}
    return oduz;

}

matrica pomnozi(matrica unesi, matrica gen)
{
    matrica pomn;
    if(unesi.m == gen.m && unesi.n == gen.n )
    {
        pomn.m = unesi.m;
        pomn.n = unesi.n;
    }
    if(unesi.m == gen.n && unesi.n == gen.m)
    {
        pomn.m = unesi.m;
        pomn.n = gen.n;
    }
    else
    {
        cout << "mnozenje nije moguce\n";
    }
    cout << "Pomnozena matrica\n";
    pomn.broj = new float*[pomn.m];
    for(int i = 0; i < pomn.n; i++){
        pomn.broj[i] = new float[pomn.n];
        for(int j = 0; j < pomn.n; j++){
                pomn.broj [i][j] = 0;
                for(int k = 0; k < unesi.n; k++)
                pomn.broj[i][j] += unesi.broj[i][k] * gen.broj[k][j];
        }}
    return pomn;
}
void free(matrica unesi)
{
    for(int i = 0; i < unesi.m; i++)
    {
        delete[] unesi.broj[i];
    }
    delete[] unesi.broj;
}


matrica transponirana(matrica unesi)
{
    matrica transp;
    transp.m = unesi.n;
    transp.n = unesi.m;
    cout << "Transponirana matrica\n";
    transp.broj = new float*[transp.m];
    for(int i = 0; i < transp.m; i++)
    {
        transp.broj[i] = new float[unesi.n];
        for(int j = 0; j < transp.n; j++)
        {
            transp.broj[i][j] = unesi.broj[j][i];
        }
    }
    return transp;
}
void ispisMatrice(matrica pomn) {
    for(int i = 0; i < pomn.m; i++) {
        for(int j = 0; j < pomn.n; j++) {
            printf("%7.4f ", pomn.broj[i][j]);
        }

    }
}


int main()
{

    matrica rez1 = unos();
    matrica rez2 = generiraj();
    ispisMatrice(rez2);
    cout << "\n";
    matrica rez3 = zbroj(rez1, rez2);
    ispisMatrice(rez3);
    cout << "\n";
    matrica rez4 = oduzmi(rez1, rez2);
    ispisMatrice(rez4);
    cout << "\n";
    matrica rez5 = pomnozi(rez1, rez2);
    ispisMatrice(rez5);
    cout << "\n";
    matrica rez6 = transponirana(rez1);
    ispisMatrice(rez6);
    cout << "\n";
    free(rez1);
    free(rez2);
    free(rez3);
    free(rez4);
    free(rez5);
    free(rez6);

    return 0;
}
