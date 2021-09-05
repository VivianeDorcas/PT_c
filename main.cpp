#include <iostream>
#include <vector>
#include "organisateurs.h"
#include "invite.h"
#include "party.h"
#include <string>
#include <stdlib.h>

using namespace std;

std::vector <Organisateur> orgas;
std::vector<Invite> invites ;
std :: vector <Party> fetes;

void menu();
void menuOrganisateur ();
void menuInvite();
void menuAdmin();

struct Administrator {
    string password;
    string username;
};

void effacerEcran (){
    std::system("cls");
}

void rapport (){
    cout << "_______________VOICI LE RAPPORT DU SITE________________"<<endl<<endl;
    cout <<"Nombre de fetes : "<<fetes.size()<<endl;
    cout<< "Nombres d'organisateurs : "<<orgas.size()<<endl;
    cout<<"Total des invites : "<<invites.size()<<endl;
}

bool allo (){
    Administrator admini;
    admini.password="admin";
    admini.username="admin";
    cout <<"CONNECTEZ - VOUS : "<< endl;
    cout<<"MOT DE PASSE : ";
    std:: string password;
    std:: string username;
    cin>> password;
    cout<<"USERNAME : ";
    cin >>username;
    return (admini.password==password && admini.username==username);
}


void esp (){
    cout<<"                 ";
}
void choix(){
    cout<<"Choisissez un chiffre : ";
}

void menuChoix (){
    cout<<endl<<"Tapez la touche : "<<endl<<endl;
    cout<<" -  0 ( zero ) pour aller au MENU PRINCIPAL "<<endl;
    cout<<" -  1( un ) pour retourner au MENU ORGANISATEUR "<<endl;
    cout<<" -  Un autre chiffre pour quitter "<<endl;
    cout <<endl<<" VOTRE CHOIX : ";
    int choix;
    cin >>choix;
    if (choix==0){
        effacerEcran();
        menu();
    }
    else if (choix ==1){
        effacerEcran();
        menuOrganisateur();
    }
}

void menuChoix2 (){
    cout<<endl<<"Tapez la touche : "<<endl<<endl;
    cout<<" -  0 ( zero ) pour aller MENU PRINCIPAL "<<endl;
    cout<<" -  1( un ) pour retourner au MENU ORGANISATEUR "<<endl;
    cout<<" -  Un autre chiffre pour quitter le programme"<<endl;
    cout <<endl<<" VOTRE CHOIX : ";
    int choix;
    cin >>choix;
    if (choix==0){
        effacerEcran();
        menu();
    }
    else if (choix ==1){
        effacerEcran();
        menuInvite();
    }
}


void OrgaSauvegarde(){
    Organisateur seraphin;
    cout<<endl<<"_____ENTREZ VOS INFORMATIONS_____ "<<endl<<endl;
    seraphin.senregistrer();
    orgas.push_back(seraphin);
    cout<<"Bravo !!!! Vous avez ete enregistreE avec succEs"<<endl<<endl;
    cout <<"VOUS AVEZ LE NUMERO :  "<<orgas.size()<<" ( VOUS NE DEVEZ PAS L'OUBLIER !!! )"<<endl;
}

void InviteSauvegarde (){
    Invite bari;
    cout<<endl<<"_____ENTREZ VOS INFORMATIONS_____ "<<endl<<endl;
    bari.enregistrerInvite();
    invites.push_back(bari);
    cout<<"Bravo !!!! Vous avez ete enregistreE avec succEs"<<endl<<endl;
    cout <<"VOUS AVEZ LE NUMERO :  "<<invites.size()<<" ( VOUS NE DEVEZ PAS L'OUBLIER !!! )"<<endl;
}

void FeteSauvegarde (){
    if (orgas.size()==0){
        cout <<"Veuillez d'abord vous enregistrer "<<endl;
        OrgaSauvegarde();
        cout<<"_______ENREGISTREMENT DE LA FETE______"<<endl<<endl;
        cout <<endl<<"Vous pouvez maintenant enregistrer votre fete :"<<endl<<endl;
        orgas[0].saveParty();
    }
    else {
        int numero;
        cout<<"_______ENREGISTREMENT DE LA FETE______"<<endl<<endl;
        cout <<"Pour enregistrer la fete entrer votre identifiant ( numero ) :";
        cin >>numero;
        cout<<endl<<endl;
        orgas[numero-1].saveParty();
    }
}

void SenregistrerFete(){

    int compt=1;
    for (int i=0; i<orgas.size(); ++i){
            for (int j=0 ; j<orgas[i].fete.size(); ++j){
                fetes.push_back(orgas[i].fete[j]);
            }
    }
    if (fetes.size()==0){
        cout<< " Aucune fete n'est disponible pour l'instant "<<endl;
    }
    else {
        cout <<endl<<endl<<"Voici les fetes disponibles "<<endl<<endl;
        for (int i=0; i<fetes.size(); ++i){
                cout<<"     NUMERO : "<<compt<<endl;
                fetes[i].afficher();
                compt++;
    }
    if (invites.size()==0){
        cout <<" Enregistrer-vous d'abord svp !!!"<<endl;
        InviteSauvegarde();
        cout<<"SELECTIONNEZ UNE FETE"<<endl;
        cout <<" Choisissez le numero de la fete que vous voulez : ";
        int choixFete;
        cin>>choixFete;
        fetes[choixFete-1].SaveGuest(invites[0]);
        cout<<"Nbre des fetes : "<<fetes[choixFete-1].nbreInvit();
    }
    else {
        cout <<"Pour choisir entrer votre identifiant( numero )";
        int identifiant;
        cin>>identifiant;
        Invite guest=invites[identifiant];
        cout <<" Choisissez le numero de la fete que vous voulez : ";
        int choixFete;
        cin>>choixFete;
        fetes[choixFete-1].SaveGuest(guest);
    }
    }
}

