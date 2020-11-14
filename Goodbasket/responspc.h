#ifndef RESPONSPC_H
#define RESPONSPC_H

#include "Personne.h"

class ResponsPC
{
public:
    ResponsPC();

    // @brief Le nom de la personne est une chaîne de caractères C++.
    std::string Mail;
    // @brief Le prenom de la personne est une chaîne de caractères C++.
    std::string MotDePasse;


    //@brief Le gestionnaire de produit.
    GestionnaireProduction GestProduit;

    //@brief Les producteurs et les consommateurs
    std::vector<Personne> lesUtilisateurs;

    //@brief La vente ouverte ou fermé
    bool vente;

public:
  /// @brief Le constructeur permet de remplir les champs
  ///        de la classe en fonction des paramètres passés.
  ///
  /// @param  m  le mail du reponsable,
  /// @param  mdp  le mot de passe du responsable.
  ///
  /// @see     Mail, MotDePasse.
  ResponsPC(std::string m, std::string mdp) : Mail(m), MotDePasse(mdp) { vente = false;}

  /// @brief Le destructeur ne fait rien.
  virtual ~ResponsPC(){}




  /// @brief   Cette méthode donne le mail de la personne.
  ///
  /// @return  le mail de la personne (dans une chaîne de caractères C++).
  ///
  /// @see     Mail.
  virtual std::string mail() const   { return Mail; }

  /// @brief   Cette méthode donne le mot de passe de la personne.
  ///
  /// @return  le mot de passe de la personne (dans une chaîne de caractères C++).
  ///
  /// @see     MotDePasse.
  virtual std::string motdepas() const   { return MotDePasse; }


  void   decrit(std::ostream &os) const
    { os << mail() << " \n" << motdepas() << "\n" ; }

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

    /// @brief   Cette méthode donne le Gestionnaire de tous les produits present.
    ///
    /// @return  le Gestionnaire de produit.
    ///
    /// @see     GestProduit.
     GestionnaireProduction gestionnaireProd(){
         return GestProduit;
     }

     /// @brief   Cette méthode donne la liste de tous les utilisateurs
     ///            de la plateforme.
     ///
     /// @return  les utilisateurs.
     ///
     /// @see     lesUtilisateurs.
     std::vector<Personne> utilisateurs(){
         return lesUtilisateurs;
     }


     /// @brief   Cette méthode donne le nombre d'utilisateur enregistré.
     ///
     /// @return  le nombre d'utilisateur enregistré.
     ///
     /// @see     lesUtilisateurs.
     int nbUtilisateur(){
         return lesUtilisateurs.size();
     }

     /// @brief   Cette méthode permet de savoir si l'utilisateur existe ou non.
     ///
     /// @param  p la personne
     ///
     /// @return  true s'il existe
     ///
     /// @see     lesUtilisateurs.
     bool utilisateurExiste(Personne p){
         for(int i = 0; i< nbUtilisateur(); i++){
            if(lesUtilisateurs[i].coordon().mail() == p.coordon().mail())
                return true;
         }
         return false;
     }

     /// @brief   Cette méthode donne l'identifiant d'un utilisateur s'il existe.
     ///
     /// @param nom le nom de l'utilisateur choisi
     ///
     /// @return  l'indentifiant d'un utilissateur donné
     ///
     /// @see     lesUtilisateurs.
     int utilisateurNom(std::string nom){
         for(int i = 0; i< nbUtilisateur(); i++){
            if(lesUtilisateurs[i].nom() == nom)
                return i;
         }
         return -1;
     }

     /// @brief   Cette méthode donne l'utilisateur choisi
     ///
     /// @param i l'identifiant de l'utilisateur choisi
     ///
     /// @return  l'utilisateur choisi
     ///
     /// @see     lesutilisateur.
     Personne utilisateurChoix(int i){
        return lesUtilisateurs[i];
     }

     //-------------------------------------------------------------------------------------------------------------------------------

     /// @brief Cette méthode permet d'ouvrir un vente
     ///
     /// @see  GestProduit, vente.
     void ouvertureVente (){
         if(GestProduit.nbProduit() >= 1){
             vente = true;
         }
         else{
             ajoutProd();
         }
     }

     /// @brief Cette méthode permet d'ajouter tous les produits
     ///        de tous les producteurs dans une seule liste
     ///
     /// @see  GestProduit, lesUtilisateurs.
     void ajoutProd () {
         for(int i = 0; i < nbUtilisateur(); i++){
             if (lesUtilisateurs[i].verifPersonne() == "Producteur"){
                 for(int j = 0; j <lesUtilisateurs[i].gestionnaireProd().nbProduit(); j++)
                 GestProduit.ajouterProduits(lesUtilisateurs[i].gestionnaireProd().produitChoix(j));
             }
         }
     }
};

#endif // RESPONSPC_H
