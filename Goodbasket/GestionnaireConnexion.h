#ifndef GESTIONNAIRECONNEXION_H
#define GESTIONNAIRECONNEXION_H

#include "coordonnees.h"

#include <vector>




class GestionnaireConnexion
{
    /// @brief Les inscriptions du gestionnaire sont un tableau de coordonnées C++.
    std::vector<Coordonnees> lesInscriptions;

protected:
  /// @brief Le constructeur permet de remplir les champs
  ///        de la classe en fonction des paramètres passés.
  ///
  /// Ce constructeur est protégé pour que la classe Coordonnees
  /// reste abstraite
  ///
  /// @param c les Coordonnées de la personne
  ///
  /// @see     Mail, Adresse, CodePostal, Ville, NumTelephone.
    GestionnaireConnexion(Coordonnees c){ajouterCoord(c); };

public :

    /// @brief Cette méthode permet d'ajouter un produit a la liste
    ///
    /// @see   lesProduits.
    virtual void ajouterCoord(Coordonnees c) {
        if (verifierExist(c.mail()))
            lesInscriptions.push_back(c);
    }

    /// @brief Cette méthode permet de verifier que la quantite et les prix sont valides
    ///
    /// @return vrai si la quantite et les prix sont coohérents
    ///
    /// @see   Quantite, Prix.
    bool verifierExist(std::string mail){
        for(Coordonnees i : lesInscriptions){
            if (i.mail() == mail)
                return false;
            return true;
        }
    }



};



#endif // GESTIONNAIRECONNEXION_H
