/*
 * To change this license header, choose License Headers in Project Properties.
 * To change thizaes template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicolas
 *
 * Created on 20 avril 2018, 10:56
 */
#include <iostream>
using namespace std;
#include <cstdlib>
#include <regex>
#include <string>
#include "Constante.h"
#include "Addition.h"



/*
 * 
 */
int main(int argc, char** argv) {

    string* tab;
    int VALEUR_MAX_TABLEAU=20;
    tab=new string[VALEUR_MAX_TABLEAU];
    int tailleTab=0;
    string c;
    cout<< "entrez votre oppération, appuyez sur entrée après chaque saisie, appuyez sur la touche q suivie de deux fois la touche entrée pour terminer la saisie"<<endl;
    while(c!="q" && c!="Q" ){
        cin >> c;
        if( c!="q" && c!="Q" ){
            tab[tailleTab]=c;
            cout <<c<<endl;
            tailleTab++;
        }
    }
    
    Constante* tabConstante[VALEUR_MAX_TABLEAU];
    Addition* tabAddition[VALEUR_MAX_TABLEAU];
    
    int tailleConstante=0;
    int tailleAddition=0;
    
    int i=0;
    while(i<tailleTab){
        if (regex_match(tab[i], regex{"[+-]?([0-9]*[.])?[0-9]+"})==1){
            tabConstante[tailleConstante]=new Constante(stof( tab[i]));
            tailleConstante+=1;
            if (regex_match(tab[i+1], regex{"[+-]?([0-9]*[.])?[0-9]+"})==1){
                tabConstante[tailleConstante]=new Constante(stof( tab[i+1]));
                tailleConstante+=1;
                if (regex_match(tab[i+2], regex{"^[/+*-]$"})==1){
                    switch (tab[i+2].c_str()[0]){
                        case '+':
                            tabAddition[tailleAddition]=new Addition(tabConstante[tailleConstante-2],tabConstante[tailleConstante-1]);
                            tailleAddition+=1;
                            break;
                        case '-':
                            break;
                        case '*':
                            break;
                        case '/':
                            break;
                    }
                    i+=3;
                }else{
                    cout<< "ERREUR : veuillez saisir une expression valide";
                    return 0;
                }
            }else if (regex_match(tab[i+1], regex{"^[/+*-]$"})==1){
                
                    switch (tab[i+1].c_str()[0]){
                        case '+':
                            tabAddition[tailleAddition]=new Addition(tabAddition[tailleAddition-1],tabConstante[tailleConstante-1]);
                            tailleAddition+=1;
                            break;
                        case '-':
                            break;
                        case '*':
                            break;
                        case '/':
                            break;
                    }
                    i+=2;
                }else{
                cout<< "ERREUR : veuillez saisir une expression valide";
                return 0;
            }
        }else if (regex_match(tab[i], regex{"^[/+*-]$"})==1){
            switch (tab[i].c_str()[0]){
                        case '+':
                            tabAddition[tailleAddition]=new Addition(tabAddition[tailleAddition-1],tabAddition[tailleAddition-2]);
                            tailleAddition+=1;
                            break;
                        case '-':
                            break;
                        case '*':
                            break;
                        case '/':
                            break;
                    }
                    i++;
        }else{
            cout<< "ERREUR : veuillez saisir une expression valide";
            return 0;
        }
    }
    cout<< "résultat :";
    tabAddition[tailleAddition-1]->afficher();
    
    return 0;
}

