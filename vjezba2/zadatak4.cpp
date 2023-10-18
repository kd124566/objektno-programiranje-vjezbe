#include <iostream>
#include <ctime>

using namespace std;
struct matrica {
    int m, n;
    float** brojevi;
};

matrica unosMatrice() {
    matrica x;
    cout << "Unesite broj redaka: ";
    cin >> x.m;
    cout << "Unesite broj stupaca: ";
    cin >> x.n;

    x.brojevi = new float*[x.m];
    for(int i = 0; i < x.m; i++) {
        x.brojevi[i] = new float[x.n];
        for(int j = 0; j < x.n; j++) {
            cout << "Unesite brojeve [" << i << "][" << j << "]: ";
            cin >> x.brojevi[i][j];
        }
    }
    return x;
}

matrica generirajMatricu(int m, int n, float a, float b) {
    matrica x;
    x.m = m;
    x.n = n;
    x.brojevi = new float*[m];
    srand(time(0));
    for(int i = 0; i < m; i++) {
        x.brojevi[i] = new float[n];
        for(int j = 0; j < n; j++) {
            x.brojevi[i][j] = a + (rand() / (float)RAND_MAX) * (b - a);
        }
    }
    return x;
}

matrica zbroj(matrica x, matrica y) {
    if(x.m != y.m || x.n != y.n) {
        cout << "Dimenzije nisu iste";
    }

    matrica z;
    z.m = x.m;
    z.n = x.n;
    z.brojevi = new float*[z.m];
    for(int i = 0; i < z.m; i++) {
        z.brojevi[i] = new float[z.n];
        for(int j = 0; j < z.n; j++) {
            z.brojevi[i][j] = x.brojevi[i][j] + y.brojevi[i][j];
        }
    }
    return z;
}

matrica oduzimanje(matrica x, matrica y) {
    if (x.m != y.m || x.n != y.n) {
        cout << "Dimenzije nisu iste!";
    }

    matrica z;
    z.m = x.m;
    z.n = x.n;
    z.brojevi = new float*[z.m];
    for (int i = 0; i < z.m; i++) {
        z.brojevi[i] = new float[z.n];
        for (int j = 0; j < z.n; j++) {
            z.brojevi[i][j] = x.brojevi[i][j] - y.brojevi[i][j];
        }
    }
    return z;
}

matrica mnozenje(matrica x, matrica y) {
    if (x.n != x.m) {
        cout << "Ne mogu se mnoziti";
    }

    matrica z;
    z.m = x.m;
    z.n = y.n;
    z.brojevi = new float*[z.m];
    for (int i = 0; i < z.m; i++) {
        z.brojevi[i] = new float[z.n];
        for (int j = 0; j < z.n; j++) {
            z.brojevi[i][j] = 0;
            for (int k = 0; k < x.n; k++) {
                z.brojevi[i][j] += x.brojevi[i][k] * y.brojevi[k][j];
            }
        }
    }
    return z;
}

matrica transponiranje(matrica x) {
    matrica y;
    y.m = x.n;
    y.n = x.m;
    y.brojevi = new float*[y.m];
    for (int i = 0; i < y.m; i++) {
        y.brojevi[i] = new float[y.n];
        for (int j = 0; j < y.n; j++) {
            y.brojevi[i][j] = x.brojevi[j][i];
        }
    }
    return y;
}


void ispisMatrice(matrica x) {
    for(int i = 0; i < x.m; i++) {
        for(int j = 0; j < x.n; j++) {
            printf("%7.4f ", x.brojevi[i][j]);
        }
    std::cout << std::endl;
    }
}

void oslobodiMemoriju(matrica x) {
    for(int i = 0; i < x.m; i++) {
        delete[] x.brojevi[i];
    }
    delete[] x.brojevi;
}

int main() {
    matrica x = unosMatrice();
    ispisMatrice(x);

    matrica y = generirajMatricu(x.m, x.n, 1.0, 10.0);
    ispisMatrice(y);

    matrica z = zbroj(x, y);
    ispisMatrice(z);

    oslobodiMemoriju(x);
    oslobodiMemoriju(y);
    oslobodiMemoriju(z);

    return 0;
}
