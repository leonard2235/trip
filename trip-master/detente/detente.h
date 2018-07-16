#ifndef DETENTE_H
#define DETENTE_H
#include<iostream>
using namespace std;
#include"../activite/activite.h"
const int NB_ACT=5;

class Detente
{
    int _nbAct;
    Activite * _tabAct;
public:
    //Constructeur et desctructeur_________________________________________________________________
    Detente();
    Detente(int);
    Detente(const Detente &);
    ~Detente();
    //Accesseurs___________________________________________________________________________________
    int getNbact()const;
    void setNbact(const int);
    //Operateurs surcharges________________________________________________________________________
    Detente & operator=(const Detente &);
    //Methodes utilitaires_________________________________________________________________________
    void Ajoutact(const Activite &);
    bool Appartientact(const Activite &);
    void afficher()const;
    void retirerAct(const int);
};

#endif // DETENTE_H
