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

public:
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





// === Classe : Gestionnaire de Production =====================


class GestionnaireProduction
{
    /// @brief Le produits ddu gestionnaire est un tableau de produit C++.
    std::vector<Produit> lesProduits;

public :
  /// @brief Le constructeur permet de remplir les champs
  ///        de la classe en fonction des paramètres passés.
  virtual ~GestionnaireProduction() {}


  /// @brief   Cette méthode donne le nombre de produit enregistré.
  ///
  /// @return  le nombre de produit enregistré.
  ///
  /// @see     lesProduits.
  int nbProduit(){
      return lesProduits.size();
  }

  /// @brief   Cette méthode donne tous les produits enregistrés.
  ///
  /// @return  tous les produits enregistrés
  ///
  /// @see     lesProduits.
  std::vector<Produit> tousLesProduits(){
      return lesProduits;
  }

  /// @brief   Cette méthode permet de savoir si le produit existe ou non.
  ///
  /// @return  true si le produit existe
  ///
  /// @see     lesProduits.
  bool produitExiste(std::string nom){
      for(int i = 0; i< nbProduit(); i++){
         if(lesProduits[i].nom() == nom)
             return true;
      }
      return false;
  }

  /// @brief   Cette méthode donne l'identifiant d'un produit s'il existe.
  ///
  /// @return  l'indentifiant d'un produit donné
  ///
  /// @see     lesProduits.
  int produitNom(std::string nom){
      for(int i = 0; i< nbProduit(); i++){
         if(lesProduits[i].nom() == nom)
             return i;
      }
      return -1;
  }

  /// @brief   Cette méthode donne le produit choisi
  ///
  /// @return  le produit choisi
  ///
  /// @see     lesProduits.
  Produit produitChoix(int i){
     return lesProduits[i];
  }




    /// @brief Cette méthode permet d'ajouter un produit a la liste
    ///
    /// @see   lesProduits.
    virtual void ajouterProduits(Produit p) {
        if (verifierQP(p.quantite(),p.prix()) && verifierProduits(p.nom()))
            lesProduits.push_back(p);
        //mettre un message d'erreur sinon
    }

    /// @brief Cette méthode permet de verifier que la quantite et les prix sont valides
    ///
    /// @return vrai si la quantite et les prix sont coohérents
    ///
    /// @see   Quantite, Prix.
    bool verifierQP(int quantite, float prix){
        if(quantite > 0 && prix > 0)
            return true;
        //afficher un message d'erreur
        return false;
    }

    bool verifierProduits(std::string n){
        for(Produit p : lesProduits){
            if(p.nom() == n){
                //afficher un message pour le nom
                return false;
            }
        }
        return true;
    }


};




#endif // GESTIONNAIREPRODUCTION_H
