
#include <iostream>
using namespace std;

class Boite {
private:
    double longueur;
    double largeur;
    double hauteur;

    static int nbBoites;

public:
    // Constructeur
    Boite(double l, double lar, double h) {
        longueur = l;
        largeur = lar;
        hauteur = h;
        nbBoites++;
    }

    // Destructeur
    ~Boite() {
        nbBoites--;
    }

    // Methode statique
    static int getNombreBoites() {
        return nbBoites;
    }

    // Afficher les informations
    void afficher() {
        cout << "Longueur : " << longueur << endl;
        cout << "Largeur  : " << largeur << endl;
        cout << "Hauteur  : " << hauteur << endl;
    }
};

// Initialisation de l'attribut statique
int Boite::nbBoites = 0;

int main() {
    Boite b1(10, 5, 3);
    Boite b2(8, 4, 2);
    Boite b3(6, 3, 2);

    cout << "Nombre de boites : "
         << Boite::getNombreBoites() << endl;

    {
        Boite b4(12, 6, 4);

        cout << "Apres creation de b4 : "
             << Boite::getNombreBoites() << endl;
    } // b4 est detruite ici

    cout << "Apres destruction de b4 : "
         << Boite::getNombreBoites() << endl;

    return 0;
}
