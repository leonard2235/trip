#include "activite.h"

//Constructeur et desctructeur__________________________

Activite::Activite()
{
    _nomActivite="";
    _horaires="";
    _tarif=0;
}

Activite::Activite(string nomactivite, string horaires, float tarif)
{
    _nomActivite=nomactivite;
    _horaires=horaires;
    _tarif=tarif;
}

Activite::Activite(const Activite & a )
{
    _nomActivite=a.getNomactivite();
    _horaires=a.getHoraires();
    _tarif=a.getTarif();
}

Activite::~Activite(){

}

//Accesseurs____________________________________________

string Activite::getNomactivite()const{
    return _nomActivite;
}

string Activite::getHoraires()const{
    return _horaires;
}

float Activite::getTarif()const{
    return _tarif;
}

void Activite::setNomactivite(const string nomact){
    _nomActivite=nomact;
}

void Activite::setHoraires(const string horaires){
    _horaires=horaires;
}

void Activite::setTarif(const float tarif){
    _tarif=tarif;
}

//Operateurs surcharges_________________________________

Activite & Activite::operator =(const Activite & a){
    _nomActivite=a.getNomactivite();
    _horaires=a.getHoraires();
    _tarif=a.getTarif();
}

ostream & operator << (ostream & f,Activite & a)
{
    f<<"***** INFORMATIONS-ACTIVITE *****"<<endl;
    f<<"** Nom: "<<a.getNomactivite()<<endl;
    f<<"** Horaires: "<<a.getHoraires()<<endl;
    f<<"** Tarif: "<<a.getTarif()<<endl;
    f<<endl;
    return f;
}

bool Activite::operator ==(const Activite & a){
    if((a.getNomactivite()==_nomActivite)&&(a.getHoraires()==_horaires)&&(a.getTarif()==_tarif))
        return true;
    return false;
}

bool Activite::operator !=(const Activite & a){
    if((a.getNomactivite()!=_nomActivite)||(a.getHoraires()!=_horaires)||(a.getTarif()!=_tarif))
        return true;
    return false;
}


//Methodes utilitaires__________________________________
