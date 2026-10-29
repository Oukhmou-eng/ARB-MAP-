#include <iostream>
#include <chrono>
#include <map>
using namespace std;

class Arbre {

private:
    map<int, int> m;   

    void chercherChronometre(int cle) {
        auto debut = chrono::high_resolution_clock::now();

        auto it = m.find(cle);

        auto fin = chrono::high_resolution_clock::now();

        auto duree = chrono::duration_cast<chrono::nanoseconds>(
            fin - debut
        ).count();

        if (it != m.end()) {
            cout << "Cle " << cle << " trouvee, valeur = " << it->second << endl;
        } else {
            cout << "Cle " << cle << " non trouvee dans le map." << endl;
        }
        cout << "Temps de recherche : " << duree / 1000.0 << " microsecondes." << endl;
    }





public:
    void ajouter( int  ) {

        auto debut = chrono::high_resolution_clock::now();
         for (int i = 0; i < 10000; i++) {
             m[i] = rand() % 10000;
                    } 
        auto fin = chrono::high_resolution_clock::now();

    auto duree = chrono::duration_cast<chrono::nanoseconds>(
        fin - debut
    ).count();


     cout << "Temps de d insertion  : " << duree/1000.0 << " microsecondes." << endl;
    }

    void afficher() {
        for (auto& p : m) {
            cout << "[" << p.first << "] = " << p.second << "  ";
        }
        cout << endl;
    }

    void chercher(int cle) {
        chercherChronometre(cle);
    }
};





int main() {
    Arbre arbre;
    int choix, cle;

    do {
        cout << "\n--- MENU MAP ---\n";
        cout << "1. Remplir le map (cles triees, valeurs aleatoires)\n";
        cout << "2. Afficher le map\n";
        cout << "3. Chercher une cle\n";
        cout << "0. Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
        case 1:
            arbre.ajouter();
            break;

        case 2:
            cout << "Elements dans l'ordre des cles : ";
            arbre.afficher();
            break;

        case 3:
            cout << "Donner la cle a chercher : ";
            cin >> cle;
            arbre.chercher(cle);
            break;

        case 0:
            cout << "Fin du programme.\n";
            break;

        default:
            cout << "Choix invalide !\n";
        }

    } while (choix != 0);

    return 0;
}