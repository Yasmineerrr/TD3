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
        cout << "Nom : " << p.nom << ", Pr�nom : " << p.prenom << ", �ge : " << p.age << endl;
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
        cout << "Entrez le pr�nom de la personne " << i + 1 << " : ";
        cin >> p.prenom;
        cout << "Entrez l'�ge de la personne " << i + 1 << " : ";
        cin >> p.age;
        personnes.push_back(p);
    }

    personnes.sort();

    cout << "Liste tri�e par nom et pr�nom : " << endl;
    afficherPersonnes(personnes);

    return 0;
}
