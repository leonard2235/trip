#include"naturel.h"
//constructeurs et destructeur___________________________________________________________
Naturel::Naturel(){
}
Naturel::Naturel(string nomNat,Sport sp, Detente dt){
    _nomNat=nomNat;
    _sp=sp;
    _dt=dt;
}
Naturel::~Naturel(){
}
Naturel::Naturel(const Naturel & n){
    _sp=n._sp;
    _dt=n._dt;
}
//accesseurs_____________________________________________________________________________
//getteurs///////////////////////////////////////////////////////////////////////////////
string Naturel::getNomnat()const{
    return _nomNat;
}
Sport Naturel::getSp()const{
    return _sp;
}
Detente Naturel::getDt()const{
    return _dt;
}
//setteurs///////////////////////////////////////////////////////////////////////////////
void Naturel::setNomnat(const string & nomnat){
    _nomNat=nomnat;
}

void Naturel::setSp(const Sport & sp){
    _sp=sp;
}
void Naturel::setDt(const Detente & dt){
    _dt=dt;
}
//operateurs surcharges__________________________________________________________________
//operator=//////////////////////////////////////////////////////////////////////////////
Naturel & Naturel::operator=(const Naturel & n){
    _sp=n._sp;
    _dt=n._dt;
    return * this;
}
//methodes utilitaires___________________________________________________________________
void Naturel::afficherNaturel()const{
    _sp.afficher();
    _dt.afficher();
}
//_______________________________________________________________________________________
