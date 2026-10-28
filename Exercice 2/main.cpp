
#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    float prixHT;

    static float tauxTVA;

public:
    // Constructeur
    Produit(string n, float prix) {
        nom = n;
        prixHT = prix;
    }

    // Calculer le prix TTC
    float getPrixTTC() {
        return prixHT * (1 + tauxTVA / 100);
    }

    // Modifier le taux de TVA pour tous les produits
    static void modifierTVA(float nouveauTaux) {
        tauxTVA = nouveauTaux;
    }

    // Afficher les informations du produit
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Prix HT : " << prixHT << " DH" << endl;
        cout << "Prix TTC : " << getPrixTTC() << " DH" << endl;
        cout << "-------------------" << endl;
    }
};

// Initialisation du taux de TVA a 20 %
float Produit::tauxTVA = 20.0;

int main() {
    Produit p1("Ordinateur", 5000);
    Produit p2("Clavier", 200);
    Produit p3("Souris", 100);

    cout << "=== TVA initiale : 20 % ===" << endl;
    p1.afficher();
    p2.afficher();
    p3.afficher();

    // Modifier le taux de TVA a 10 %
    Produit::modifierTVA(10);

    cout << "\n=== TVA modifiee : 10 % ===" << endl;
    p1.afficher();
    p2.afficher();
    p3.afficher();

    return 0;
}
