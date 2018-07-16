#ifndef LIEU_H
#define LIEU_H
#include<iostream>
#include "../naturel/naturel.h"
#include "../urbain/urbain.h"
using namespace std;
const int NB_LABEL=3;

class Lieu:public Urbain,public Naturel{
    int _abscisse;
    int _ordonnee;
    int _nbLabel;
    string * _tabLabel;
public:
    //constructeurs et destructeur_______________________________________________________
    Lieu();
    Lieu(string nomVille,string nomNat,Sport sp,Detente dt,int abscisse,int ordonnee);
    Lieu(const Lieu &);
    ~Lieu();
    //accesseurs_________________________________________________________________________
    int getAbscisse()const;
    int getOrdonnee()const;
    int getNbLabel()const;
    void setAbscisse(const int);
    void setOrdonnee(const int);
    void setNbLabel(const int);
    //operateurs surcharges____________________________________________________________
    Lieu & operator =(const Lieu &);
    friend ostream & operator<<(ostream & flux,const Lieu &);
    bool operator ==(const Lieu &);
    //methodes utilitaires_____________________________________________________________
    void ajouterLabel(const string &);
    bool appartientLabel(const string &);
    void retirerLabel(const string);
    void afficherNaturel()const;
    void afficherUrbain()const;
    void afficherInfo()const;
    void afficherLabel()const;
};

#endif // LIEU_H
