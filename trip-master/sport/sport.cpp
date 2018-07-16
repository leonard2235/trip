#include "sport.h"
//Constructeur et desctructeur_____________________________________________________________________
Sport::Sport()
{
    _nbEscal=0;
    _nbRando=0;
    tabEscal=NULL;
    tabRando=NULL;
}

Sport::Sport(const Sport & s){
    _nbEscal=s.getNbescal();
    _nbRando=s.getNbrando();
    tabEscal=new Escalade[TAILLE_MAX_ESCAL];
    tabRando=new Randonnee[TAILLE_MAX_RANDO];

    for(int i=0; i<_nbEscal; i++)
        tabEscal[i]=s.tabEscal[i];

    for(int i=0; i<_nbRando; i++)
        tabRando[i]=s.tabRando[i];
}

Sport::~Sport()
{
    delete []tabEscal;
    tabEscal=NULL;
    delete []tabRando;
    tabRando=NULL;
}

//Accesseurs_______________________________________________________________________________________

int Sport::getNbescal()const{
    return _nbEscal;
}

int Sport::getNbrando()const{
    return _nbRando;
}

void Sport::setNbescal(const int nbescal){
    _nbEscal=nbescal;
}

void Sport::setNbrando(const int nbrando){
    _nbRando=nbrando;
}

//Operateurs surcharges____________________________________________________________________________

Sport & Sport::operator=(const Sport & s){

    _nbEscal=s.getNbescal();
    _nbRando=s.getNbrando();

    tabEscal=new Escalade[TAILLE_MAX_ESCAL];
    tabRando=new Randonnee[TAILLE_MAX_RANDO];

    int nbEscal=getNbescal();
    int nbRando=getNbrando();

    for(int i=0; i<nbEscal; i++)
        tabEscal[i]=s.tabEscal[i];

    for(int i=0; i<nbRando; i++)
        tabRando[i]=s.tabRando[i];
    return *this;
}

//Methodes utilitaires_____________________________________________________________________________

bool Sport::Appartientescal(const Escalade & e){
    int nbEscal=getNbescal();
    for (int i=0; i<nbEscal; i++)
        if(tabEscal[i]==e)
            return true;
     return false;
}

bool Sport::Appartientrando(const Randonnee & r){
    int nbRando=getNbrando();
    for (int i=0; i<nbRando; i++)
        if(tabRando[i]==r)
            return true;
     return false;
}

void Sport::AjoutRando(const Randonnee & r)
{
    if (!Appartientrando(r)){
        int nbRando=getNbrando();
        Randonnee * tabTemp = new Randonnee[nbRando+1];
        for (int i=0; i<nbRando; i++)
            tabTemp[i]=tabRando[i];
        tabTemp[nbRando]=r;
        delete [] tabRando;
        tabRando=tabTemp;
        _nbRando++;
    }
}

void Sport::AjoutEscal(const Escalade & e)
{
    if (!Appartientescal(e)){
        int nbEscal=getNbescal();
        Escalade * tabTemp = new Escalade[nbEscal+1];
        for (int i=0; i<nbEscal; i++)
            tabTemp[i]=tabEscal[i];
        tabTemp[nbEscal]=e;
        delete [] tabEscal;
        tabEscal=tabTemp;
        _nbEscal++;
    }
}

void Sport::afficher()const{
    if(_nbRando>0){
        cout<<"**** > Randonnees:"<<endl;
        for(int i=0;i<getNbrando();i++){
           cout<<"****    "<<"Randonne n°("<<i+1<<") "<<endl;
           cout<<"****    ->"<<"Nom randonne :"<<tabRando[i].getNomRandonnee()<<endl;
           cout<<"****    ->"<<"Depart :"<<tabRando[i].getDepart()<<endl;
           cout<<"****    ->"<<"Arrivee :"<<tabRando[i].getArrivee()<<endl;
           cout<<"****    ->"<<"Duree :"<<tabRando[i].getDuree()<<endl;
           cout<<"****    ->"<<"Denivelee positif :"<<tabRando[i].getDenivele()<<endl;
        }
    }
    if(_nbEscal>0){
        cout<<"**** > Escalades:"<<endl;
        for(int i=0;i<getNbescal();i++){
            cout<<"****    "<<"Escalade n°("<<i+1<<") "<<endl;
            cout<<"****    ->"<<"Nom escalade :"<<tabEscal[i].getNomescalade()<<endl;
            cout<<"****    ->"<<"Nombre de voie(s) :"<<tabEscal[i].getNbvoies()<<endl;
            cout<<"****    ->"<<"Niveau minimum :"<<tabEscal[i].getLvlmin()<<endl;
            cout<<"****    ->"<<"Niveau maximum :"<<tabEscal[i].getLvlmax()<<endl;
        }
    }
}


void Sport::retirerRando(const int position){
    if(getNbrando()>0){
        int newpos=position-1;
        Randonnee rd;
        rd=tabRando[newpos];
        int nbR=getNbrando();
            int j=0;
            int newTaille=nbR-1;

        Randonnee * tab = new Randonnee[newTaille];

        for(int i=0;i<nbR;i++){
            if (tabRando[i]!=rd){
                tab[j]=tabRando[i];
                j++;
            }
        }
        setNbrando(newTaille);
        delete [] tabRando;
        tabRando=tab;
    }else{
        cout<<"Aucune randonnée n'est associée à ce Lieu"<<endl;
    }
}

void Sport::retirerEscal(const int position){
    if(getNbescal()>0){
        int newpos=position-1;
        Escalade esc;
        esc=tabEscal[newpos];
        int nbE=getNbescal();
            int j=0;
            int newTaille=nbE-1;

        Escalade * tab = new Escalade[newTaille];

        for(int i=0;i<nbE;i++){
            if (tabEscal[i]!=esc){
                tab[j]=tabEscal[i];
                j++;
            }
        }
        setNbescal(newTaille);
        delete [] tabEscal;
        tabEscal=tab;
    }else{
        cout<<"Aucun monument n'est associé à ce Lieu";
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
