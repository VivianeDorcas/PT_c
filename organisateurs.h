#ifndef DEF_ORGANISATEURS
#define DEF_ORGANISATEURS
#include "party.h"
#include <vector>

#include <string>

class Organisateur {

public :
    int numero;
    std::string nom ;
    int age ;
    std::vector <Party> fete;

    Organisateur();
    void senregistrer ();
    void saveParty ();
    void afficher ();


};

#endif // DEF_ORGANISATEURS