void FeteOrgaRegarder(){
    if (orgas.size()==0){
        cout <<"Veuillez d'abord vous enregistrer "<<endl;
        OrgaSauvegarde();
        menuChoix();
    }
    cout<<"________MES FETES ENREGISTREES__________"<<endl<<endl;
    cout<<"Entrer votre identifiant( numero ) pour voir vos fetes ";
    int choixNum;
    cin>> choixNum;
    if (orgas[choixNum-1].fete.size()==0){
        cout <<"Vous n'avez aucune fete enregistrer "<<endl;
    }
    else {
            cout<<endl<<"VOICI VOS FETES : "<<endl<<endl;
    int compteur=0;
    for (int i=0; i<orgas[choixNum-1].fete.size(); ++i){
        cout<<" Fete numero :"<<compteur+1<<endl;
        cout<<endl<<"___________________________________"<<endl;
        orgas[choixNum-1].fete[i].afficher();
        compteur++;
        cout<<"___________________________________"<<endl;
    }
    }
}

int VoirFeteInvite (){
    if (invites.size()==0){
        cout <<"Vous n'etes pas enregistrer "<<endl;
        return 0;
    }
    cout <<"Entrer votre identifiant ( numero ) : ";
    int ident;
    cin>>ident;
    Invite guest =invites[ident];
    cout <<"Nombre des fetes : "<<fetes.size()<<endl;
    cout<<fetes[0].nbreInvit();

    cout <<endl<<" VOTRE NOM "<<guest.nom<<endl<<endl;
    if (fetes.size()==0){
        cout <<"IL N'YA AUCUNE FETE DANS NOTRE BASE"<<endl;
    }
    else {
        cout <<endl<<" VOTRE NOM "<<guest.nom<<endl<<endl;
        for (int i=0; i<fetes.size(); i++){
            for (int j=0; j<25; j++) {
            if (fetes[i].nombreInvites[i].nom==guest.nom ){
                //&& fetes[i].nombreInvites[i].prenom==guest.prenom
                fetes[i].afficher();
                }
            }
        }
    }
    return 0;
}

void menuOrganisateur(){
    esp();cout <<"________BIENVENUE DANS L'ESPACE ORGANISATEUR________"<< endl<<endl;
    esp();cout<<"       Que voulez-vous faire ? "<<endl<<endl;
    esp();cout<<"1.       S'enregistrer "<<endl;esp();cout<<"2.       Enregistrer une party"<<endl;
    esp();cout<<"3.       Voir mes party enregistres"<<endl;
    cout<<endl<<"Vous pouvez tapez 0 (zero) si vous desirer retourner au MENU PRINCIPAL"<<endl<<endl;
    choix();
    int choixOrga;
    cin>>choixOrga;
    if (choixOrga==1){
        effacerEcran();
        OrgaSauvegarde();
        menuChoix();
    }
    else if (choixOrga==2){
        effacerEcran();
        FeteSauvegarde();
        menuChoix();
    }
    else if (choixOrga==3){
        effacerEcran();
        FeteOrgaRegarder();
        menuChoix();
    }
    else if (choixOrga==0){
        effacerEcran();
        menu();
    }
}

void menuInvite (){
    esp();cout<<"__________BIENVENUE DANS L'ESPACE INVITE_____________"<< endl<<endl;
    esp();cout<<"       Que vlz vous faire ?"<<endl;
    esp();cout<<"1.       S'enregistrer "<<endl; esp();cout<<"2.       s'enregistrer a une party"<<endl;
    esp();cout<<"3.       Voir mes party "<<endl;
    cout<<endl<<"Vous pouvez tapez 0 (zero) si vous desirer retourner au MENU PRINCIPAL"<<endl<<endl;
    choix();
    int choixInvite;
    cin >>choixInvite;

    if (choixInvite==1){
        effacerEcran();
        InviteSauvegarde();
        menuChoix2();
    }
    else if (choixInvite==2){
        effacerEcran();
        SenregistrerFete();
        menuChoix2();
    }
    else if (choixInvite==0){
        effacerEcran();
        menu();
    }
    else if (choixInvite==3){
        VoirFeteInvite();
        menuChoix2();
    }
}

void menu (){
    cout <<endl;
    esp();cout<<"_______BIENVENUE AU SITE OFFICIEL DES FETES_______"<< endl<<endl;
    esp();cout <<"              Qui etes vous  ? "<< endl<<endl;esp();cout<< "1.       ORGANISATEUR DE FETE "<<endl;
    esp();cout<<"2.       INVITE "<<endl;
    esp();cout <<"3.       ADMINISTRATEUR "<<endl<<endl;
    int reponse=5;

    while (reponse ){
        esp();cout <<"  Choisissez en tapant 1 ,2 ou 3 :  ";
        cin>> reponse;
        if (reponse>=1 && reponse<=3){
            break;
        }
    }
    if (reponse==1){
        effacerEcran();
        menuOrganisateur();
    }
    if (reponse==2){
        effacerEcran();
        menuInvite();
    }
    if (reponse==3){
        if (allo()){
            rapport();
            int choixAdm;
            cout<<endl<< "Tapez la touche 0 (zero ) pour le MENU PRINCIPAL ou autre chiffre pour QUITTER"<<endl;
            cin>> choixAdm;
            if (choixAdm==0){
                menu();
            }
        }

    }
}

int main()
{
    //DECLARATION
    menu();
    cout<<endl<<endl<<endl<<"MERCI ET AUREVOIR !!!"<<endl;
    return 0;
}
