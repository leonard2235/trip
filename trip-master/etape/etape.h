#ifndef ETAPE_H
#define ETAPE_H
#include <iostream>
using namespace std;

class Etape{
    string _nomEtap;
    string _typEtap;
    float _tarif;
public:
    //constructeurs et destructeur_______________________________________________________
    Etape(string,string,float);
    Etape();
    Etape(const Etape &);
    ~Etape();
    //accesseurs_________________________________________________________________________
    string getNometap()const;
    string getTypetap()const;
    float getTarif()const;

    void setNometap(const string &);
    void setTypetap(const string &);
    void setTarif(const float &);
    //operateurs surcharges______________________________________________________________
    Etape & operator=(const Etape &);
    friend ostream & operator<<(ostream & flux,const Etape &);
    bool operator==(const Etape &);
    bool operator!=(const Etape &);
    //methodes utilitaires_______________________________________________________________
};
#endif // ETAPE_H
