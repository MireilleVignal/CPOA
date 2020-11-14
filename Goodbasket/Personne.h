#ifndef PERSONNE_H
#define PERSONNE_H

#include "coordonnees.h"
#include "GestionnaireProduction.h"

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
