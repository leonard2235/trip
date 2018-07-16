
do{
    cout<<"Voulez vous ajouter un sport(Randonne ou escalade) (O/n)?"<<endl;
    cin>>sBuffer;
    if ((sBuffer=="O")||(sBuffer=="o")){
        do{
            cout <<"Randonnee ou Escalade (R/r)(E/e) ?"<<endl;
            cin>>answ;
            if ((answ=="R")||(answ=="r")){
                cout<<"Entrez le nom de la randonne !"<<endl;
                cin>>sBuffer;
                rd.setNomRandonnee(sBuffer);
                cout<<"Entrez le point de depart !"<<endl;
                cin>>sBuffer;
                rd.setDepart(sBuffer);
                cout<<"Entrez le point d'arriver' !"<<endl;
                cin>>sBuffer;
                rd.setArrivee(sBuffer);
                cout<<"Entrez la durée !"<<endl;
                cin>>fBuffer;
                rd.setDuree(fBuffer);
                cout<<"Entrez le denivele positif !"<<endl;
                cin>>fBuffer;
                rd.setDenivele(fBuffer);
                sp.AjoutRando(rd);
            }else if((answ=="E") || (answ=="e")){
                cout<<"Entrez le nom de l'escalade' !"<<endl;
                cin>>sBuffer;
                esc.setNomescalade(sBuffer);
                cout<<"Entrez le nombre(s) de voie(s) !"<<endl;
                cin>>iBuffer;
                esc.setNbvoies(iBuffer);
                cout<<"Entrez le niveau minimum !"<<endl;
                cin>>sBuffer;
                esc.setLvlmin(sBuffer);
                cout<<"Entrez le niveau maximum !"<<endl;
                cin>>sBuffer;
                esc.setLvlmax(sBuffer);
                sp.AjoutEscal(esc);
            }else{
                cout<<"Saisie invalide"<<endl;
                cin<<answ;
        }



        }while((answ=="O") || (answ=="o"));

    }





    cout<<"Voulez vous ajouter une autre activité sportive(O/n)?"<<endl;
    cin>>answ;
}while((answ=="O") || (answ=="o"));


