#include <iostream>
#include <chrono>
using namespace std;

float debut , fin;

class Noeud{
public:
     int valeur; 
     Noeud* droite;
     Noeud* gauche; 

     Noeud(int v){
        valeur = v; 
         droite = nullptr; 
         gauche = nullptr; 
     }
} ;








class Arbre{

private : 
   Noeud* racine ; 


   Noeud* ajouter(Noeud * crt , int v ){

    if(crt ==nullptr){ return new Noeud(v);}
    if(v < crt-> valeur) {crt->gauche = ajouter(crt->gauche , v);}
    else if(v > crt-> valeur) {crt->droite = ajouter(crt->droite , v);}

    return crt ;
   }

   void afficher(Noeud* crt){
        if(crt != nullptr){
            
            afficher(crt->gauche);
            cout << crt->valeur << " "; 
            afficher(crt->droite);
        }
   }




  bool rechercher(int v) {
    Noeud* courant = racine;

    while (courant != nullptr) {
        if (courant->valeur == v)
            return true;

        if (v < courant->valeur)
            courant = courant->gauche;
        else
            courant = courant->droite;
    }

    return false;
}
  
void chercherChronometre(int v) {
   auto debut = chrono::high_resolution_clock::now();

    bool trouve = rechercher(v);

    auto fin = chrono::high_resolution_clock::now();

    auto duree = chrono::duration_cast<chrono::nanoseconds>(
        fin - debut
    ).count();


    if (trouve) {
        cout << "Element " << v << " trouve dans l'arbre." << endl;
    } else {
    
        cout << "Element " << v << " non trouve dans l'arbre." << endl;
    }
    cout << "Temps de recherche : " << duree/1000.0 << " microsecondes." << endl; 
}

 




   




public:
    Arbre() {
        racine = nullptr;
    }

    void ajouter() {

         auto debut = chrono::high_resolution_clock::now();
         
         for(int i = 0; i < 10000 ; i++) {
              racine = ajouter(racine, rand() % 10000);
            }
            auto fin = chrono::high_resolution_clock::now();

    auto duree = chrono::duration_cast<chrono::nanoseconds>(
        fin - debut
    ).count();


     cout << "Temps de d insertion  : " << duree/1000.0 << " microsecondes." << endl;
         
    }

    void afficher() {
        afficher(racine);
        cout << endl;
    }

    void chercher(int v) {
        chercherChronometre(v);
    }


} ; 



int main() {
    Arbre arbre;
    int choix, valeur;

    do {
        cout << "\n--- MENU ARBRE BINAIRE ---\n";
        cout << "1. Remplir l'arbre par des valeurs aleatoires\n";
        cout << "2. Afficher l'arbre\n";
        cout << "3. Chercher un element\n";
        cout << "0. Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
        case 1:
            arbre.ajouter();
            break;

        case 2:
            cout << "Elements dans l'ordre croissant : ";
            arbre.afficher();
            break;
        case 3:
            cout << "Donner la valeur a chercher : ";
            cin >> valeur;
            arbre.chercher(valeur); 

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
