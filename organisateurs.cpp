#include <iostream>
#include <string>
#include "party.h"
#include "organisateurs.h"

using namespace std;

Organisateur::Organisateur(){
        nom="Vivi";
        numero=67;
        age=25;
    }

void Organisateur::senregistrer (){
        cout <<"Entrer votre nom : ";
        cin  >>nom;
        cout <<"Entrer votre numero : ";
        cin  >>numero;
        cout <<"Entrer votre age : ";
        cin  >>age;

    }
void Organisateur::saveParty (){
        Party fet;
        fet.save();
        fete.push_back(fet);
    }
void Organisateur::afficher (){
    cout <<"Le nom : "<<nom<<endl<<endl;
    cout <<"L'age : "<<age<<endl<<endl;
    cout <<"Le numero : "<<numero<<endl<<endl;
}

