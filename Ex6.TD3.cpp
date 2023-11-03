#include <iostream>
#include <cstring>
using namespace std;

class vect {
protected:
    int nelem;
    int* adr;

public:
    vect(int n) : nelem(n), adr(new int[n]) {}

    ~vect() {
        delete[] adr;
    }

    int& operator[](int index) {
        if (index >= 0 && index < nelem) {
            return adr[index];
        }
        throw "Indice hors limites";
    }
};

class vectok : public vect {
public:
    vectok(int n) : vect(n) {}

    vectok(const vectok& other) : vect(other.nelem) {
        memcpy(adr, other.adr, nelem * sizeof(int));
    }

    vectok& operator=(const vectok& other) {
        if (this == &other) {
            return *this;
        }

        if (nelem != other.nelem) {
            delete[] adr;
            nelem = other.nelem;
            adr = new int[nelem];
        }

        memcpy(adr, other.adr, nelem * sizeof(int));
        return *this;
    }

    int taille() const {
        return nelem;
    }
};

int main() {
    vectok v1(5);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1[3] = 4;
    v1[4] = 5;

    cout << "Taille de v1 : " << v1.taille() << endl;

    vectok v2 = v1; // Appel du constructeur par copie
    cout << "Taille de v2 : " << v2.taille() << endl;

    v2[0] = 10;
    v2[1] = 20;
    v2[2] = 30;
    v2[3] = 40;
    v2[4] = 50;

    cout << "v1[0] : " << v1[0] << ", v2[0] : " << v2[0] << endl;

    return 0;
}
