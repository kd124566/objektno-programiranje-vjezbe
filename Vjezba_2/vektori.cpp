
#include <iostream>
using namespace std;

struct vektori {
    int* niz;
    int log;
    int fiz;

    void vector_new(int i) {
        niz = new int[i];
        fiz = 0;
        log = i;
    }

    void vector_delete() {
        delete[] niz;
        niz = 0;
        fiz = 0;
        log = 0;
    }

    void vector_push_back(int x) {
        if (log == fiz) {
            int velicina = log * 2;
            int* novi = new int[velicina];
            for (int i = 0; i < fiz; i++) {
                novi[i] = niz[i];
            }
            delete[] niz;
            niz = novi;
            log = velicina;
        }
        niz[fiz++] = x;
    }

    void vector_pop_back() {
        if (log > 0 && fiz > 0) {
            fiz = fiz - 1;
        }
    }

    int vector_front() {
        if (log > 0 && fiz > 0) {
            return niz[0];
        }
        else{
            return -100;
        }
    }

    int vector_back() {
        if (log > 0 && fiz > 0) {
            return niz[fiz - 1];
        }
        else
        {
            return -200;
        }
    }

    int vector_size() {
        return fiz;
    }
};

int main() {
    vektori v;

    v.vector_new(5);
    cout << "vector new " << v.log << "\n";
    v.vector_push_back(3);
    cout << "vector_push_back " << v.log << "\n";
    v.vector_push_back(4);
    cout << "vector_push_back " << v.log << "\n";
    v.vector_push_back(5);
    cout << "vector_push_back " << v.log << "\n";

    cout << "vector_front " << v.vector_front() << "\n";
    cout << "vector_back " << v.vector_back() << "\n";

    v.vector_pop_back();
    cout << "vector_pop_back " << v.log << "\n";

    cout << "vector_size " << v.vector_size() << "\n";

    v.vector_delete();
    cout << "vector delete " << v.log << "\n";

    return 0;
}


