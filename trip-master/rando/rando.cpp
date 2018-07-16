#include "rando.h"

//Constructeur et desctructeur__________________________

Randonnee::Randonnee()
{
    _nomRandonnee="";
    _depart="";
    _arrivee="";
    _duree=0;
    _denivele=0;
}

Randonnee::Randonnee(string nomRandonnee, string depart, string arrivee, float duree, float denivele)
{
    _nomRandonnee=nomRandonnee;
    _depart=depart;
    _arrivee=arrivee;
    _duree=duree;
    _denivele=denivele;
}

Randonnee::Randonnee(const Randonnee & r )
{
    _nomRandonnee=r.getNomRandonnee();
    _depart=r.getDepart();
    _arrivee=r.getArrivee();
    _duree=r.getDuree();
    _denivele=r.getDenivele();
}

Randonnee::~Randonnee()
{
}


//Accesseurs____________________________________________

string Randonnee::getNomRandonnee()const{
    return _nomRandonnee;
}

string Randonnee::getDepart()const{
    return _depart;
}

string Randonnee::getArrivee()const{
    return _arrivee;
}

float Randonnee::getDuree()const{
    return _duree;
}

float Randonnee::getDenivele()const{
    return _denivele;
}
void Randonnee::setNomRandonnee(const string nomrando){
    _nomRandonnee=nomrando;
}

void Randonnee::setDepart(const string depart){
    _depart=depart;
}

void Randonnee::setArrivee(const string arrivee){
    _arrivee=arrivee;
}

void Randonnee::setDuree(const float duree){
    _duree=duree;
}

void Randonnee::setDenivele(const float deniv){
    _denivele=deniv;
}

//Operateurs surcharges_________________________________

Randonnee & Randonnee::operator=(const Randonnee & r){
    _nomRandonnee=r.getNomRandonnee();
    _depart=r.getDepart();
    _arrivee=r.getArrivee();
    _duree=r.getDuree();
    _denivele=r.getDenivele();
    return *this;
}

ostream & operator<<(ostream & f,Randonnee & r)
{
    f<<"***** INFORMATIONS-RANDONNEE *****:"<<endl;
    f<<"** Nom de la Randonnee: "<<r.getNomRandonnee()<<endl;
    f<<"** Lieu de depart: "<<r.getDepart()<<endl;
    f<<"** Lieu d'arrivée: "<<r.getArrivee()<<endl;
    f<<"** Duree: "<<r.getDuree()<<endl;
    f<<"** Denivele positif: "<<r.getDenivele()<<endl;
    f<<endl;
    return f;
}

bool Randonnee::operator ==(const Randonnee & r){
    if((r.getNomRandonnee()==_nomRandonnee)&&(r.getDepart()==_depart)&&(r.getArrivee()==_arrivee)&&(r.getDuree()==_duree)&&(r.getDenivele()==_denivele))
        return true;
    return false;
}

bool Randonnee::operator !=(const Randonnee & r){
    if((r.getNomRandonnee()!=_nomRandonnee) || (r.getDepart()!=_depart) || (r.getArrivee()!=_arrivee) || (r.getDuree()!=_duree) || (r.getDenivele()!=_denivele))
        return true;
    return false;
}
//Methodes utilitaires__________________________________



