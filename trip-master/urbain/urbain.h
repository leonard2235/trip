#ifndef URBAIN_H
#define URBAIN_H
#include <iostream>
#include "../monument/monument.h"
#include "../etape/etape.h"
using namespace std;
const int NB_MONUM=4;
const int NB_ETAP=5;

class Urbain{
    string _nomVille;
    int _nbMon;
    int _nbEtap;
    Monument * _tabMon;
    Etape * _tabEtap;
public:
    //Constructeurs et destructeur_______________________________________________________
    Urbain(string nomVille);
    Urbain();
    ~Urbain();
    Urbain(const Urbain &);

    //Accesseurs_________________________________________________________________________
    string getNomville()const;
    int getNbmon()const;
    int getNbetap()const;
    void setNomville(const string &);
    void setNbmon(const int &);
    void setNbetap(const int &);

    //Operateurs surcharges______________________________________________________________
    Urbain & operator=(const Urbain &);

    //Methodes utilitaires_______________________________________________________________
    bool appartientMon(const Monument &);
    void ajouterMon(const Monument &);
    void retirerMon(const int);
    bool appartientEtap(const Etape &);
    void ajouterEtap(const Etape &);
    void retirerEtap(const int);
    virtual void afficherUrbain()const;

};

#endif // URBAIN_H
