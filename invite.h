#ifndef DEF_INVITE
#define DEF_INVITE

#include <string>

class Invite {
public :
    std::string nom;
    std::string prenom;
    int age ;
    int vip;

    Invite();
    void enregistrerInvite();
    void afficherInvite ();
    //bool operator == (const Invite &guest);
};


#endif
