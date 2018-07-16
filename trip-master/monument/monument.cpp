#include <iostream>
#include "monument.h"
using namespace std;

//constructeurs et destructeur___________________________________________________________
Monument::Monument(){
    _nomMon="";
    _typMon="";
    _epoq=0;
}

Monument::Monument(string nomMon,string typMon,int epoq){
    _nomMon=nomMon;
    _typMon=typMon;
    _epoq=epoq;
}

Monument::Monument(const Monument & m){
    _nomMon=m.getNommon();
    _typMon=m.getTypmon();
    _epoq=m.getEpoq();
}

Monument::~Monument(){

}
//accesseurs_____________________________________________________________________________
string Monument::getNommon()const{
    return _nomMon;
}

string Monument::getTypmon()const{
    return _typMon;
}

int Monument::getEpoq()const{
    return _epoq;
}

void Monument::setNommon(const string & nomMon){
    _nomMon=nomMon;
}

void Monument::setTypmon(const string & typMon){
    _typMon=typMon;
}

void Monument::setEpoq(const int & epoq){
    _epoq=epoq;
}

//operateurs surcharges____________________________________________________________________________
//operator=////////////////////////////////////////////////////////////////////////////////////////
Monument & Monument::operator=(const Monument & m){
    _nomMon=m.getNommon();
    _typMon=m.getTypmon();
    _epoq=m.getEpoq();
    return * this;
}
//operator<<///////////////////////////////////////////////////////////////////////////////////////
ostream & operator<<(ostream & flux,const Monument & m){
    flux<<"*** Information sur le monument *** "<<endl;
    flux<<"*** "<<m._nomMon<<endl;
    flux<<"*** "<<m._typMon<<endl;
    flux<<"*** "<<m._epoq<<endl;
}
//operator==//////////////////////////////////////////////////////////////////////////////////////
bool Monument::operator==(const Monument & m){
    if((m.getNommon()==_nomMon)&&(m.getTypmon()==_typMon)&&(m.getEpoq()==_epoq)){
        return true;
    }
    return false;
}

bool Monument::operator!=(const Monument & m){
    if((m.getNommon()!=_nomMon) || (m.getTypmon()!=_typMon) || (m.getEpoq()!=_epoq)){
        return true;
    }
    return false;
}


//methodes utilitaires____________________________________________________________________________
