#include <iostream>

#include "Personne.h"

using namespace std;


/// @param  argc  nombre de paramètres du programme (non utilisé),
/// @param  argv  paramètres du programme (non utilisé).
///
/// @return  0 (OK).
///
/// @version 1a
int main()
{
    //le numéro de téléphone ne peut pas commencer par un 0 ATTENTION
    Coordonnees c("patrick.durant@gmail.fr","4 route du sud", 54500, "Vandoeuvre les nancy", 625143625, "codeXY");
    Personne pers("Durant", "Patrick", c,'P');

    pers.affiche(std::cout);

    //Demander la consultation des produits, la connexion ou l'inscription
    int choix;
    cout << "Que voulez vous faire ? 1: Consulter, 2:Connexion, 3: Inscription ";
    cin >> choix;

    if(choix == 1){
        cout << "Vous voilà dans la consultation des produits" << endl;
    }
    else if (choix == 2) {
        cout << "Vous pouvez vous connecter : " << endl;
    }
    else if (choix == 3) {
        cout << "Veuillez saisir les informations suivantes pour vous inscrir" << endl;
    }
    else {
        cout << "Vous avez fait un movais choix" << endl;
    }


    //Demander l'inscription ou la connexion

    return 0;
}
