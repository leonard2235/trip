#include "escalade.h"

//Constructeur et desctructeur__________________________

Escalade::Escalade()
{
    _nomEscalade="";
    _nbvoies=0;
    _lvlmin="";
    _lvlmax="";
}

Escalade::Escalade(string nomescalade, int nbvoies, string lvlmin, string lvlmax)
{
    _nomEscalade=nomescalade;
    _nbvoies=nbvoies;
    _lvlmin=lvlmin;
    _lvlmax=lvlmax;
}

Escalade::Escalade(const Escalade & e )
{
    _nomEscalade=e.getNomescalade();
    _nbvoies=e.getNbvoies();
    _lvlmin=e.getLvlmin();
    _lvlmax=e.getLvlmax();
}

Escalade::~Escalade()
{
}


//Accesseurs____________________________________________

string Escalade::getNomescalade()const{
    return _nomEscalade;
}

int Escalade::getNbvoies()const{
    return _nbvoies;
}

string Escalade::getLvlmin()const{
    return _lvlmin;
}

string Escalade::getLvlmax()const{
    return _lvlmax;
}

void Escalade::setNomescalade(const string nomescal){
    _nomEscalade=nomescal;
}

void Escalade::setNbvoies(const int nbvoies){
    _nbvoies=nbvoies;
}

void Escalade::setLvlmin(const string lvlmin){
    _lvlmin=lvlmin;
}

void Escalade::setLvlmax(const string lvlmax){
    _lvlmax=lvlmax;
}

//Operateurs surcharges_________________________________

Escalade & Escalade::operator=(const Escalade & e){
    _nomEscalade=e.getNomescalade();
    _nbvoies=e.getNbvoies();
    _lvlmin=e.getLvlmin();
    _lvlmax=e.getLvlmax();
    return *this;
}

ostream & operator << (ostream & f,Escalade & e)
{
    f<<"***** INFORMATIONS-ESCALADE *****:"<<endl;
    f<<"** Nom du site: "<<e._nomEscalade<<endl;
    f<<"** Nombre de voies: "<<e._nbvoies<<endl;
    f<<"** Niveau minimum : "<<e._lvlmin<<endl;
    f<<"** Niveau maximum : "<<e._lvlmax<<endl;
    f<<endl;
    return f;
}

bool Escalade::operator ==(const Escalade & e){
    if((e.getNomescalade()==_nomEscalade)&&(e.getNbvoies()==_nbvoies)&&(e.getLvlmin()==_lvlmin)&&(e.getLvlmax()==_lvlmax))
        return true;
    return false;
}
bool Escalade::operator !=(const Escalade & e){
    if((e.getNomescalade()!=_nomEscalade) || (e.getNbvoies()!=_nbvoies) || (e.getLvlmin()!=_lvlmin) || (e.getLvlmax()!=_lvlmax))
        return true;
    return false;
}

//Methodes utilitaires__________________________________



