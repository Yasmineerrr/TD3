#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Personne {
    string nom;
    string prenom;
    int age;

    bool operator<(const Personne& autre) const {
        if (nom == autre.nom) {
            return prenom < autre.prenom;
        }
        return nom < autre.nom;
    }
};

void afficherPersonnes(const list<Personne>& personnes) {
    for (const Personne& p : personnes) {
        cout << "Nom : " << p.nom << ", Prénom : " << p.prenom << ", Âge : " << p.age << endl;
    }
}

int main() {
    list<Personne> personnes;
    int nombrePersonnes;

    cout << "Entrez le nombre de personnes : ";
    cin >> nombrePersonnes;

    for (int i = 0; i < nombrePersonnes; i++) {
        Personne p;
        cout << "Entrez le nom de la personne " << i + 1 << " : ";
        cin >> p.nom;
        cout << "Entrez le prénom de la personne " << i + 1 << " : ";
        cin >> p.prenom;
        cout << "Entrez l'âge de la personne " << i + 1 << " : ";
        cin >> p.age;
        personnes.push_back(p);
    }

    personnes.sort();

    cout << "Liste triée par nom et prénom : " << endl;
    afficherPersonnes(personnes);

    return 0;
}
