#include <iostream>
#include "lieu.h"

using namespace std;
//constructeurs et destructeur___________________________________________________________

//constructeur par defaut////////////////////////////////////////////////////////////////
Lieu::Lieu()
{
    _abscisse=-1;
    _ordonnee=-1;
    _nbLabel=0;
    _tabLabel=NULL;
}

//constructeur avec parametres///////////////////////////////////////////////////////////
Lieu::Lieu(string nomVille,string nomNat,Sport sp,Detente dt,int abscisse,int ordonnee)
    :Urbain(nomVille),Naturel(nomNat,sp,dt){
    _ordonnee=ordonnee;
    _abscisse=abscisse;
    _nbLabel=0;
    _tabLabel=NULL;
}

//constructeurs par recopie//////////////////////////////////////////////////////////////
Lieu::Lieu(const Lieu & l)
{
    _nbLabel=l.getNbLabel();
    _abscisse=l.getAbscisse();
    _ordonnee=l.getOrdonnee();
    string * _tabLabel=NULL;
    _tabLabel = new string[NB_LABEL];
    for (int i=0; i<_nbLabel; i++){
        _tabLabel[i]=l._tabLabel[i];
    }
}

//destructeur////////////////////////////////////////////////////////////////////////////
Lieu::~Lieu(){
    if (_tabLabel!=NULL){
        delete [] _tabLabel;
        _tabLabel=NULL;
        _nbLabel=0;
    }
}

//accesseurs_____________________________________________________________________________

//getteurs///////////////////////////////////////////////////////////////////////////////
int Lieu::getAbscisse()const{
    return _abscisse;
}

int Lieu::getOrdonnee()const{
    return _ordonnee;
}

int Lieu::getNbLabel()const{
    return _nbLabel;
}

//setteurs//////////////////////////////////////////////////////////////////////////////
void Lieu::setAbscisse(const int abs){
    _abscisse=abs;
}

void Lieu::setOrdonnee(const int ord){
    _ordonnee=ord;
}

void Lieu::setNbLabel(const int nblabel){
    _nbLabel=nblabel;
}
//operateurs surcharges__________________________________________________________________
//operator=//////////////////////////////////////////////////////////////////////////////
Lieu & Lieu::operator =(const Lieu & l){
    this->Urbain::operator=(l); //Appel explicite à la méthode operator= de Urbain
    this->Naturel::operator=(l); //Appel explicite à la methode operator= de Naturel

    int nb=l.getNbLabel();

    _abscisse=l.getAbscisse();
    _ordonnee=l.getOrdonnee();
    _nbLabel=l.getNbLabel();
    _tabLabel= new string[NB_LABEL];

    for (int i=0; i<nb; i++){
        _tabLabel[i]=l._tabLabel[i];
    }
    return *this;
}

//operator<</////////////////////////////////////////////////////////////////////////////
ostream & operator<<(ostream & flux,const Lieu & lieu){
    if((lieu.getNomville()!="") || (lieu.getNbmon()!=0) || (lieu.getNbetap()!=0)){//Le lieu est d'interet urbain -> flux sort V dans l'affichage de la carte
        flux<<"V";
    }else if((lieu.getNomnat()!="") || (lieu.getSp().getNbescal()!=0) || (lieu.getSp().getNbrando()!=0) || (lieu.getDt().getNbact()!=0)){//Le lieu est d'interet naturel -> flux sort N dans l'affichage de la carte
        flux<<"N";
    }else{//Le lieu n'a aucun interet -> flux sort " " dans l'affichage de la carte
        flux<<"-";
    }
}

//operator==/////////////////////////////////////////////////////////////////////////////
bool Lieu::operator ==(const Lieu & l){
    if((l.getNomville()==getNomville() && l.getAbscisse()==getAbscisse() && l.getOrdonnee()==getOrdonnee()) || (l.getNomnat()==getNomnat() && l.getAbscisse()==getAbscisse() && l.getOrdonnee()==getOrdonnee())){
        return true;
    }
    return false;
}

