#ifndef GESTIONNAIRECONNEXION_H
#define GESTIONNAIRECONNEXION_H

#include "Personne.h"

#include <vector>




class GestionnaireConnexion
{
    /// @brief Les inscriptions du gestionnaire sont un tableau de coordonnées C++.
    std::vector<Personne> lesInscriptions;


public :

  /// @brief Le constructeur permet de remplir les champs
  ///        de la classe en fonction des paramètres passés.
  ///
  /// Ce constructeur est protégé pour que la classe Coordonnees
  /// reste abstraite
  ///
  /// @param c les Coordonnées de la personne
  ///
  /// @see
    //GestionnaireConnexion(Personne p){ajouterPers(p); };

    GestionnaireConnexion() {}


    ///@brief Le destructeur ne fait rien.
    //virtual ~GestionnaireConnexion();


    /// @brief   Cette méthode donne le nombre de personne enregistrée.
    ///
    /// @return  le nombre de personne enregistré.
    ///
    /// @see     lesInscriptions.
    int nbPers(){
        return lesInscriptions.size();
    }


    /// @brief   Cette méthode donne toutes les personnes enregistrées.
    ///
    /// @return  les personnes enregistrées.
    ///
    /// @see     lesInscriptions.
    std::vector<Personne> toutesLesPersonnes(){
        return lesInscriptions;
    }



    virtual void ajouterPers(Personne p){
        if (verifierExist(p.coordon().mail()))
            lesInscriptions.push_back(p);
    }


    /// @brief Cette méthode permet de verifier que la quantite et les prix sont valides
    ///
    /// @return vrai si la quantite et les prix sont coohérents
    ///
    /// @see   Quantite, Prix.
    bool verifierExist(std::string mail){
        for(Personne i : lesInscriptions){
            if (i.coordon().mail() == mail)
                return false;
        }return true;
    }

    /// @brief   Cette méthode donne l'identifiant d'un utilisateur s'il existe.
    ///
    /// @param  nom le nom de l'utilisateur choisi
    ///
    /// @return  l'indentifiant d'un utilissateur donné
    ///
    /// @see     lesUtilisateurs.
    int PersonneNom(std::string nom){
        for(int i = 0; i< nbPers(); i++){
           if(lesInscriptions[i].nom() == nom)
               return i;
        }
        return -1;
    }

    void mettreAJourPers(Personne p){
        if(verifierExist(p.coordon().mail())){
            lesInscriptions.at(PersonneNom(p.nom())) = p;}
    }



};



#endif // GESTIONNAIRECONNEXION_H
