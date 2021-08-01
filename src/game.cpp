#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "../include/game.h"
using namespace std;

string melangerLettres(string mot){
    string res;
    int position(0);
    int tailleMot(mot.size());
    srand(time(0));
    for(int i(0); i<tailleMot ;++i){
        position = rand() % mot.size();
        res+=mot[position];
        mot.erase(position,1);
    }
    return res;
}

int startGame(string mot){

    string motmelanger;
    string res;
    int essai(6);

    cout << endl;

    do{ 
        --essai;
        if (res.size()!=0) {
            cout << "Ce n'est pas le mot !" << endl;
            cout << endl;
        }
        do{
            motmelanger = melangerLettres(mot);
        }while(mot==motmelanger);
        cout << "Quel est ce mot ? " << motmelanger << endl;

        cin >> res;

    } while(res!=mot && essai > 1 );
    
    if(res==mot){
        cout << "Bravo !" << endl;
        return essai;
    }
    else{
        cout << "Echec, le mot etait " << mot << endl;
        return 0;
    }
}

string pickWord(){
    string const fichier("./dico.txt");
    ifstream monFlux(fichier.c_str());
    vector<string> tableau;
    string mot;
    int position;


    if(monFlux)
    {
        while(monFlux >> mot)
        {   
            tableau.push_back(mot);
        }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier " << fichier << endl;
    }
    monFlux.close();

    int tabSize = tableau.size();
    srand(time(0));
    position = rand() % tabSize;
    return tableau[position];
}