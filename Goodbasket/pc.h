#ifndef PC_H
#define PC_H


// pour les affichages (des destructeurs)
#include <iostream>
// pour la précision
#include <iomanip>
// pour les flux sur les chaînes de caractères (ostringstream)
#include <sstream>

//Declaration de la class sans la définir
class responspc;


class PC
{
public:
    PC();
    /// @brief Le destructeur ne fait rien, mais doit être défini
    ///        comme abstrait.
    virtual ~PC(){}

};

#endif // PC_H
