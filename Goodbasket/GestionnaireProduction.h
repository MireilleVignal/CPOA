#ifndef GESTIONNAIREPRODUCTION_H
#define GESTIONNAIREPRODUCTION_H


// pour les affichages (des destructeurs)
#include <iostream>
// pour la précision
#include <iomanip>
// pour les flux sur les chaînes de caractères (ostringstream)
#include <sstream>

#include <vector>

// === Classe concrète : produit =====================

/** @brief La classe Produit est un produit du producteur
 **
 ** Elle donne le nom, le prix et la quantité d'un produit
 **
 ** @author Emeline BONTE
 **/
class Produit{
    /// @brief Le nom du produit est une chaîne de caractères C++.
    std::string Nom;
    /// @brief La quantité est un entier.
    int Quantite;
    /// @brief Le prix est un réel en virgule flottante.
    float Prix;

protected:
    /// @brief Le constructeur permet de remplir les champs
    ///        de la classe en fonction des paramètres passés.
    ///
    /// Ce constructeur est protégé pour que la classe GestionnaireProduit
    /// reste abstraite
    ///
    /// @param nom le nom du produit,
    /// @param quantite la quantite du produit,
    /// @param prix le prix du produit.
    ///
    /// @see     Nom, Quantite, Prix.
    Produit(std::string nom,int quantite, float prix) : Nom(nom), Quantite(quantite), Prix(prix) {}

public:
    ///@brief Le destructeur ne fait rien.
  virtual ~Produit() {}


    /// @brief   Cette méthode donne le nom du produit.
    ///
    /// @return  le nom du produit (dans une chaîne de caractères C++).
    ///
    /// @see     Nom.
    virtual std::string nom() const   { return Nom; }

    /// @brief   Cette méthode donne la quantite du produit.
    ///
    /// @return  la quantite du produit (dans un entier).
    ///
    /// @see     Nom.
    virtual int quantite() const   { return Quantite; }

    /// @brief   Cette méthode donne le prix du produit.
    ///
    /// @return  le prix du produit (dans un réel en virgule flottante).
    ///
    /// @see     Prix.
    virtual float      prix() const   { return Prix; }
};








class GestionnaireProduction
{
    /// @brief Le produits ddu gestionnaire est un tableau de produit C++.
    std::vector<Produit> lesProduits;

protected:
  /// @brief Le constructeur permet de remplir les champs
  ///        de la classe en fonction des paramètres passés.
  ///
  /// Ce constructeur est protégé pour que la classe Coordonnees
  /// reste abstraite
  ///
  /// @param ml le mail de la personne,
  /// @param ad l'adresse de la personne
  /// @param cd le code postal de la personne
  /// @param vl la ville de la personne
  /// @param nt le numéro de téléphone de la personne
  ///
  /// @see     Mail, Adresse, CodePostal, Ville, NumTelephone.
  GestionnaireProduction();

public :

    /// @brief Cette méthode permet d'ajouter un produit a la liste
    ///
    /// @see   lesProduits.
    virtual void ajouterProduits(Produit p) {
        if (verifierQP(p.quantite(),p.prix()))
            lesProduits.push_back(p);
    }

    /// @brief Cette méthode permet de verifier que la quantite et les prix sont valides
    ///
    /// @return vrai si la quantite et les prix sont coohérents
    ///
    /// @see   Quantite, Prix.
    bool verifierQP(int quantite, float prix){
        if(quantite > 0 && prix > 0)
            return true;
        return false;
    }



};




#endif // GESTIONNAIREPRODUCTION_H
