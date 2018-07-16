#ifndef RANDO_H
#define RANDO_H
#include<iostream>
using namespace std;

class Randonnee
{
    string _nomRandonnee;
    string _depart;
    string _arrivee;
    float _duree;
    float _denivele;
public:
    //Constructeur et desctructeur__________________________
    Randonnee();
    Randonnee(string,string,string,float,float);
    Randonnee(const Randonnee &);
    ~Randonnee();
    //Accesseurs____________________________________________
    string getNomRandonnee()const;
    string getDepart()const;
    string getArrivee()const;
    float getDuree()const;
    float getDenivele()const;

    void setNomRandonnee(const string);
    void setDepart(const string);
    void setArrivee(const string);
    void setDuree(const float);
    void setDenivele(const float);
    //Operateurs surcharges_________________________________
    friend ostream & operator << (ostream & f,Randonnee &e);
    Randonnee & operator=(const Randonnee & );
    bool operator == (const Randonnee &);
    bool operator !=(const Randonnee &);
    //Methodes utilitaires__________________________________
};

#endif // RANDO_H
