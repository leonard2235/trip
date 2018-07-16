#include <iostream>
using namespace std;

const int CSIZE=10;
const int LSIZE=10;

template<class T> class Carte{
    int _nbL;
    int _nbC;
public:
    T ** _tabLieu;
    //constructeurs et destructeur_________________________________________________________________
    Carte(int nbL=LSIZE,int nbC=CSIZE);//initialisation par defaut;
    Carte(const Carte &);
    ~Carte();
    //Getteurs_____________________________________________________________________________________
    int getNbl()const{return _nbL;}
    int getNbc()const{return _nbC;}
    //operateurs surcharges________________________________________________________________________
    Carte & operator=(const Carte &);
    //methodes utilitaires_________________________________________________________________________
    void afficherCarte()const;
    void inserer(const T &,int,int);
    void retirer(int,int);
    T retour(int,int);
};


//Constructeurs et destructeur___________________________________________________________
//Constructeur par defaut///////////////////////////////////////////////////////////////
template<class T>
Carte<T>::Carte(int nbL,int nbC):_nbL(nbL),_nbC(nbC){
    _tabLieu= new T * [nbC];
    for(int i=0;i<nbC;i++){
        _tabLieu[i]= new T [nbL];
    }
}

//Constructeur par recopie///////////////////////////////////////////////////////////////
template <class T>
Carte<T>::Carte(const Carte & c):_nbL(c.getNbl()),_nbC(c.getNbc()){
     _tabLieu= new T * [_nbC];
     for(int i=0;i<_nbC;i++){
         _tabLieu[i]= new T [_nbL];
     }
     for(int i=0;i<_nbC;i++){
         for(int j=0;i<_nbL;i++){
             _tabLieu[i][j]=c._tabLieu[i][j];
         }

     }

}

//Destructeur////////////////////////////////////////////////////////////////////////////
template <class T>
Carte<T>::~Carte(){
    for(int i=0;i<getNbc();i++){ T t;
          delete [] _tabLieu[i];
        _tabLieu[i]=NULL;
    }
       delete[] _tabLieu;
}


//Methodes utilitaires_____________________________________________________________________________
//Affichage de la carte(tableau 2d)////////////////////////////////////////////////////////////////
template <class T>
void Carte<T>::afficherCarte()const{
    cout<<"                                                 ";
    for(int i=0;i<_nbC;i++){
    cout<<"  "<<i;
    }
    cout<<endl;
    for(int i=0;i<_nbC;i++){
        if(i==0){
            cout<<"            **** Légende ****                   "<<i<<" ";
        }else if(i==1){
            cout<<"            ** V: Lieu d'interêt urbain         "<<i<<" ";
        }else if(i==2){
            cout<<"            ** N: Lieu d'interêt naturel        "<<i<<" ";
        }else if(i==3){
            cout<<"            ** -: Lieu sans interêt             "<<i<<" ";
        }else{
    cout<<"                                                "<<i<<" ";
        }
        for(int j=0;j<_nbL;j++){
            cout<<" "<<_tabLieu[i][j]<<" ";
        }
cout<<endl;
    }
}
//Insertion d'un element au tableau 2d/////////////////////////////////////////////////////////////
template<class T>
void Carte<T>::inserer(const T & t,int x,int y){
    T test;
    if(_tabLieu[x][y]==test){
        _tabLieu[x][y]=t;
    }else{
         cout<<"Il existe deja un element à ces coordonnées"<<endl;
    }
}
//Retrait d'un l'element du tableau 2d/////////////////////////////////////////////////////////////
template<class T>
void Carte<T>::retirer(int x,int y){
    T test;
    if(_tabLieu[x][y]==test){
        cout<<"**** Aucun element à supprimer pour ces coordonnées"<<endl;
    }else{
         _tabLieu[x][y]=test;
    }
}
