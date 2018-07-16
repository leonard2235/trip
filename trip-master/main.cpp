#include <iostream>
using namespace std;
#include<cstdlib>
#include <limits>
#include <string>
#include <sstream>
#include"lieu/lieu.h"
#include"carte2d/carte2d.h"

//Fonctions de saisie_____________________________________________________________________________
void vider_buffer()
{
cin.clear();
cin.seekg(0, ios::end);

if(!cin.fail())
{
cin.ignore(numeric_limits<streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
}

else
{
cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
}
}

bool saisirint(int &variable, const string &message)
{
string temp;

while(true)
{
cout << message;
cin >> temp;

if(cin.bad() || cin.eof())
{
cerr << "Une erreur interne est survenue" << endl;

if(cin.eof())
{
return false;
}

vider_buffer();

continue;
}

else if(cin.fail())
{
cerr << "Erreur, saisie incorrecte." << endl;

vider_buffer();

continue;
}

vider_buffer();

istringstream stream(temp);
stream >> variable;

if(stream.fail() || !stream.eof())
{
cerr << "Erreur, saisie incorrecte." << endl;
}

else
{
return true;
}
}

return false;
}

bool saisirfloat(float &variable, const string &message)
{
string temp;

while(true)
{
cout << message;
cin >> temp;

if(cin.bad() || cin.eof())
{
cerr << "Une erreur interne est survenue" << endl;

if(cin.eof())
{
return false;
}

vider_buffer();

continue;
}

else if(cin.fail())
{
cerr << "Erreur, saisie incorrecte." << endl;

vider_buffer();

continue;
}

vider_buffer();

istringstream stream(temp);
stream >> variable;

if(stream.fail() || !stream.eof())
{
cerr << "Erreur, saisie incorrecte." << endl;
}

else
{
return true;
}
}

return false;
}
bool saisie_Cord( int & n)
{
    cout<<"         Entrez une valeur en 0 et 9"<<endl;
    while (!( cin >> n ) || n < 0 || n > 9 )
    {
        if ( cin.eof() )
        {
            return false;
        }
        else if ( cin.fail() )
        {
            cout <<"            Saisie incorrecte"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        }
        else cout <<"            Le chiffre n'est pas entre 0 et 9: "<<endl;
    }
    return true; // succès
}

bool saisie0a4( int & n)
{
    while (!( cin >> n ) || n < 0 || n > 4 )
    {
        if ( cin.eof() )
        {
            return false;
        }
        else if ( cin.fail() )
        {
            cout <<"            Saisie incorrecte"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        }
        else cout <<"            Le chiffre n'est pas entre 0 et 4: "<<endl;    }
    return true; // succès
}

bool saisie0a3( int & n)
{
    while (!( cin >> n ) || n < 0 || n > 3 )
    {
        if ( cin.eof() )
        {
            return false;
        }
        else if ( cin.fail() )
        {
            cout <<"            Saisie incorrecte"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        }
        else cout <<"            Le chiffre n'est pas entre 0 et 3: "<<endl;
    }
    return true; // succès
}

bool saisie0a2( int & n)
{
    while (!( cin >> n ) || n < 0 || n > 2 )
    {
        if ( cin.eof() )
        {
            return false;
        }
        else if ( cin.fail() )
        {
            cout <<"            Saisie incorrecte"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n' );
        }
        else cout <<"            Le chiffre n'est pas entre 0 et 2: "<<endl;
    }
    return true; // succès
}

// MENU PRINCIPAL__________________________________________________________________________________

void Menuprincipal(){
    cout <<endl<<endl;
    cout <<"            ** 1 Affichage des informations concernant un lieu "<<endl;
    cout <<"            ** 2 Ajout / Suppression d'un lieu "<<endl;
    cout <<"            ** 3 Ajout / Suppression d'informations concernant un lieu "<<endl;
    cout <<"            ** 4 Ajout / Suppression d'un label "<<endl;
    cout <<"            ** 0 Sortir "<<endl;
    cout<<endl;
    cout <<"            Faites votre choix "<<endl;
}

// SOUS MENU DU MENU PRINCIPAL_____________________________________________________________________
void Sousmenu1(){
     cout<<endl<<endl;
     cout <<"           ** 0 Retour menu principal <<<<"<<endl;
}

void Sousmenu2(){
     cout <<endl<<endl;
     cout <<"           ** 1 Ajout d'un lieu naturel "<<endl;
     cout <<"           ** 2 Ajout d'un lieu urbain "<<endl;
     cout <<"           ** 3 Supression d'un lieu"<<endl;
     cout <<"           ** 0 Retour menu principal "<<endl;
     cout<<endl;
     cout <<"           Faites votre choix"<<endl;
}

void Sousmenu3(){
     cout <<endl<<endl;
     cout<<"           ** 1 Ajout d'information(s) concernant un lieu naturel "<<endl;
     cout<<"           ** 2 Suppression d'information(s) concernant un lieu naturel"<<endl;
     cout<<"           ** 3 Ajour d'information(s) concernant un lieu urbain"<<endl;
     cout<<"           ** 4 Suppression d'information(s) concernant un lieu urbain"<<endl;
     cout<<"           ** 0 Retour menu principal "<<endl;
     cout<<endl;
     cout<<"           Faites votre choix"<<endl;
}

void Sousmenu4(){
     cout<<endl<<endl;
     cout<<"           ** 1 Ajout d'un label "<<endl;
     cout<<"           ** 2 Suppression d'un label "<<endl;
     cout<<"           ** 0 Retour menu principal "<<endl;
     cout<<endl;
     cout<<"           Faites votre choix "<<endl;
}
int main(){
    Carte<Lieu> cartelieu;

    string label1="Parc";
    string label2="UNESCO";

    Monument monument1 ("Pyramide de l'UPPA","Pyramide",300);
    Monument monument2 ("L'obélix","Obélisque",350);
    Etape etap1 ("Restaurant du bearn","Restaurant",12.0);
    Etape etap2 ("Le routier","Restaurant",10.0);
    Randonnee rando1 ("RandoF","Paris","Pau",1000,10);
    Randonnee rando2 ("Rando du bearn","Paris","Pau",1000,10);
    Escalade escal1  ("Escalade du bearn",10,"3a+","3a");
    Escalade escal2  ("De l'esc",9,"3a+","3c");
    Activite activi1 ("Lac de biscarosse","Baignade",15);

    Sport s1;
    Sport s2;


    Detente dete1;
    dete1.Ajoutact(activi1);

    Lieu lieu1;
    lieu1.ajouterEtap(etap1);
    lieu1.ajouterMon(monument1);

    Lieu lieu2;
    lieu2.ajouterEtap(etap2);
    lieu2.ajouterMon(monument2);

    Lieu lieu3;
    s1.AjoutEscal(escal1);
    s1.AjoutRando(rando1);

    Lieu lieu4;
    s2.AjoutEscal(escal2);
    s2.AjoutRando(rando2);

    Lieu lieu5;
    lieu5.ajouterEtap(etap2);
    lieu5.ajouterMon(monument1);
    lieu5.ajouterLabel(label1);


    lieu1.setAbscisse(1);
    lieu1.setOrdonnee(1);
    lieu1.setNomville("Pau");
    lieu1.ajouterLabel(label1);

    lieu2.setAbscisse(5);
    lieu2.setOrdonnee(1);
    lieu2.setNomville("Paris");

    lieu3.setAbscisse(9);
    lieu3.setOrdonnee(9);
    lieu3.ajouterLabel(label2);
    lieu3.setNomnat("Paris");
    lieu3.setSp(s1);
    lieu3.setDt(dete1);

    lieu4.setAbscisse(5);
    lieu4.setOrdonnee(2);
    lieu4.setNomnat("Par la");
    lieu4.setSp(s2);

    lieu5.setAbscisse(3);
    lieu5.setOrdonnee(8);
    lieu5.setNomville("Toulouse");

    cartelieu.inserer(lieu1,lieu1.getAbscisse(),lieu1.getOrdonnee());
    cartelieu.inserer(lieu2,lieu2.getAbscisse(),lieu2.getOrdonnee());
    cartelieu.inserer(lieu3,lieu3.getAbscisse(),lieu3.getOrdonnee());
    cartelieu.inserer(lieu4,lieu4.getAbscisse(),lieu4.getOrdonnee());
    cartelieu.inserer(lieu5,lieu5.getAbscisse(),lieu5.getOrdonnee());

                        int x;
                        int y;
                        Lieu ln;
                        Lieu lu;
                        Lieu l1;
                        Lieu l2;
                        Sport sp;
                        Randonnee rd;
                        Monument mon;
                        Escalade esc;
                        Etape etp;
                        Activite act;
                        Detente dt;

                        string msgNbvoie="         Nombre de voies:";
                        string msgTarif="         Tarif (en €):";
                        string msgEpoq="         Epoque:";
                        string msgDur="         Durée (en mn):";
                        string msgDeniv="         Denivelé positif:";


                        string sBuffer;
                        string answ;
                        float fBuffer;
                        int iBuffer;
                        int iBool;
    //fin declarations


    int menu;
    cartelieu.afficherCarte();
    do
        {
            system("clear");
            cout <<"            *******************************************************************"<<endl;
            cout <<"            ****************************** TRIP *******************************"<<endl;
            cout <<"            *******************************************************************"<<endl;
            cout<<endl;
            cartelieu.afficherCarte();
            Menuprincipal();
            saisie0a4(menu);
            cout<<endl;

            switch(menu)
            {
                case 0 :
                system("clear");
                break;

                case 1 :
                //Saisie des coordonnées + affichage des infos d'un lieu a ces coords.
                int sousmenu1;
                do
                {
                    system("clear");
                    cout<<"            *******************************************************************"<<endl;
                    cout<<"            ****************************** TRIP *******************************"<<endl;
                    cout<<"            *******************************************************************"<<endl;
                    cout<<endl;
                    cartelieu.afficherCarte();
                    cout<<endl<<endl;
                    cout<<"            Entrez les coordonnées du lieu"<<endl;
                    cout<<"            Ordonnee"<<endl;
                    saisie_Cord(iBuffer);
                    x=iBuffer;
                    cout<<"           Abscisse"<<endl;
                    saisie_Cord(iBuffer);
                    y=iBuffer;
                    //affichage des infos du lieu//////////////////////////////////////////////////
                    system("clear");
                    cartelieu._tabLieu[x][y].afficherInfo();

                    Sousmenu1();
                    cin>>sousmenu1;
                    cout<<endl;
                    switch(sousmenu1)
                    {
                    case 0:
                        //RETOUR MENU PRINCIPAL////////////////////////////////////////////////////
                        break;
                    default:
                        cout<<"Saisie invalide, try again !!!"<<endl;
                        break;
                    }
                }while(sousmenu1 != 0);
                break;

                case 2 :
                int sousmenu2;
                do
                {
                    system("clear");
                    cout <<"            *******************************************************************"<<endl;
                    cout <<"            ****************************** TRIP *******************************"<<endl;
                    cout <<"            *******************************************************************"<<endl;
                    cout<<endl;
                    cartelieu.afficherCarte();
                    Sousmenu2();
                    saisie0a2(sousmenu2);
                    cout<<endl;
                    switch(sousmenu2)
                    {
                    case 0:
                        //RETOUR MENU PRINCIPAL
                        break;
                    case 1:
                        //AJOUT D'UN LIEU NATUREL//////////////////////////////////////////////////
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        ln.setAbscisse(x);
                        ln.setOrdonnee(y);
                        ln.setNomnat(sBuffer);
                        system("clear");
                        /////////////////////////
                        cout<<"         Voulez-vous ajouter une activité sportive (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                        cout<<"         Randonnee ou Escalade (R/r)(E/e) ?"<<endl;
                                        cin>>answ;
                                        if ((answ=="R")||(answ=="r")){
                                                cout<<"         Nom de la randonnée:"<<endl;
                                                cin>>sBuffer;
                                                rd.setNomRandonnee(sBuffer);
                                                cout<<"         Point de depart:"<<endl;
                                                cin>>sBuffer;
                                                rd.setDepart(sBuffer);
                                                cout<<"         Point d'arrivée:"<<endl;
                                                cin>>sBuffer;
                                                rd.setArrivee(sBuffer);
                                                saisirfloat(fBuffer,msgDur);
                                                rd.setDuree(fBuffer);
                                                saisirfloat(fBuffer,msgDeniv);
                                                rd.setDenivele(fBuffer);
                                                sp.AjoutRando(rd);
                                        }else if((answ=="E") || (answ=="e")){
                                                cout<<"         Nom de l'escalade:"<<endl;
                                                cin>>sBuffer;
                                                esc.setNomescalade(sBuffer);
                                                saisirint(iBuffer,msgNbvoie);
                                                esc.setNbvoies(iBuffer);
                                                cout<<"         Niveau minimum:"<<endl;
                                                cin>>sBuffer;
                                                esc.setLvlmin(sBuffer);
                                                cout<<"         Niveau maximun:"<<endl;
                                                cin>>sBuffer;
                                                esc.setLvlmax(sBuffer);
                                                sp.AjoutEscal(esc);
                                        }
                                        cout<<"Voulez-vous ajouter une autre activité sportive (o/n) ?"<<endl;
                                        cin>>answ;
                                        if((answ =="n") || (answ =="N"))
                                            iBool=0;
                                        else
                                            iBool=1;
                                }while(iBool);
                        }
                        system("clear");
                        /////////////////////////
                        cout<<"Voulez-vous ajouter une activité de détente (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                    cout<<"         Nom de l'activité:"<<endl;
                                    cin>>sBuffer;
                                    act.setNomactivite(sBuffer);
                                    cout<<"         Horaires:"<<endl;
                                    cin>>sBuffer;
                                    act.setHoraires(sBuffer);
                                    saisirint(iBuffer,msgTarif);
                                    act.setTarif(fBuffer);
                                    dt.Ajoutact(act);
                                    cout<<"         Voulez-vous ajouter une autre activité de détente (o/n) ?"<<endl;
                                    cin>>answ;
                                    if((answ =="n") || (answ =="N"))
                                        iBool=0;
                                    else
                                        iBool=1;
                             }while(iBool);
                        }
                        ln.setDt(dt);
                        ln.setSp(sp);
                        cartelieu.inserer(ln,ln.getAbscisse(),ln.getOrdonnee());
                        break;

                    case 2:
                        //AJOUT D'UN LIEU URBAIN///////////////////////////////////////////////////
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        cout<<"         Nom du lieu (ville):"<<endl;
                        cin>>sBuffer;
                        lu.setAbscisse(x);
                        lu.setOrdonnee(y);
                        lu.setNomville(sBuffer);
                        system("clear");
                        ////////////////////////////
                        cout<<"         Voulez-vous ajouter un monument (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                cout<<"         Nom du monument:"<<endl;
                                cin>>sBuffer;
                                mon.setNommon(sBuffer);
                                cout<<"         Type du monument:"<<endl;
                                cin>>sBuffer;
                                mon.setTypmon(sBuffer);
                                saisirint(iBuffer,msgEpoq);
                                mon.setEpoq(iBuffer);
                                lu.ajouterMon(mon);
                                cout<<"         Voulez-vous ajouter un autre monument (o/n) ?"<<endl;
                                cin>>answ;
                                if((answ =="n") || (answ =="N"))
                                    iBool=0;
                                else
                                    iBool=1;

                            }while(iBool);
                        }
                        system("clear");
                        /////////////////////////
                        cout<<"         Voulez-vous ajouter une étape(Hôtel,Restaurant,... (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                                do{
                                    cout<<"         Nom de l'étape:"<<endl;
                                    cin>>sBuffer;
                                    etp.setNometap(sBuffer);
                                    cout<<"         Type de l'étape:"<<endl;
                                    cin>>sBuffer;
                                    etp.setTypetap(sBuffer);
                                    saisirint(iBuffer,msgTarif);
                                    etp.setTarif(fBuffer);
                                    lu.ajouterEtap(etp);
                                    cout<<"         Voulez-vous ajouter une autre étape (o/n) ?"<<endl;
                                    cin>>answ;
                                    if((answ =="n") || (answ =="N"))
                                        iBool=0;
                                    else
                                        iBool=1;
                                }while(iBool);
                        }
                        cartelieu.inserer(lu,lu.getAbscisse(),lu.getOrdonnee());
                        break;
                    case 3:
                        //SUPRESSION D'UN LIEU
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        cartelieu.retirer(x,y);
                        break;
                    default:
                        cout<<" Choix invalide, try again !"<<endl;
                        break;
                    }
                }while(sousmenu2 != 0);
                break;

                case 3 :
                int sousmenu3;
                do
                {
                    system("clear");
                    cout <<"            *******************************************************************"<<endl;
                    cout <<"            ****************************** TRIP *******************************"<<endl;
                    cout <<"            *******************************************************************"<<endl;
                    cout<<endl;
                    cartelieu.afficherCarte();
                    Sousmenu3();
                    saisie0a4(sousmenu3);
                    cout<<endl;
                    switch(sousmenu3)
                    {
                    case 0:
                        //RETOUR MENU PRINCIPAL
                        break;
                    case 1:
                        //AJOUT D'INFO SUR UN LIEU NATUREL
                        cout <<endl<<endl;
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        l1=cartelieu._tabLieu[x][y];
                        system("clear");
                        /////////////////////////
                        cout<<"             Voulez-vous ajouter une activité sportive (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                        cout<<"         Randonnee ou Escalade (R/r)(E/e) ?"<<endl;
                                        cin>>answ;
                                        if ((answ=="R")||(answ=="r")){
                                                cout<<"         Nom de la randonnée:"<<endl;
                                                cin>>sBuffer;
                                                rd.setNomRandonnee(sBuffer);
                                                cout<<"         Point de depart:"<<endl;
                                                cin>>sBuffer;
                                                rd.setDepart(sBuffer);
                                                cout<<"         Point d'arrivée:"<<endl;
                                                cin>>sBuffer;
                                                rd.setArrivee(sBuffer);
                                                saisirfloat(fBuffer,msgDur);
                                                rd.setDuree(fBuffer);
                                                saisirfloat(fBuffer,msgDeniv);
                                                rd.setDenivele(fBuffer);
                                                sp.AjoutRando(rd);
                                        }else if((answ=="E") || (answ=="e")){
                                            cout<<"         Nom de l'escalade:"<<endl;
                                            cin>>sBuffer;
                                            esc.setNomescalade(sBuffer);
                                            saisirint(iBuffer,msgNbvoie);
                                            esc.setNbvoies(iBuffer);
                                            cout<<"         Niveau minimum"<<endl;
                                            cin>>sBuffer;
                                            esc.setLvlmin(sBuffer);
                                            cout<<"         Niveau maximum:"<<endl;
                                            cin>>sBuffer;
                                            esc.setLvlmax(sBuffer);
                                            sp.AjoutEscal(esc);
                                        }
                                        cout<<"         Voulez-vous ajouter une autre activité sportive (o/n) ?"<<endl;
                                        cin>>answ;
                                        if((answ =="n") || (answ =="N"))
                                            iBool=0;
                                        else
                                            iBool=1;
                                }while(iBool);
                        }
                        system("clear");
                        /////////////////////////
                        cout<<"         Voulez-vous ajouter une activité de détente ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                    cout<<"         Nom de l'activité:"<<endl;
                                    cin>>sBuffer;
                                    act.setNomactivite(sBuffer);
                                    cout<<"         Horaires:"<<endl;
                                    cin>>sBuffer;
                                    act.setHoraires(sBuffer);
                                    saisirint(iBuffer,msgTarif);
                                    act.setTarif(fBuffer);
                                    dt.Ajoutact(act);
                                    cout<<"         Voulez-vous ajouter une autre activité de détente (o/n) ?"<<endl;
                                    cin>>answ;
                                    if((answ =="n") || (answ =="N"))
                                        iBool=0;
                                    else
                                        iBool=1;
                             }while(iBool);
                        }
                        l1.setDt(dt);
                        l1.setSp(sp);
                        cartelieu.retirer(l1.getAbscisse(),l1.getOrdonnee());
                        cartelieu.inserer(l1,l1.getAbscisse(),l1.getOrdonnee());
                        break;
                    case 2:
                        //SUPP D'INFO SUR UN LIEU LIEU NATUREL
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        l1=cartelieu._tabLieu[x][y];
                        system("clear");
                        /////////////////////////
                        cout<<"         Voulez-vous supprimer une activité sportive (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                      cout<<"           Randonnee ou Escalade (R/r)(E/e) ?"<<endl;
                                      cin>>answ;
                                      if ((answ=="R")||(answ=="r")){
                                          cout<<"       Entrez le numero de la randonnée à supprimer"<<endl;
                                          cin>>iBuffer;
                                          l1.getSp().retirerRando(iBuffer);
                                      }else if((answ=="E")||(answ=="e")){
                                           cout<<"      Entrez le numero de l'escalade à supprimer"<<endl;
                                           cin>>iBuffer;
                                           l1.getSp().retirerEscal(iBuffer);
                                            }
                                      cout<<"           Voulez-vous supprimer une autre activité sportive (o/n) ?"<<endl;
                                      cin>>answ;
                                      if((answ =="n") || (answ =="N"))
                                            iBool=0;
                                      else
                                            iBool=1;
                            }while(iBool);
                        }
                        system("clear");
                        /////////////////////////
                        cout<<"         Voulez-vous supprimer une activité détente (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                    cout<<"         Entrez le numero de l'activité de détente"<<endl;
                                    cin>>iBuffer;
                                    l1.getDt().retirerAct(iBuffer);
                                    cout<<"         Voulez-vous supprimer une autre activité de détente (o/n) ?"<<endl;
                                    cin>>answ;
                                    if((answ=="n") || (answ=="N"))
                                        iBool=0;
                                    else
                                        iBool=1;
                                }while(iBool);
                        }
                        cartelieu.retirer(l1.getAbscisse(),l1.getOrdonnee());
                        cartelieu.inserer(l1,l1.getAbscisse(),l1.getOrdonnee());
                        break;
                    case 3:
                        //AJOUT D'INFO SUR UN LIEU URBAIN
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        l2=cartelieu._tabLieu[x][y];
                        system("clear");
                        /////////////////////////
                        cout<<"         Voulez-vous ajouter un monument (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                cout<<"         Nom du monument:"<<endl;
                                cin>>sBuffer;
                                mon.setNommon(sBuffer);
                                cout<<"         Type du monument:"<<endl;
                                cin>>sBuffer;
                                mon.setTypmon(sBuffer);
                                saisirint(iBuffer,msgEpoq);
                                mon.setEpoq(iBuffer);
                                l2.ajouterMon(mon);
                                cout<<"         Voulez-vous ajouter un autre monument (o/n) ?"<<endl;
                                cin>>answ;
                                if((answ =="n") || (answ =="N"))
                                    iBool=0;
                                else
                                    iBool=1;

                            }while(iBool);
                        }
                        system("clear");
                        /////////////////////////
                        cout<<"         Voulez-vous ajouter une étape(Hôtel,Restaurant,... (o/n)"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                cout<<"         Nom de l'étape:"<<endl;
                                cin>>sBuffer;
                                etp.setNometap(sBuffer);
                                cout<<"         Type de l'étape:"<<endl;
                                cin>>sBuffer;
                                etp.setTypetap(sBuffer);
                                saisirfloat(fBuffer,msgTarif);
                                etp.setTarif(fBuffer);
                                l2.ajouterEtap(etp);
                                cout<<"         Voulez-vous ajouter une autre étape (o/n) ?"<<endl;
                                cin>>answ;
                                if((answ =="n") || (answ =="N"))
                                    iBool=0;
                                else
                                    iBool=1;
                            }while(iBool);
                        }
                        cartelieu.retirer(l2.getAbscisse(),l2.getOrdonnee());
                        cartelieu.inserer(l2,l2.getAbscisse(),l2.getOrdonnee());
                        break;
                    case 4:
                        //SUPP D'INFO SUR UN LIEU URBAIN
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        l2=cartelieu._tabLieu[x][y];
                        system("clear");
                        /////////////////////////
                        cout<<"Voulez-vous supprimer une étape (o/n) ?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                      cout<<"           Entrez le numero de l'étape à supprimer"<<endl;
                                      cin>>iBuffer;
                                      l2.retirerEtap(iBuffer);
                                      cout<<"           Voulez-vous supprimer une autre étape (o/n) ?"<<endl;
                                      cin>>answ;
                                      if((answ =="n") || (answ =="N"))
                                            iBool=0;
                                      else
                                            iBool=1;
                            }while(iBool);
                        }
                        system("clear");
                        /////////////////////////
                        cout<<"         Voulez-vous supprimer un monument (o/n)?"<<endl;
                        cin>>answ;
                        if((answ=="o") || (answ=="O")){
                            do{
                                      cout<<"           Entrez le numero du monument à supprimer"<<endl;
                                      cin>>iBuffer;
                                      l2.retirerMon(iBuffer);
                                      cout<<"           Voulez-vous supprimer un autre monument (o/n)?"<<endl;
                                      cin>>answ;
                                      if((answ =="n") || (answ =="N"))
                                            iBool=0;
                                      else
                                            iBool=1;
                            }while(iBool);
                        }
                        cartelieu.retirer(l2.getAbscisse(),l2.getOrdonnee());
                        cartelieu.inserer(l2,l2.getAbscisse(),l2.getOrdonnee());
                    default:
                        cout<<"Choix invalide, try again !"<<endl;
                        break;
                    }
                }while(sousmenu3 != 0);
                break;

                case 4 :
                int sousmenu4;
                do
                {
                    system("clear");
                    cout <<"            *******************************************************************"<<endl;
                    cout <<"            ****************************** TRIP *******************************"<<endl;
                    cout <<"            *******************************************************************"<<endl;
                    cartelieu.afficherCarte();
                    Sousmenu4();
                    cin>>sousmenu4;
                    cout<<endl;

                    switch(sousmenu4)
                    {
                    case 0:
                        //RETOUR MENU PRINCIPAL
                        break;
                    case 1:
                        //AJOUT D'UN LABEL
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        cout<<"         Entrez un label:"<<endl;
                        cin>>sBuffer;
                        cartelieu._tabLieu[x][y].ajouterLabel(sBuffer);
                        break;
                    case 2:
                        //SUPP D'UN LABEL
                        cout<<"            Entrez les coordonnées du lieu"<<endl;
                        cout<<"            Ordonnee"<<endl;
                        saisie_Cord(iBuffer);
                        x=iBuffer;
                        cout<<"            Abscisse"<<endl;
                        saisie_Cord(iBuffer);
                        y=iBuffer;
                        cout<<"             Liste des labels associés à ce lieu"<<endl;
                        cartelieu._tabLieu[x][y].afficherLabel();
                        cout<<"             Entrez le label à supprimer"<<endl;
                        cin>>sBuffer;
                        cartelieu._tabLieu[x][y].retirerLabel(sBuffer);
                        break;
                    default:
                        cout<<"Choix invalide, try again !"<<endl;
                        break;
                    }
                }while(sousmenu4!= 0);
                break;

                default:
                cout<<"Choix invalide, try again !"<<endl;
                break;

            }

        }while (menu!=0);

    return 0;
}




