#include <iostream>
#include <set>
#include <vector>
#include <list>
using namespace std;

template <typename T>
    set<T> creerSetDe1A100() {
    set<T> monSet;
    for (T i = 1; i <= 100; i++) {
        monSet.insert(i);
    }
    return monSet;
}

template <typename InputIterator, typename T>
bool recherche(const InputIterator& debut, const InputIterator& fin, const T& valeur) {
    for (InputIterator it = debut; it != fin; ++it) {
        if (*it == valeur) {
            return true;
        }
    }
    return false;
}

int main() {

    // 1
    vector<string> vecteurStrings = {"apple", "banana", "cherry", "date", "fig"};
    string valeurString = "cherry";
    bool trouveString = recherche(vecteurStrings.begin(), vecteurStrings.end(), valeurString);
    if (trouveString) {
        cout << "La valeur \"" << valeurString << "\" a été trouvée dans le vecteur de strings." <<endl;
    } else {
        cout << "La valeur \"" << valeurString << "\" n'a pas été trouvée dans le vecteur de strings." <<endl;
    }

    // 2
    list<int> listeEntiers = {10, 20, 30, 40, 50};
    int valeurEntier = 30;
    bool trouveEntier = recherche(listeEntiers.begin(), listeEntiers.end(), valeurEntier);
    if (trouveEntier) {
        cout << "La valeur " << valeurEntier << " a été trouvée dans la liste d'entiers." << endl;
    } else {
        cout << "La valeur " << valeurEntier << " n'a pas été trouvée dans la liste d'entiers." << endl;
    }

    // 3
    float tableauFloat[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    float valeurFloat = 2.2f;
    bool trouveFloat = recherche(begin(tableauFloat), end(tableauFloat), valeurFloat);
    if (trouveFloat) {
        cout << "La valeur " << valeurFloat << " a été trouvée dans le tableau de floats." << endl;
    } else {
        cout << "La valeur " << valeurFloat << " n'a pas été trouvée dans le tableau de floats." << endl;
    }

    return 0;
}
