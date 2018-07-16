#include <iostream>
#include "etape.h"
using namespace std;

//constructeurs et destructeur___________________________________________________________
Etape::Etape(){
    _nomEtap="";
    _typEtap="";
    _tarif=0;
}

Etape::Etape(string nomEtap, string typEtap, float tarif){
    _nomEtap=nomEtap;
    _typEtap=typEtap;
    _tarif=tarif;
}

Etape::Etape(const Etape &e){
    _nomEtap=e.getNometap();
    _typEtap=e.getTypetap();
    _tarif=e.getTarif();
}
Etape::~Etape(){}
//accesseurs_____________________________________________________________________________
string Etape::getNometap()const{
    return _nomEtap;
}

string Etape::getTypetap()const{
    return _typEtap;
}

float Etape::getTarif()const{
    return _tarif;
}

void Etape::setNometap(const string & nomEtap){
    _nomEtap=nomEtap;
}

void Etape::setTypetap(const string & typEtap){
    _typEtap=typEtap;
}

void Etape::setTarif(const float & tarif){
    _tarif=tarif;
}
//operateurs surcharges__________________________________________________________________
Etape & Etape::operator =(const Etape & e){
    _nomEtap=e.getNometap();
    _typEtap=e.getTypetap();
    _tarif=e.getTarif();
    return * this;
}

ostream & operator<<(ostream & flux,const Etape & e){
    flux<<"*** Informations sur l'etape *** "<<endl;
    flux<<"*** "<<e._nomEtap<<endl;
    flux<<"*** "<<e._typEtap<<endl;
    flux<<"*** "<<e._tarif<<endl;
}
bool Etape::operator==(const Etape & m){
    if((m.getNometap()==_nomEtap)&&(m.getTypetap()==_typEtap)&&(m.getTarif()==_tarif)){
        return true;
    }
    return false;
}

bool Etape::operator!=(const Etape & m){
    if((m.getNometap()!=_nomEtap)||(m.getTypetap()!=_typEtap)||(m.getTarif()!=_tarif)){
        return true;
    }
    return false;
}
//methodes utilitaires___________________________________________________________________
