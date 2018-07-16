#ifndef ESCALADE_H
#define ESCALADE_H
#include<iostream>
using namespace std;

class Escalade
{
    string _nomEscalade;
    int _nbvoies;
    string _lvlmin;
    string _lvlmax;
public:
    //Constructeur et desctructeur__________________________
    Escalade();
    Escalade(string,int,string,string);
    Escalade(const Escalade &);
    ~Escalade();
    //Accesseurs____________________________________________
    string getNomescalade()const;
    int getNbvoies()const;
    string getLvlmin()const;
    string getLvlmax()const;

    void setNomescalade(const string);
    void setNbvoies(const int);
    void setLvlmin(const string);
    void setLvlmax(const string);
    //Operateurs surcharges_________________________________
    friend ostream & operator << (ostream & f,Escalade &e);
    Escalade & operator=(const Escalade & );
    bool operator == (const Escalade &);
    bool operator !=(const Escalade &);
    //Methodes utilitaires__________________________________

};

#endif // ESCALADE_H
