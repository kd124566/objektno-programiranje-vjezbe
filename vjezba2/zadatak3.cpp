
#include <iostream>
using namespace std;

struct vektori {
    int* niz;
    int log;
    int fiz;

    void vector_new(int i = 1) {
        niz = new int[i];
        log = 0;
        fiz = i;
    }

    void vector_delete() {
        delete[] niz;
        niz = 0;
        log = 0;
        fiz = 0;
    }

    void vector_push_back(int x) {
        if (log == fiz) {
            int velicina = fiz * 2;
            int* novo = new int[velicina];
            for (int i = 0; i < log; i++) {
                novo[i] = niz[i];
            }
            delete[] niz;
            niz = novo;
            fiz = velicina;
        }
        niz[log++] = x;
    }

    void vector_pop_back() {
        if (log > 0) {
            log--;
        }
    }

    int vector_front() {
        if (log > 0) {
            return niz[0];
        }
        else
        {
            return -1;
        }
    }

    int vector_back() {
        if (log > 0) {
            return niz[log - 1];
        }
        else
        {
            return -1;
        }
    }

    int vector_size() {
        return log;
    }
};

int main() {
    vektori v;
    v.vector_new(5);
    cout << "vector new " << v.fiz << "\n";
    v.vector_push_back(3);
    cout << "vector_push_back " << v.fiz << "\n";
    v.vector_push_back(4);
    cout << "vector_push_back " << v.fiz << "\n";
    v.vector_push_back(5);
    cout << "vector_push_back " << v.fiz << "\n";

    cout << "vector_front " << v.vector_front() << "\n";
    cout << "vector_back " << v.vector_back() << "\n";

    v.vector_pop_back();
    cout << "vector_pop_back " << v.fiz << "\n";

    cout << "vector_size " << v.vector_size() << "\n";

    v.vector_delete();
    cout << "vector delete " << v.fiz << "\n";

    return 0;
}

