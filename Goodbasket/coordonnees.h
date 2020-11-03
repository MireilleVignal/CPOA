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
    /// @brief Le numéro de téléphone de la personne est une chaîne de caractères C++.
    int NumTelephone;

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
  Coordonnees(std::string ml, std::string ad, int cd, std::string vl, int nt) :
      Mail(ml), Adresse(ad), CodePostal(cd), Ville(vl), NumTelephone(nt) {}

public:
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
  virtual int numtel() const   { return NumTelephone; }

};


#endif // COORDONNEES_H
