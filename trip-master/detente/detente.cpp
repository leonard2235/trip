#include "detente.h"
//Constructeur et desctructeur_____________________________________________________________________
Detente::Detente()
{
    _nbAct=0;
    _tabAct=NULL;
}

Detente::Detente(const Detente & d){
    _nbAct=d.getNbact();
    _tabAct=new Activite[NB_ACT];

    for(int i=0; i<_nbAct; i++)
        _tabAct[i]=d._tabAct[i];
}

Detente::~Detente(){
    delete [] _tabAct;
    _tabAct=NULL;
}

//Accesseurs_______________________________________________________________________________________

int Detente::getNbact()const{
    return _nbAct;
}

void Detente::setNbact(const int nbact){
    _nbAct=nbact;
}

//Operateurs surcharges____________________________________________________________________________

Detente & Detente::operator =(const Detente & d){
    _nbAct=d.getNbact();

    _tabAct=new Activite[NB_ACT];

    int nbAct=d.getNbact();

    for(int i=0; i<nbAct; i++)
        _tabAct[i]=d._tabAct[i];
    return *this;
}

//Methodes utilitaires_____________________________________________________________________________

void Detente::Ajoutact(const Activite & a){
    if (!Appartientact(a)){
        int nbAct=getNbact();
        Activite * tabTemp = new Activite[nbAct+1];
        for (int i=0; i<nbAct; i++)
            tabTemp[i]=_tabAct[i];
        tabTemp[nbAct]=a;
        delete [] _tabAct;
        _tabAct=tabTemp;
        _nbAct++;
    }
}

bool Detente::Appartientact(const Activite & a){
    int nbAct=getNbact();
    for (int i=0; i<nbAct; i++)
        if(_tabAct[i]==a)
            return true;
     return false;
}

void Detente::afficher()const{
    if(_nbAct>0){
        cout<<"**** > Activites:"<<endl;
        for(int i=0;i<getNbact();i++){
            cout<<"****    "<<"Activité n°("<<i+1<<") "<<endl;
            cout<<"****    ->"<<"Nom activité:"<<_tabAct[i].getNomactivite()<<endl;
            cout<<"****    ->"<<"Horaires :"<<_tabAct[i].getHoraires()<<endl;
            cout<<"****    ->"<<"Tarif :"<<_tabAct[i].getTarif()<<endl;
        }
        }
    cout<<endl;
}


void Detente::retirerAct(const int position){
    if(getNbact()>0){
        int newpos=position-1;
        Activite act;
        act=_tabAct[newpos];
        int nbA=getNbact();
            int j=0;
            int newTaille=nbA-1;

        Activite * tab = new Activite[newTaille];

        for(int i=0;i<nbA;i++){
            if (_tabAct[i]!=act){
                tab[j]=_tabAct[i];
                j++;
            }
        }
        setNbact(newTaille);
        delete [] _tabAct;
        _tabAct=tab;
    }else{
        cout<<"Aucune activité n'est associé à ce Lieu";
    }
}
