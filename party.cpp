#include <iostream>
#include "party.h"
#include "invite.h"
#include <vector>
#include <math.h>
#include <array>
#include <bits/stdc++.h>
using namespace std;

int places =25;
std::vector <int> NombrePremier(int places){
        std:: vector <int> pVip;
        //std:: vector <int> pNonVip;
        for(int j=2;j<places;j++) {
        int compt=2, i;
        double racine=sqrt(j);
        for (i=2; i<=racine;i++){
            if (j%i==0){compt ++;}
        }
        if (compt==2){
            pVip.push_back(j);
        }
        }

        return pVip;
}
std:: vector <int> PlacesVip= NombrePremier(25);
Party:: Party (){
        slogan="Fete national";
        mois= "Janvier";
        jour=16;
        heure=15;
        nombreInvites[25];
        //organise;
    }
void Party:: save (){
        cout << "Entrer le slogan de votre fete :"<<endl;
        cin>>slogan;
        cout << "Le mois d'organisation : "<<endl;
        cin >> mois;
        cout << "Jour du mois : "<<endl;
        cin >>jour;
        cout << "Heure de la fete : "<<endl;
        cin >>heure;
}
int Party:: nbreInvit (){
    int compteur=0;
    for (int i; i<25; i++){
        if (nombreInvites[i].age!=0)
        {
            compteur++;
        }
    }
    return compteur;
}
void Party:: afficher() {
        cout <<"Slogan de la fete: "<<slogan<<endl;
        cout <<"Date : le "<<jour<<" "<<mois<<" 2021 a ";
        cout <<heure<<" heure(s)"<<endl;
        cout <<"Nombres d'invites :"<<nbreInvit()<<endl;
        //cout <<"Nombres d'invites :"<<sizeof(nombreInvites)/40<<endl;
}
void Party:: SaveGuest (Invite &guest){

    //cout <<"La taille : "<<PlacesVip.size()<<endl;
    if (guest.vip){
            int comptPlace=0;
            for (int i; i<PlacesVip.size(); i++) {
                if (nombreInvites[PlacesVip[i]].nom=="Anonyme"){
                    nombreInvites[PlacesVip[i]]=guest;
                    cout<<" PLACE VIP !! "<<endl;
                    nombreInvites[PlacesVip[i]].afficherInvite();
                    int a =nbreInvit();
                    cout<<"Nbre : "<<a;
                    cout<<"Place : "<< PlacesVip[i]<<endl;
                    comptPlace++;
                }
                break;
            }
            if (comptPlace==0){
                cout <<"PAS DE PLACE VIP DISPONIBLE"<<endl;
            }
    }
    else {
        int compteurNonVip=0;
        int compteurFinal=0;
        for (int i; i<25; i++){
            //std::vector <int>::iterator it=std::find(PlacesVip.begin(), PlacesVip.end(),i);
            if ( std::find(PlacesVip.begin(), PlacesVip.end(),i)!=PlacesVip.end()){

            }
            else {
                if (nombreInvites[i].nom=="Anonyme") {
                    nombreInvites[i]=guest;
                    cout<<"PLACE NORMAL !!";
                    compteurFinal++;
                    compteurNonVip++;
                    break;
                }
            }
        }
        if (compteurNonVip==0){
            for (int i; i<25; i++) {
                if (nombreInvites[i].nom=="Anonyme") {
                    nombreInvites[i]=guest;
                    compteurFinal++;
                }
            }
        }
        if (compteurFinal==0){
            cout<<"DESOLE IL N'YA PLUS DE PLACE"<<endl;
        }
    }
}


