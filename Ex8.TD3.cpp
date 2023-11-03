#include <iostream>
using namespace std;

template <typename T>
T carre(T valeur) {
    return valeur * valeur;
}

int main() {
    int entier = 5;
    double reel = 3.5;

    cout << "Carré de l'entier : " << carre(entier) << endl;
    cout << "Carré du réel : " << carre(reel) << endl;

    return 0;
}
