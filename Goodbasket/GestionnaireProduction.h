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


    /// @brief Cette méthode permet de modifier le nom du produit.
    ///
    /// @param n le nouveau nom
    ///
    /// @see   Nom.
    void modifNom(std::string n){
        Nom = n;
    }

    /// @brief Cette méthode permet de modifier la quantite du produit.
    ///
    /// @param q la nouvelle quantité
    ///
    /// @see   Quantite.
    void modifQuantite(int q){
        Quantite = q;
    }

    /// @brief Cette méthode permet de modifier le prix du produit.
    ///
    /// @param p le nouveau prix
    ///
    /// @see   Prix.
    void modifPrix(float p){
        Prix = p;
    }
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

  /// @brief Cette méthode permet d'ajouter plusieurs exemplaire d'un produit à la liste
  ///
  /// @see lesProduits.
  virtual void ajouterProduits(Produit p, int nb) {
      if(verifierQP(p.quantite(), p.prix()) && verifierProduits(p.nom())){
          lesProduits.push_back(p);
          lesProduits[lesProduits.size()-1].modifQuantite(nb);
      }
      //Message d'erreur
  }

    /// @brief Cette méthode permet de verifier que la quantite et les prix sont valides
    ///
    ///@param quantite la quantite a vérifier
    /// @param prix le prix à vérifier
    ///
    /// @return vrai si la quantite et les prix sont coohérents
    ///
    /// @see   Quantite, Prix.
    bool verifierQP(int quantite, float prix){
        if(quantite > 0 && prix > 0)
            return true;
        return false;
    }

    /// @brief Cette méthode permet de verifier que le nom du produit
    ///         n'existe pas déjà.
    ///
    /// @param n le nom a verifier
    ///
    /// @return vrai si le nom n'existe pas
    ///
    /// @see   lesProduits.
    bool verifierProduits(std::string n){
        for(Produit p : lesProduits){
            if(p.nom() == n){
                return false;
            }
        }
        return true;
    }

    /// @brief Cette méthode permet de suprimer un produit de la liste
    ///
    /// @param p le produit à supprimer
    ///
    /// @see   lesProduits.
    virtual void SupprimerProduit(Produit p) {
        if(produitNom(p.nom()) != -1)
            lesProduits.erase(lesProduits.begin() + produitNom(p.nom()));
    }


    //--------------------------------------------AFFICHAGE--------------------------------------------


    void   decrit(std::ostream &os)
      { for(int i = 0; i< nbProduit();i++){
             os << i + 1 <<".  " << lesProduits[i].nom()<< "\t Quantité : " << lesProduits[i].quantite() << "\t Le Prix : " << lesProduits[i].prix() << "€" <<"\n" ;

        }
            }

      /// @brief Cette méthode retourne la description de la personne
      ///
      /// @return  la description (nom et prix) de la pizza  (dans une chaîne
      ///           de caractères C++).
      ///
      /// @see  decrit(std::ostream &) const, std::ostringstream,
      ///       std::ostringstream.str().
      std::string decrit()
      { std::ostringstream os;  decrit(os);  return os.str(); }

      /// @brief Cette méthode permet d'affiche la description de la personne
      ///
      /// @param  os  le flot de sortie dans lequel la description
      ///             sera affichée.
      ///
      /// @see  decrit(std::ostream &) const, std::ostream::operator<<(),
      ///       std::endl.
      void  affiche(std::ostream &os)
      { decrit(os); os << std::endl; }


};




#endif // GESTIONNAIREPRODUCTION_H
