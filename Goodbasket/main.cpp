#include <iostream>

#include "Personne.h"
#include "responspc.h"
#include "GestionnaireConnexion.h"

using namespace std;

//Tous les cas d'utilisation des clients


/// @brief Cette méthode permet de proposer des produits
Personne proposerDesProduits(Personne p){
    std::string nom = "";
    int quantite = 0;
    float prix = 0;
    while (nom == "") {
        cout << "Quel est le nom de votre produit ? ->  " << endl;
        cin >> nom;
    }
    while (quantite <= 0) {
        cout << "Quel est la quantité de votre produit ? ->  " << endl;
        cin >> quantite;
    }
    while (prix <= 0) {
        cout << "Quel est le prix de votre produit ? ->  " << endl;
        cin >> prix;
    }
    p.proposerProduit(nom, quantite, prix);
    cout << "Produit ajouté ! MERCI :) " << endl;

    return p;
}

/// @brief Cette méthode permet d'ouvrir un vente
void ouvrirUneVente(ResponsPC r){
        r.ajoutProd();
        r.ouvertureVente();

        if(r.vente)
            cout << "La vente est ouverte ! MERCI :) " << endl;
        else
            cout << "Il ne doit pas y avoir de produit enrefistré car la vente est toujours fermé ! " << endl;

}


/// @param  argc  nombre de paramètres du programme (non utilisé),
/// @param  argv  paramètres du programme (non utilisé).
///
/// @return  0 (OK).
///
/// @version 1a
int main()
{

    //le numéro de téléphone ne peut pas commencer par un 0 ATTENTION
    Coordonnees c("patrick.durant@gmail.fr","4 route du sud", 54500, "Vandoeuvre les nancy", 625143625, "codeXY");
    Personne pers("Durant", "Patrick", c,'P');


    GestionnaireConnexion utilisateurs;

    pers.affiche(std::cout);


    cout << "Vous pouvez proposer des produits : \n" <<endl;

    pers = proposerDesProduits(pers);


    //a la déconnexion :
    utilisateurs.ajouterPers(pers);

    ResponsPC respons("lolo.marie@gmail.fr", "cocoLasticot", utilisateurs);
    ouvrirUneVente(respons);


    //Demander l'inscription ou la connexion

    return 0;
}
