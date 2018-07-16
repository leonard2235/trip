#ifndef MONUMENT_H
#define MONUMENT_H
#include <iostream>
using namespace std;

class Monument{
    string _nomMon;
    string _typMon;
    int _epoq;
public:
    //Constructeurs et destructeurs______________________________________________________
    Monument(string,string,int);
    Monument();
    ~Monument();
    Monument(const Monument &);
    //Accesseurs_________________________________________________________________________
    string getNommon()const;
    string getTypmon()const;
    int getEpoq()const;

    void setNommon(const string &);
    void setTypmon(const string &);
    void setEpoq(const int &);
    //Operateurs surcharges______________________________________________________________
    Monument & operator=(const Monument & m);
    friend ostream & operator<<(ostream & flux,const Monument & m);
    bool operator==(const Monument & m);
    bool operator!=(const Monument & m);
    //Methodes utilitaires_______________________________________________________________
};
#endif // MONUMENT_H
