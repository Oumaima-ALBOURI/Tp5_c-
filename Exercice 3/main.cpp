
#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;

    static int nbUtilisateursConnectes;

public:
    // Constructeur : connexion
    Utilisateur(string n, string r) {
        nom = n;
        role = r;
        nbUtilisateursConnectes++;
    }

    // Destructeur : deconnexion
    ~Utilisateur() {
        nbUtilisateursConnectes--;
    }

    // Methode statique pour acceder au compteur
    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }

    // Afficher les informations
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Role : " << role << endl;
    }
};

// Initialisation de l'attribut statique
int Utilisateur::nbUtilisateursConnectes = 0;

int main() {
    cout << "Nombre initial : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur* u1 = new Utilisateur("Ali", "admin");
    cout << "Apres connexion de Ali : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur* u2 = new Utilisateur("Sara", "visiteur");
    cout << "Apres connexion de Sara : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur* u3 = new Utilisateur("Yassine", "visiteur");
    cout << "Apres connexion de Yassine : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    // Deconnexion de Sara
    delete u2;
    cout << "Apres deconnexion de Sara : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    // Deconnexion de Ali
    delete u1;
    cout << "Apres deconnexion de Ali : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    // Deconnexion de Yassine
    delete u3;
    cout << "Apres deconnexion de Yassine : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    return 0;
}