//Methodes utilitaires___________________________________________________________________
//affichage d'un lieu////////////////////////////////////////////////////////////////////
void Lieu::afficherInfo()const{
    if((getAbscisse()<0) && (getOrdonnee()<0)){
        cout<<"            Aucun information n'est associée à ce lieu (lieu sans interêt)"<<endl;
    }else if((getNomville()!="") || (getNbmon()!=0) || (getNbetap()!=0)){//Le lieu est d'interet urbain -> appel de la methode polymorphe afficherUrbain
        afficherUrbain();
    }else if((getSp().getNbescal())!=0 || ((getSp().getNbrando())!=0) || ((getDt().getNbact())!=0)){//Le lieu est d'interet naturel -> appel de la methode polymorphe afficherNaturel
        afficherNaturel();
    }
}

void Lieu::afficherNaturel()const{
    if((getAbscisse()>=0) && (getOrdonnee()>=0)){
        cout<<"*************** INFORMATIONS-LIEU ***************"<<endl;
        cout<<"**** > Coordonnées: ["<<getAbscisse()<<"-"<<getOrdonnee()<<"]"<<endl;
        if(getNbLabel()>0){
            cout<<"**** > Labels: "<<endl;
            for(int i=0;i<getNbLabel();i++)
            cout<<"****     - "<<_tabLabel[i]<<endl;
            }else{
                cout<<"Aucun Label n'est associé à ce lieu"<<endl;
            }
    }else{
        cout<<"Lieu non défini sur la cartdife"<<endl;
    }
    Naturel::afficherNaturel();
}

void Lieu::afficherUrbain()const{
    if((getAbscisse()>=0) && (getOrdonnee()>=0)){
        cout<<"*************** INFORMATIONS-LIEU ***************"<<endl;
        cout<<"**** > Coordonnées: ["<<getAbscisse()<<"-"<<getOrdonnee()<<"]"<<endl;
        if(getNbLabel()>0){
            cout<<"**** -> Labels: "<<endl;
            for(int i=0;i<getNbLabel();i++)
            cout<<"****     -> "<<_tabLabel[i]<<endl;
            }else{
                cout<<"Aucun Label n'est associé à ce lieu"<<endl;
            }

    }else{
        cout<<"Lieu non défini sur la carte"<<endl;
    }
    Urbain::afficherUrbain();
}

//verification de l'appartenance d'un label au tableau de label//////////////////////////
bool Lieu::appartientLabel(const string & l){
    int nb=getNbLabel();
    for (int i=0; i<nb; i++)
        if(_tabLabel[i]==l)
            return true;
    return false;
}

//ajout d'un label au tableau de labels//////////////////////////////////////////////////

void Lieu::ajouterLabel(const string & l){
    if (!appartientLabel(l)){
        int nb=getNbLabel();
        string * tabTemp = new string[nb+1];
        for (int i=0; i<nb; i++)
            tabTemp[i]=_tabLabel[i];
        tabTemp[nb]=l;
        delete [] _tabLabel;
        _tabLabel=tabTemp;
        _nbLabel++;
    }else{
        cout<<"Ce label est déjà associé à ce lieu"<<endl;
    }
}

//supression d'un label//////////////////////////////////////////////////////////////////
void Lieu::retirerLabel(const string l){
    int nbL=getNbLabel();
    if(getAbscisse()>=0 && getOrdonnee()>=0){
        if (appartientLabel(l)){
            int j=0;
            int newTaille = nbL-1;

        string * tab1 = new string[newTaille];

        for(int i=0; i<nbL; i++){
            if (_tabLabel[i]!=l){
                tab1[j]=_tabLabel[i];
                j++;
            }
        }
        setNbLabel(newTaille);
        delete [] _tabLabel;
        _tabLabel=tab1;
        }else{
            cout<<"         Ce label ne correspond a aucun des labels associés à ce lieu"<<endl;
        }
    }else cout<<"          Ce lieu n'est pas défini"<<endl;
}

void Lieu::afficherLabel()const{
    int nbL=getNbLabel();
    for(int i=0;i<nbL;i++){
        cout<<"         "<<_tabLabel[i]<<endl;
    }
}
//_______________________________________________________________________________________

