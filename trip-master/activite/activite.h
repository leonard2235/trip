#ifndef ACTIVITE_H
#define ACTIVITE_H
#include<iostream>
using namespace std;

class Activite
{
    string _nomActivite;
    string _horaires;
    float _tarif;
public:
    //Constructeur et destructeur__________________________________________________________________
    Activite();
    Activite(string,string,float);
    Activite(const Activite &);
    ~Activite();
    //Accesseurs___________________________________________________________________________________
    string getNomactivite()const;
    string getHoraires()const;
    float getTarif()const;
    void setNomactivite(const string);
    void setHoraires(const string);
    void setTarif(const float);
    //Operateurs surcharges________________________________________________________________________
    friend ostream & operator <<(ostream & f, Activite & a);
    Activite & operator =(const Activite &);
    bool operator ==(const Activite &);
    bool operator !=(const Activite &);
    //Methodes utilitaires_________________________________________________________________________
};

#endif // ACTIVITE_H
