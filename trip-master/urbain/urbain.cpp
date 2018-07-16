#include <iostream>
#include "urbain.h"
using namespace std;


//Constructeurs et destructeur___________________________________________________________
//constructeur par defaut////////////////////////////////////////////////////////////////
Urbain::Urbain(){
    _nbMon=0;
    _nbEtap=0;
    _nomVille="";
    _tabMon=NULL;
    _tabEtap=NULL;
}

//contructeur avec parametres////////////////////////////////////////////////////////////
Urbain::Urbain(string nomVille){
    _nomVille=nomVille;
    _nbMon=0;
    _nbEtap=0;
    _tabMon=NULL;
    _tabEtap=NULL;
}
//constructeur par recopie///////////////////////////////////////////////////////////////
Urbain::Urbain(const Urbain & u){
    _nomVille=u._nomVille;
    _nbMon=u._nbMon;
    _nbEtap=u._nbEtap;
    _tabEtap= new Etape[NB_ETAP];
    _tabMon= new Monument[NB_ETAP];

    for(int i=0;i<_nbEtap;i++){
        _tabEtap[i]=u._tabEtap[i];
    }

    for(int i=0;i<_nbMon;i++){
        _tabMon[i]=u._tabMon[i];
    }

}
//destructeur////////////////////////////////////////////////////////////////////////////
Urbain::~Urbain(){
    delete [] _tabMon;
    _tabMon=NULL;
    delete [] _tabEtap;
    _tabEtap=NULL;
}

//Accesseurs_____________________________________________________________________________
//getteurs///////////////////////////////////////////////////////////////////////////////
string Urbain::getNomville()const{
    return _nomVille;
}
int Urbain::getNbmon()const{
    return _nbMon;
}
int Urbain::getNbetap()const{
    return _nbEtap;
}

//setteurs///////////////////////////////////////////////////////////////////////////////
void Urbain::setNomville(const string & nomVille){
    _nomVille=nomVille;
}

void Urbain::setNbmon(const int & nbMon){
    _nbMon=nbMon;
}

void Urbain::setNbetap(const int & nbEtap){
    _nbEtap=nbEtap;
}

//Operateurs surcharges__________________________________________________________________
//operator=//////////////////////////////////////////////////////////////////////////////
Urbain & Urbain::operator =(const Urbain & u){
    _nomVille=u._nomVille;
    _nbMon=u._nbMon;
    _nbEtap=u._nbEtap;
    _tabEtap= new Etape[NB_ETAP];
    _tabMon= new Monument[NB_MONUM];

    int nbE=_nbEtap;
    int nbM=_nbMon;

    for(int i=0;i<nbE;i++){
        _tabEtap[i]=u._tabEtap[i];
    }

    for(int i=0;i<nbM;i++){
        _tabMon[i]=u._tabMon[i];
    }
    return * this;
}

//methodes utilitaires_____________________________________________________________________________
//verification de l'appartenance d'un monument au tableau de monuments/////////////////////////////
bool Urbain::appartientMon(const Monument & m){
    int nb=getNbmon();
    for (int i=0; i<nb;i++)
        if(_tabMon[i]==m)
            return true;
     return false;
}

//ajout d'un monument au tableau de monuments//////////////////////////////////////////////////////
void Urbain::ajouterMon(const Monument & m){
    if (!appartientMon(m)){
        int nb=getNbmon();
        Monument * tabTemp = new Monument[nb+1];
        for (int i=0; i<nb; i++)
            tabTemp[i]=_tabMon[i];
        tabTemp[nb]=m;
        delete [] _tabMon;
        _tabMon=tabTemp;
        _nbMon++;
    }
}

//suppression d'un monument du tableau de monument/////////////////////////////////////////////////
void Urbain::retirerMon(const int position){
    if(getNbmon()>0){
        int newpos=position-1;
        Monument m;
        m=_tabMon[newpos];
        int nbM=getNbmon();
            int j=0;
            int newTaille =nbM-1;

        Monument * tab = new Monument[newTaille];

        for(int i=0;i<nbM;i++){
            if (_tabMon[i]!=m){
                tab[j]=_tabMon[i];
                j++;
            }
        }
        setNbmon(newTaille);
        delete [] _tabMon;
        _tabMon=tab;
    }else{
        cout<<"Aucun monument n'est associé à ce Lieu";
    }
}

//verification de l'appartenance d'une etape au tableau d'etapes///////////////////////////////////
bool Urbain::appartientEtap(const Etape & e){
    int nb=getNbetap();
    for (int i=0; i<nb; i++)
        if(_tabEtap[i]==e)
            return true;
    return false;
}

//ajout d'une etape au tableau d'etapes//////////////////////////////////////////////////
void Urbain::ajouterEtap(const Etape & e){
    if (!appartientEtap(e)){
        int nb=getNbetap();
        Etape * tabTemp = new Etape[nb+1];
        for (int i=0; i<nb; i++)
            tabTemp[i]=_tabEtap[i];
        tabTemp[nb]=e;
        delete [] _tabEtap;
        _tabEtap=tabTemp;
        _nbEtap++;
    }
}

//suppression d'une etape du tableau d'etapes//////////////////////////////////////////////////////
void Urbain::retirerEtap(const int position){
    if(getNbetap()>0){
        int newpos=position-1;
        Etape e;
        e=_tabEtap[newpos];
        int nbE=getNbetap();
            int j=0;
            int newTaille =nbE-1;

        Etape * tab = new Etape[newTaille];

        for(int i=0;i<nbE;i++){
            if (_tabEtap[i]!=e){
                tab[j]=_tabEtap[i];
                j++;
            }
        }
        setNbetap(newTaille);
        delete [] _tabEtap;
        _tabEtap=tab;
    }else{
        cout<<"Aucune étape n'est associée à ce Lieu"<<endl;
    }
}

//afficherUrbain///////////////////////////////////////////////////////////////////////////////////
void Urbain::afficherUrbain()const{
        cout<<"**** > Ville: "<<getNomville()<<endl;
        if(_nbMon>0){
            cout<<"**** > Monument(s):"<<endl;
            for(int i=0; i<getNbmon(); i++){
                cout<<"****    "<<"Monument n°("<<i+1<<") "<<endl;
                cout<<"****    ->"<<"Nom monument :"<<_tabMon[i].getNommon()<<endl;
                cout<<"****    ->"<<"Type monument :"<<_tabMon[i].getTypmon()<<endl;
                cout<<"****    ->"<<"Epoque :"<<_tabMon[i].getEpoq()<<endl;
            }
        }
        if(_nbEtap>0){
            cout<<"**** > Etape(s) :"<<endl;
            for(int i=0;i<getNbetap();i++){
                cout<<"****    "<<"Etape(s) n°("<<i+1<<") "<<endl;
                cout<<"****    ->"<<"Nom etape :"<<_tabEtap[i].getNometap()<<endl;
                cout<<"****    ->"<<"Type de l'etape' :"<<_tabEtap[i].getTypetap()<<endl;
                cout<<"****    ->"<<"Tarif :"<<_tabEtap[i].getTarif()<<endl;
            }

        }
}
///////////////////////////////////////////////////////////////////////////////////////////////////















