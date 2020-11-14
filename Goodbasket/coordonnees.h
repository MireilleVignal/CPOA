#ifndef COORDONNEES_H
#define COORDONNEES_H

// pour les affichages (des destructeurs)
#include <iostream>
// pour la précision
#include <iomanip>
// pour les flux sur les chaînes de caractères (ostringstream)
#include <sstream>


class Coordonnees
{
    /// @brief Le mail de la personne est une chaîne de caractères C++.
    std::string Mail;
    /// @brief L'adresse de la personne est une chaîne de caractères C++.
    std::string Adresse;
    /// @brief Le le code postal est un entier.
    int CodePostal;
    /// @brief Le nom de la ville de la personne est une chaîne de caractères C++.
    std::string Ville;
    /// @brief Le numéro de téléphone de la personne est un unsigned int.
    unsigned int NumTelephone;
    /// @brief Le Mot de passe de la personne est une chaîne de caractères C++.
    std::string MotDePasse;

public:
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
  /// @param mdp le mot de passe de la personne.
  ///
  /// @see     Mail, Adresse, CodePostal, Ville, NumTelephone, MotDePasse.
  Coordonnees(std::string ml, std::string ad, int cd, std::string vl, unsigned int nt, std::string mdp) :
      Mail(ml), Adresse(ad), CodePostal(cd), Ville(vl), NumTelephone(nt), MotDePasse(mdp) {
      //verifAdresse();
  }

    ///@brief Le destructeur ne fait rien.
  virtual ~Coordonnees() {}


  /// @brief   Cette méthode donne le mail de la personne.
  ///
  /// @return  le mail de la personne (dans une chaîne de caractères C++).
  ///
  /// @see     Mail.
  virtual std::string mail() const   { return Mail; }

  /// @brief   Cette méthode donne l'adresse de la personne.
  ///
  /// @return  l'adresse de la personne (dans une chaîne de caractères C++).
  ///
  /// @see     Adresse.
  virtual std::string adresse() const   { return Adresse; }

  /// @brief   Cette méthode donne le code postal de la personne.
  ///
  /// @return  le code postal de la personne (dans un entier).
  ///
  /// @see     CodePostal.
  virtual int codePostal() const   { return CodePostal; }

  /// @brief   Cette méthode donne la ville de la personne.
  ///
  /// @return  la ville de la personne (dans une chaîne de caractères C++).
  ///
  /// @see     Ville.
  virtual std::string ville() const   { return Ville; }

  /// @brief   Cette méthode donne le numéro de téléphone de la personne.
  ///
  /// @return  le numéro de téléphone de la personne (dans un entier).
  ///
  /// @see     NumTelephone.
  virtual unsigned int numtel() const   { return NumTelephone; }

  /// @brief   Cette méthode donne le mot de passe de la personne.
  ///
  /// @return  le mot de passe de la personne (dans une chaîne de caractères C++).
  ///
  /// @see     MotDePasse.
  virtual std::string motdepas() const   { return MotDePasse; }



  /// @brief Cette méthode vérifie si les coordonées données sont valides ou non
  ///
  /// Ce constructeur est protégé pour que la classe Coordonnees
  /// reste abstraite
  ///
  ///
  /// @see
  bool verifAdresse(){
    if((codePostal()>=01000 && codePostal()< 96000 ) || (codePostal() >= 971000 && codePostal() < 975000)){
        return false;
    }
    return false;
  }



  void   decrit(std::ostream &os) const
    { os << "\t" << mail() << "\n\t" << adresse() <<  "\n\t" << codePostal()
         <<  "\n\t" << ville() <<  "\n\t" << numtel(); }

    /// @brief Cette méthode retourne les coordonnées de la personne
    ///
    /// @return  les coordonnées de la personne (dans une chaîne
    ///           de caractères C++).
    ///
    /// @see  decrit(std::ostream &) const, std::ostringstream,
    ///       std::ostringstream.str().
    std::string decrit() const
    { std::ostringstream os;  decrit(os);  return os.str(); }

    /// @brief Cette méthode permet d'affiche les coordonnées de la personne
    ///         avec un espacement
    ///
    /// @param  os  le flot de sortie dans lequel la description
    ///             sera affichée.
    ///
    /// @see  decrit(std::ostream &) const, std::ostream::operator<<(),
    ///       std::endl.
  void afficher(std::ostream &os) const {
      decrit(os); os << std::endl;

  }

};


#endif // COORDONNEES_H
