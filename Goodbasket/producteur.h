#ifndef PRODUCTEUR_H
#define PRODUCTEUR_H

#include "coordonnees.h"

class Producteur
{
    // @brief Le nom du producteur est une chaîne de caractères C++.
    std::string Nom;
    // @brief Le prenom du producteur est une chaîne de caractères C++.
    std::string Prenom;
    // @brief Les coordonnées du producteur sont des Coordonnees
    Coordonnees Coord;

protected:
  /// @brief Le constructeur permet de remplir les champs
  ///        de la classe en fonction des paramètres passés.
  ///
  /// @param  nom  le nom du producteur,
  /// @param  prenom  le prenom du producteur,
  /// @param c les coordonnees du producteur.
  ///
  /// @see     Nom, Prenom, Coord.
  Producteur(std::string nom, std::string prenom, Coordonnees c) : Nom(nom), Prenom(prenom), Coord(c){}

public:
  /// @brief Le destructeur ne fait rien.
  virtual ~Producteur(){}

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
};

#endif // PRODUCTEUR_H
