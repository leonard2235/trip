#ifndef SPORT_H
#define SPORT_H
#include<iostream>
#include"../rando/rando.h"
#include"../escalade/escalade.h"
using namespace std;

const int TAILLE_MAX_RANDO=5;
const int TAILLE_MAX_ESCAL=5;

class Sport{
    int _nbRando;
    int _nbEscal;
    Randonnee * tabRando;
    Escalade * tabEscal;
public:
    //Constructeur et desctructeur__________________________
    Sport();
    Sport(const Sport &);
    ~Sport();

    //Accesseurs____________________________________________
    int getNbrando()const;
    int getNbescal()const;

    void setNbrando(const int);
    void setNbescal(const int);

    //Operateurs surcharges_________________________________
    Sport & operator =(const Sport &);

    //Methodes utilitaires__________________________________
    void AjoutRando(const Randonnee &);
    void retirerRando(const int);
    bool Appartientrando(const Randonnee &);
    ////////////////////////////////////////////////////////
    void AjoutEscal(const Escalade & );
    void retirerEscal(const int);
    bool Appartientescal(const Escalade &);
    ////////////////////////////////////////////////////////
    void afficher()const;

};

#endif // SPORT_H
