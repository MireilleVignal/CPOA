#include <iostream>

#include "Personne.h"
#include "responspc.h"
#include "GestionnaireConnexion.h"

using namespace std;

//Tous les cas d'utilisation des clients


/// @brief Cette méthode permet de proposer des produits
///
/// @param p la personne proposant des produits
///
/// @return la personne (pour garder les changements en mémoire)
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
///
/// @param r le responsable de l'ouverture de la vente
///
/// @return le responsable (pour garder les changements en mémoire)
ResponsPC ouvrirUneVente(ResponsPC r){
        r.ajoutProd();
        r.ouvertureVente();

        if(r.vente)
            cout << "La vente est ouverte ! MERCI :) " << endl;
        else
            cout << "Il ne doit pas y avoir de produit enrefistré car la vente est toujours fermé ! " << endl;

        return r;
}

/// @brief Cette méthode permet de visualiser tous les produits.
///
/// @param gp le gestionnaire de produit
void consulterLesProduits(GestionnaireProduction gp){
    cout << "La consultation des produits a commencé" << endl;

    gp.affiche(std::cout);
}

/// @brief Cette méthode permet d'ajouter un produit au panier du client
///
/// @param pn le panier du client
/// @param pd le produit à ajouter au panier
void ajouterProduitPanier(Panier pn, Produit pd){
    pn.ajouterProd(pd);
}

/// @brief Cette méthode permet d'ajouter plusieurs exemplaire d'un produit au panier du client
///
/// @param pn le panier du client
/// @param pd le produit à ajouter au panier
/// @param nb le nombre d'exemplaire à ajouter
void ajouterProduitPanier(Panier pn, Produit pd, int nb){
    pn.ajouterProd(pd, nb);
}

/// @brief Cette méthode permet au client de passer sa commande
///
/// @param p le client qui effectue la commande
void effectuerUneCommande(Personne p){
    //afficher le prix total du panier
    p.panier.panierProduits.affiche();
    //affiche le nombre d'article et leur prix
    //demander au client ses coordonnées bancaire pour effectuer le paiement
    //valider le paiement du panier
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
    pers = proposerDesProduits(pers);


    //a la déconnexion :
    utilisateurs.ajouterPers(pers);

    ResponsPC respons("lolo.marie@gmail.fr", "cocoLasticot", utilisateurs);
    respons =  ouvrirUneVente(respons);

    consulterLesProduits(respons.GestProduit);


    //Demander l'inscription ou la connexion

    //Effectuer une commande
    Coordonnees cd("lola.lameche@gmail.com", "3 avenue de la ville", 54500, "Vandoeuvre-lès-Nancy", 639457020, "code YZ");
    Personne client("Lameche", "Lola", cd, 'C');

    ajouterProduitPanier(client.panier, prod);
    ajouterProduitPanier(client.panier, prod, 5);

    return 0;
}
