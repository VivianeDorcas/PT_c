#ifndef DEF_PARTY
#define DEF_PARTY
#include "invite.h"
//#include "organisateurs.cpp"

#include <string>

class Party {
public :
    std::string slogan;
    std::string mois;
    int jour;
    int heure;
    Invite nombreInvites[25];
    //Organisateur organise;


    Party();
    void save ();
    nbreInvit ();
    void afficher();
    void SaveGuest (Invite &guest);

};



#endif
