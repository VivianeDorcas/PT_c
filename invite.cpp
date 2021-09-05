#include <iostream>
#include <string>
#include "invite.h"

using namespace std;


Invite::Invite (){
    nom="Anonyme";
    prenom="";
    age=0;
    vip=0;
   }
   void Invite::enregistrerInvite(){
        cout <<"Entrer votre nom : ";
        cin  >>nom;
        cout <<"Entrer votre prenom : ";
        cin  >>prenom;
        cout <<"Entrer age : ";
        cin  >>age;
        cout <<"Etes vous VIP ? Si oui tapez 1 sinon 0 ";
        cin  >>vip;
   }
    void Invite:: afficherInvite (){

    cout <<"Le nom : "<<nom<<endl<<endl;
    cout <<"L'age : "<<age<<endl<<endl;
    if (vip) {
        cout <<"Votre standing : VIP "<<endl<<endl;
    }
    else {
       cout <<"Votre standing : INVITE NORMAL "<<endl<<endl;
    }
    }

   /* bool Invite :: operator == (const Invite &guest){
        return prenom==guest.prenom && nom=guest.prenom;
    }*/

