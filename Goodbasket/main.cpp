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

    //Prod /Cons /ResponsPc
    /*char perso;
    cout << "Etes-vous un producteur, un consommateur ou un Responsable ? (p,c,r)\n ";
    cin >> perso;

    if(perso == 'p' || perso == 'P'){
        cout << "Bonjour et bienvenu Monsieur le producteur" << endl;
    }
    else if (perso == 'c' || perso == 'C') {
        cout << "Vous pouvez vous connecter : " << endl;
    }
    else if (perso == 'R' || perso == 'R') {
        cout << "Veuillez saisir les informations suivantes pour vous inscrir" << endl;
    }
    else {
        cout << "Vous avez fait un movais choix" << endl;
    }*/

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
