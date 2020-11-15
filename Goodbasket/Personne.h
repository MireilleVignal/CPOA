#ifndef PERSONNE_H
#define PERSONNE_H

#include "coordonnees.h"
#include "GestionnaireProduction.h"


class Panier{
    //@brief Le gestionnaire de produit du panier du client
    GestionnaireProduction panierProduits;
    //@brief Le prix total du pannier.
    int prixProduits;
    //@brief La quantitée totale des produits dans le panier.
    int quantitePanier;

public:

    /// @brief Le destructeur ne fait rien.
    virtual ~Panier(){}

    /// @brief   Cette méthode donne la liste de tous les produits du panier.
    ///
    /// @return  liste des produits dans le panier.
    ///
    /// @see     panierProduits.
    virtual GestionnaireProduction panierProd() const   { return panierProduits; }

    /// @brief   Cette méthode donne le prix total du panier.
    ///
    /// @return  le prix total du panier.
    ///
    /// @see     prixProduits.
    virtual int prixTotal() const   { return prixProduits; }

    /// @brief   Cette méthode donne la quantite totale du panier.
    ///
    /// @return  la quantité totale du panier.
    ///
    /// @see     quantitePanier.
    virtual int quantiteTotale() const   { return quantitePanier; }


    /// @brief   Cette méthode donne la quantite de produit different
    ///         dans le panier
    ///
    /// @return le nombre de produit different dans le panier(pas par quantité)
    ///
    /// @see     quantitéPanier.
    int nbProdPanier(){
        return panierProduits.nbProduit();
    }

    /// @brief   Cette méthode permet d'ajouter un produit au panier
    ///
    /// @param p le produit à ajouter.
    ///
    /// @see     panierProduits.
    void ajouterProd(Produit p){
        int a = 0;
        Produit prod = p;
        for(int i = 0; i< nbProdPanier(); i++){
            if(panierProduits.tousLesProduits()[i].nom() == p.nom()){
                int q = panierProduits.tousLesProduits()[i].quantite();
                panierProduits.tousLesProduits()[i].modifQuantite(q);
                a++;
                modifPrixT(panierProduits.tousLesProduits()[i].prix() * q);
            }
        }
        if(a == 0){
            prod.modifQuantite(1);
            panierProduits.ajouterProduits(prod);
            modifPrixT(p.prix());
        }

    }

    /// @brief   Cette méthode permet de modifier le prix total du panier.
    ///
    /// @see     prixProduits.
    void modifPrixT(int p){
        int prix = prixTotal();
        prixProduits = prix + p;

    }

    /// @brief   Cette méthode permet de retirer le produit dans sa totalite.
    ///
    /// @param p le produit a retirer
    ///
    /// @see     quantitéPanier.
    void retirerToutProduit(Produit p){
        panierProduits.SupprimerProduit(p);
    }

    /// @brief   Cette méthode permet de retirer une quantite d'un produit
    ///
    /// @param p le produit.
    ///
    /// @see     quantitéPanier.
    void retirerUnProduit(Produit p){
        if(p.quantite() > 1){
            int i = panierProd().produitNom(p.nom());
            panierProduits.produitChoix(i).modifQuantite(p.quantite() - 1);
        }
        panierProduits.SupprimerProduit(p);
    }

};



class Personne
{
    // @brief Le nom de la personne est une chaîne de caractères C++.
    std::string Nom;
    // @brief Le prenom de la personne est une chaîne de caractères C++.
    std::string Prenom;
    // @brief Les coordonnées de la personne sont des Coordonnees
    Coordonnees Coord;
    // @brief Le statut de la personne est un caractères C++.
    char Statut;

public:
    //@brief Le gestionnaire de produit.
    GestionnaireProduction GestProduit;
    //@brief Le panier de la personne.
    Panier panier;


  /// @brief Le constructeur permet de remplir les champs
  ///        de la classe en fonction des paramètres passés.
  ///
  /// @param  nom  le nom de la personne,
  /// @param  prenom  le prenom de la personne,
  /// @param c les coordonnees de la personne,
  /// @param st le statut de la personne.
  ///
  /// @see     Nom, Prenom, Coord, Statut.
  Personne(std::string nom, std::string prenom, Coordonnees c, char st) : Nom(nom), Prenom(prenom), Coord(c), Statut(st){}

  /// @brief Le destructeur ne fait rien.
  virtual ~Personne(){}



    /// @brief   Cette méthode donne le nom du producteur.
    ///
    /// @return  le nom du producteur (dans une chaîne de caractères C++).
    ///
    /// @see     Nom.
    virtual std::string nom() const   { return Nom; }

    /// @brief   Cette méthode donne le prenom du producteur.
    ///
    /// @return  le prenom du producteur (dans une chaîne de caractères C++).
    ///
    /// @see     Prenom.
    virtual std::string prenom() const   { return Prenom; }

    /// @brief   Cette méthode donne les coordonnes du producteur.
    ///
    /// @return  les coordonnes du producteur (dans une chaîne de caractères C++).
    ///
    /// @see     Coord.
    virtual Coordonnees coordon() const   { return Coord; }

    /// @brief   Cette méthode donne le statut de la personne (P,R ou C).
    ///
    /// @return  le statut de la personne (dans un caractères C++).
    ///
    /// @see     Prenom.
    virtual std::string statut() const   {
      return verifPersonne(Statut);
    }

  void   decrit(std::ostream &os) const
    { os << nom() << " " << prenom() << "\n" << coordon().decrit() << "\n" << statut(); }

    /// @brief Cette méthode retourne la description de la personne
    ///
    /// @return  la description (nom et prix) de la pizza  (dans une chaîne
    ///           de caractères C++).
    ///
    /// @see  decrit(std::ostream &) const, std::ostringstream,
    ///       std::ostringstream.str().
    std::string decrit() const
    { std::ostringstream os;  decrit(os);  return os.str(); }

    /// @brief Cette méthode permet d'affiche la description de la personne
    ///
    /// @param  os  le flot de sortie dans lequel la description
    ///             sera affichée.
    ///
    /// @see  decrit(std::ostream &) const, std::ostream::operator<<(),
    ///       std::endl.
    void  affiche(std::ostream &os) const
    { decrit(os); os << std::endl; }


    //------------------------------------------------------------------------------------------------------------------------

    /// @brief Cette méthode retourne le statut de la personne
    ///
    /// @param c le statut de la personne (correct ou non).
    ///
    /// @return  la statut de la personne.
     std::string verifPersonne(char c) const{
        if(c == 'P' || c == 'p')
            return "Producteur";
        else if (c == 'C' ||  c == 'c')
            return "Consommateur";
        else if (c == 'R' ||  c == 'r')
            return "Responsable";
        return "Mais qui êtes-vous ?";
    }

     std::string verifPersonne(){
        if(Statut == 'P' || Statut == 'p')
            return "Producteur";
        else if (Statut == 'C' ||  Statut == 'c')
            return "Consommateur";
        else if (Statut == 'R' ||  Statut == 'r')
            return "Responsable";
        return "Mais qui êtes-vous ?";
    }

     /// @brief Cette méthode permet au producteur de proposer des
     ///        produits (vérifié si ok en même temps)
     ///
     /// @param n le nom du produit,
     /// @param q la quantité du produit,
     /// @param p le prix du produit.
     ///
     void proposerProduit(std::string n, int q, float p){
         if(verifPersonne(Statut) == "Producteur"){
            GestProduit.ajouterProduits(Produit(n,q,p));
         }
     }

     GestionnaireProduction gestionnaireProd(){
         return GestProduit;
     }

};



#endif // PERSONNE_H
