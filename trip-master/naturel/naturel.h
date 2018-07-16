#ifndef NATUREL_H
#define NATUREL_H
#include<iostream>
#include"../detente/detente.h"
#include"../sport/sport.h"

using namespace std;

class Naturel{
        string _nomNat;
        Sport _sp;
        Detente _dt;
public:
    //contructeurs et destructeur________________________________________________________
    Naturel();
    Naturel(string nomNat,Sport sp,Detente dt);
    ~Naturel();
    Naturel(const Naturel &);
    //accesseurs_________________________________________________________________________
    //getteurs///////////////////////////////////////////////////////////////////////////
    string getNomnat()const;
    Sport getSp()const;
    Detente getDt()const;
    //setteurs///////////////////////////////////////////////////////////////////////////
    void setNomnat(const string &);
    void setSp(const Sport &);
    void setDt(const Detente &);
    //surcharge d'operateurs_____________________________________________________________
    Naturel & operator=(const Naturel &);
    //methodes utilitaires_______________________________________________________________
    virtual void afficherNaturel()const;

};
#endif // NATUREL_H
