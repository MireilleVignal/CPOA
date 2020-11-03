#include <iostream>

#include "producteur.h"

using namespace std;


/// @param  argc  nombre de paramètres du programme (non utilisé),
/// @param  argv  paramètres du programme (non utilisé).
///
/// @return  0 (OK).
///
/// @version 1a
int main(int argc, char *argv[])
{
    Coordonnees c("patrick.durant@gmail.fr","4 route du sud", 54500, "Vandoeuvre les nancy", 0125364757);
    Producteur prod("Durant", "Patrick", c);

    prod.affiche(std::cout);

    return 0;
}
