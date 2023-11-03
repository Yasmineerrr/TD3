#include <iostream>
using namespace std;

class NombreComplexe {
private:
    double reel;
    double imaginaire;

public:
    NombreComplexe(double reel, double imaginaire) : reel(reel), imaginaire(imaginaire) {}

    NombreComplexe operator+(const NombreComplexe& autre) const {
        double reel_resultat = reel + autre.reel;
        double imaginaire_resultat = imaginaire + autre.imaginaire;
        return NombreComplexe(reel_resultat, imaginaire_resultat);
    }

    NombreComplexe operator-(const NombreComplexe& autre) const {
        double reel_resultat = reel - autre.reel;
        double imaginaire_resultat = imaginaire - autre.imaginaire;
        return NombreComplexe(reel_resultat, imaginaire_resultat);
    }

    NombreComplexe operator*(const NombreComplexe& autre) const {
        double reel_resultat = reel * autre.reel - imaginaire * autre.imaginaire;
        double imaginaire_resultat = reel * autre.imaginaire + imaginaire * autre.reel;
        return NombreComplexe(reel_resultat, imaginaire_resultat);
    }

    friend ostream& operator<<(ostream& out, const NombreComplexe& nombre) {
        out << nombre.reel << " + " << nombre.imaginaire << "i";
        return out;
    }
};

int main() {
    double reel1, imaginaire1, reel2, imaginaire2;
    cout << "Entrez la partie réelle du premier nombre complexe : ";
    cin >> reel1;
    cout << "Entrez la partie imaginaire du premier nombre complexe : ";
    cin >> imaginaire1;
    cout << "Entrez la partie réelle du deuxième nombre complexe : ";
    cin >> reel2;
    cout << "Entrez la partie imaginaire du deuxième nombre complexe : ";
    cin >> imaginaire2;

    NombreComplexe nombre_complexe1(reel1, imaginaire1);
    NombreComplexe nombre_complexe2(reel2, imaginaire2);

    NombreComplexe addition = nombre_complexe1 + nombre_complexe2;
    NombreComplexe soustraction = nombre_complexe1 - nombre_complexe2;
    NombreComplexe multiplication = nombre_complexe1 * nombre_complexe2;

    cout << "Addition : " << addition << endl;
    cout << "Soustraction : " << soustraction << endl;
    cout << "Multiplication : " << multiplication << endl;

    return 0;
}
