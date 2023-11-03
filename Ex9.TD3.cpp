#include <iostream>
using namespace std;

template <class T>
class point {
    T x, y; // coordonnées

public:
    point(T abs, T ord) : x(abs), y(ord) {}

    void affiche() {
        cout << "Coordonnees : " << x << " " << y << endl;
    }
};

int main() {
    // a
    point<char> p1('A', 'B');
    p1.affiche();

    // b
    point<int> p2(60, 65);
    p2.affiche();

    return 0;
}
