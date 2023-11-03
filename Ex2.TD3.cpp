#include <iostream>
#include <list>
using namespace std;

void afficherListe(const list<int>& maListe) {
    for (const int& element : maListe) {
        cout << element << " ";
    }
    cout << endl;
}

void triABulles(list<int>& maListe) {
    int n = maListe.size();
    bool echange;
    do {
        echange = false;
        auto it1 = maListe.begin();
        auto it2 = next(it1);
        for (int i = 0; i < n - 1; i++) {
            if (*it1 > *it2) {
                swap(*it1, *it2);
                echange = true;
            }
            it1++;
            it2++;
        }
        n--;
    } while (echange);
}

void triParSelection(list<int>& maListe) {
    for (auto it1 = maListe.begin(); it1 != prev(maListe.end()); it1++) {
        auto minimum = it1;
        for (auto it2 = next(it1); it2 != maListe.end(); it2++) {
            if (*it2 < *minimum) {
                minimum = it2;
            }
        }
        if (minimum != it1) {
            swap(*it1, *minimum);
        }
    }
}

void triParInsertion(list<int>& maListe) {
    for (auto it1 = next(maListe.begin()); it1 != maListe.end(); it1++) {
        int element = *it1;
        auto it2 = it1;
        while (it2 != maListe.begin() && *(prev(it2)) > element) {
            *it2 = *(prev(it2));
            it2--;
        }
        *it2 = element;
    }
}

int main() {
    list<int> maListe;
    int n, element;

    cout << "Entrez le nombre d'entiers : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Entrez l'entier " << i + 1 << " : ";
        cin >> element;
        maListe.push_back(element);
    }

    cout << "Liste non triée : ";
    afficherListe(maListe);


    triABulles(maListe);
    cout << "Tri à bulles : ";
    afficherListe(maListe);


    maListe.clear();
    for (int i = 0; i < n; i++) {
        cout << "Entrez l'entier " << i + 1 << " : ";
        cin >> element;
        maListe.push_back(element);
    }


    triParSelection(maListe);
    cout << "Tri par sélection : ";
    afficherListe(maListe);


    maListe.clear();
    for (int i = 0; i < n; i++) {
        cout << "Entrez l'entier " << i + 1 << " : ";
        cin >> element;
        maListe.push_back(element);
    }


    triParInsertion(maListe);
    cout << "Tri par insertion : ";
    afficherListe(maListe);

    return 0;
}
