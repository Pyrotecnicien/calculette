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

using namespace std;
#include <iostream>
#include <cstdlib>
#include <regex>
#include <string>
#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"


string modifieChaine(string notationNormale, int leSigne);
string modifieChaine(string notationNormale);
int Calc(void);
//void ChargerCalcul(void);

/*
 * 
 */

int Menu;
int main(int argc, char** argv) {
    
    while(1){
    //Calc();
    cout << "Taper 1 pour lancer un calcul, 0 pour quitter"<<endl;
    cin >> Menu;
    
        switch (Menu) {
            case 1:
                Calc();
            break;
            //case '2':
            //    ChargerCalcul();
            //    break;
            
            case 0:
                return 0;
                
        }
    }
        return 0;
}

int Calc(void) {
    float x = 5;
    float y = 9;
    //l'interface pour cahnger la valeur des variables
    cout << "Les variables acceptées sont x et y, leurs valeurs de base sont 5 et 9, souhaitez vous les changer ? (y/n), entrée pour valider" << endl;
    string c;
    while (c != "y" && c != "n" && c != "Y" && c != "N") {
        cin >> c;
        if (c != "y" && c != "n" && c != "Y" && c != "N") {
            cout << c << endl;
            cout << "veuillez entrer une lettre valide (y ou n), entrée pour valider" << endl;
        } //else
        //cout << c << endl;
    }
    if (c == "y" || c == "Y") {
        string variable;
        cout << "affectez une nouvelle valeur Ã  x, entrée pour valider :" << endl;
        cin >> variable;
        cout << variable << endl;
        if (regex_match(variable, regex{"[+-]?([0-9]*[.])?[0-9]+"}) == 1) {
            x = stof(variable);
        } else {
            cout << "erreur, la valeur entrée est incorecte, x vaut toujours 5" << endl;
        }
        cout << "affectez une nouvelle valeur Ã  y, double entrée pour valider :" << endl;
        cin >> variable;
        cout << variable << endl;
        if (regex_match(variable, regex{"[+-]?([0-9]*[.])?[0-9]+"}) == 1) {
            y = stof(variable);
        } else {
            cout << "erreur, la valeur entrée est incorecte, y vaut toujours 8" << endl;
        }
    }






    //l'interface pour faire Ã©crire Ã  l'utilisateur son opÃ©ration
    string* tab;
    int VALEUR_MAX_TABLEAU = 20;
    tab = new string[VALEUR_MAX_TABLEAU];
    int tailleTab = 0;
    cout << "entrez votre opération, appuyez sur entrée après chaque saisie, appuyez sur la touche q suivie de la touche entrée pour terminer la saisie" << endl;
    cout << "rappel, les variables acceptées sont x et y" << endl;
    while (c != "q" && c != "Q") {
        cin >> c;
        if (c != "q" && c != "Q") {
            tab[tailleTab] = c;
            //cout << c << endl;
            tailleTab++;
        }
    }
    
    int nombre = 0;
    int operande=0;
    for(int i=0; i<=tailleTab;++i)
    {
        if (regex_match(tab[i], regex{"[+-]?([0-9]*[.])?[0-9]+"}) == 1 || (regex_match(tab[i], regex{"^[xy]$"}) == 1)) {nombre +=1;}
        if (regex_match(tab[i], regex{"^[/+*-]$"}) == 1) {operande +=1;}
    }
    cout << "operande" << operande << " nombre" << nombre;
    if (nombre-operande != 1){cout << "NPI pas bon : " << nombre-operande <<endl;}       

    Constante * tabConstante[VALEUR_MAX_TABLEAU];
    Operation * tabOperation[VALEUR_MAX_TABLEAU];

    int tailleConstante = 0;
    int tailleOperation = 0;
    string notationNormale;
    int i = 0;
    int j = 0;
    //traitement de l'opÃ©ration avec vÃ©rification d'erreur
    while (i < tailleTab) {
        // si le premier est un chiffre
        if (regex_match(tab[i], regex{"[+-]?([0-9]*[.])?[0-9]+"}) == 1) {
            tabConstante[tailleConstante] = new Constante(stof(tab[i]), x, y);
            tailleConstante += 1;
            //si le deuxieme est un chiffre
            if (regex_match(tab[i + 1], regex{"[+-]?([0-9]*[.])?[0-9]+"}) == 1) {
                tabConstante[tailleConstante] = new Constante(stof(tab[i + 1]), x, y);
                tailleConstante += 1;
                //si le troisieme est un signe
                if (regex_match(tab[i + 2], regex{"^[/+*-]$"}) == 1) {
                    switch (tab[i + 2].c_str()[0]) {
                        case '+':
                            tabOperation[tailleOperation] = new Addition(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '+' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '-':
                            tabOperation[tailleOperation] = new Soustraction(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '-' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '*':
                            tabOperation[tailleOperation] = new Multiplication(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '*' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '/':
                            tabOperation[tailleOperation] = new Division(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '/' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                    }
                    i += 3;
                    //sinon le troisieme est une erreur
                } else {
                    cout << "ERREUR : veuillez saisir une expression valide";
                    //Menu = 1;
                    return 0;
                }
                //si le deuxieme est un signe
            } else if (regex_match(tab[i + 1], regex{"^[/+*-]$"}) == 1) {

                switch (tab[i + 1].c_str()[0]) {
                    case '+':
                        tabOperation[tailleOperation] = new Addition(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        notationNormale += '+' + to_string(tabConstante[tailleConstante - 1]->calculer());
                        notationNormale =modifieChaine(notationNormale);
                        tailleOperation += 1;
                        break;
                    case '-':
                        tabOperation[tailleOperation] = new Soustraction(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        notationNormale += '-' + to_string(tabConstante[tailleConstante - 1]->calculer());
                        notationNormale =modifieChaine(notationNormale);
                        tailleOperation += 1;
                        break;
                    case '*':
                        tabOperation[tailleOperation] = new Multiplication(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        notationNormale += '*' + to_string(tabConstante[tailleConstante - 1]->calculer());
                        notationNormale =modifieChaine(notationNormale);
                        tailleOperation += 1;
                        break;
                    case '/':
                        tabOperation[tailleOperation] = new Division(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        notationNormale += '/' + to_string(tabConstante[tailleConstante - 1]->calculer());
                        notationNormale =modifieChaine(notationNormale);
                        tailleOperation += 1;
                        break;
                }
                i += 2;
                //si le deuxieme est une variable
            } else if (regex_match(tab[i + 1], regex{"^[xy]$"}) == 1) {
                tabConstante[tailleConstante] = new Constante(tab[i + 1].c_str()[0], x, y);
                tailleConstante += 1;
                //si le troisieme est un signe
                if (regex_match(tab[i + 2], regex{"^[/+*-]$"}) == 1) {
                    switch (tab[i + 2].c_str()[0]) {
                        case '+':
                            tabOperation[tailleOperation] = new Addition(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '+' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '-':
                            tabOperation[tailleOperation] = new Soustraction(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '-' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '*':
                            tabOperation[tailleOperation] = new Multiplication(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '*' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '/':
                            tabOperation[tailleOperation] = new Division(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '/' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                    }
                    i += 3;
                }else{
                    //sinon le troiseme est une erreur&
                    cout << "ERREUR : veuillez saisir une expression valide";
                    //Menu = 1;
                    return 0;
                }
                //sinon le deuxieme est une erreur
            } else {
                cout << "ERREUR : veuillez saisir une expression valide";
                              //Menu = 1;
                    return 0;
            }
            //si le premier est un signe
        } else if (regex_match(tab[i], regex{"^[/+*-]$"}) == 1) {
            j = 0;
            switch (tab[i].c_str()[0]) {
                case '+':
                    tabOperation[tailleOperation] = new Addition(tabOperation[tailleOperation - 1], tabOperation[tailleOperation - 2]);
                    notationNormale = modifieChaine(notationNormale, 1);
                    tailleOperation += 1;
                    break;
                case '-':
                    tabOperation[tailleOperation] = new Soustraction(tabOperation[tailleOperation - 1], tabOperation[tailleOperation - 2]);
                    notationNormale = modifieChaine(notationNormale, 2);
                    tailleOperation += 1;
                    break;
                case '*':
                    tabOperation[tailleOperation] = new Multiplication(tabOperation[tailleOperation - 1], tabOperation[tailleOperation - 2]);
                    notationNormale = modifieChaine(notationNormale, 3);
                    tailleOperation += 1;
                    break;
                case '/':
                    tabOperation[tailleOperation] = new Division(tabOperation[tailleOperation - 1], tabOperation[tailleOperation - 2]);
                    notationNormale = modifieChaine(notationNormale, 4);
                    tailleOperation += 1;
                    break;
            }
            i++;
            //si le premier est une variable
        } else if (regex_match(tab[i], regex{"^[xy]$"}) == 1) {
            tabConstante[tailleConstante] = new Constante(tab[i].c_str()[0], x, y);
            tailleConstante += 1;
            //si le deuxieme est un chiffre
            if (regex_match(tab[i + 1], regex{"[+-]?([0-9]*[.])?[0-9]+"}) == 1) {
                tabConstante[tailleConstante] = new Constante(stof(tab[i + 1]), x, y);
                tailleConstante += 1;
                //si le troisieme est un signe
                if (regex_match(tab[i + 2], regex{"^[/+*-]$"}) == 1) {
                    switch (tab[i + 2].c_str()[0]) {
                        case '+':
                            tabOperation[tailleOperation] = new Addition(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '+' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '-':
                            tabOperation[tailleOperation] = new Soustraction(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '-' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '*':
                            tabOperation[tailleOperation] = new Multiplication(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '*' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '/':
                            tabOperation[tailleOperation] = new Division(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '/' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                    }
                    i += 3;
                    //sinon le troisieme est une erreur
                } else {
                    cout << "ERREUR : veuillez saisir une expression valide";
                                  //Menu = 1;
                    return 0;
                }
                //si le deuxieme est un signe
            } else if (regex_match(tab[i + 1], regex{"^[/+*-]$"}) == 1) {

                switch (tab[i + 1].c_str()[0]) {
                    case '+':
                        tabOperation[tailleOperation] = new Addition(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        notationNormale += '+' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                        notationNormale =modifieChaine(notationNormale);
                        tailleOperation += 1;
                        break;
                    case '-':
                        tabOperation[tailleOperation] = new Soustraction(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        notationNormale += '-' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                        notationNormale =modifieChaine(notationNormale);
                        tailleOperation += 1;
                        break;
                    case '*':
                        tabOperation[tailleOperation] = new Multiplication(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        notationNormale += '*' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                        notationNormale =modifieChaine(notationNormale);
                        tailleOperation += 1;
                        break;
                    case '/':
                        tabOperation[tailleOperation] = new Division(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        notationNormale += '/' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                        notationNormale =modifieChaine(notationNormale);
                        tailleOperation += 1;
                        break;
                }
                i += 2;
                //si le deuxieme est une variable
            } else if (regex_match(tab[i + 1], regex{"^[xy]$"}) == 1) {
                tabConstante[tailleConstante] = new Constante(tab[i + 1].c_str()[0], x, y);
                tailleConstante += 1;
                //si le troisieme est un signe
                if (regex_match(tab[i + 2], regex{"^[/+*-]$"}) == 1) {
                    switch (tab[i + 2].c_str()[0]) {
                        case '+':
                            tabOperation[tailleOperation] = new Addition(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '+' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '-':
                            tabOperation[tailleOperation] = new Soustraction(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '-' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '*':
                            tabOperation[tailleOperation] = new Multiplication(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '*' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                        case '/':
                            tabOperation[tailleOperation] = new Division(tabConstante[tailleConstante - 2], tabConstante[tailleConstante - 1]);
                            notationNormale += '(' + to_string(tabConstante[tailleConstante - 2]->calculer()) + '/' + to_string(tabConstante[tailleConstante - 1]->calculer()) + ')';
                            tailleOperation += 1;
                            break;
                    }
                    i += 3;
                    //sinon le troiseme est une erreur
                } else {
                    cout << "ERREUR : veuillez saisir une expression valide";
                    //Menu = 1;
                    return 0;
                }
                //sinon le deuxieme est une erreur
            } else {
                cout << "ERREUR : veuillez saisir une expression valide";
                              //Menu = 1;
                    return 0;
            }
            // sinon le premier est une erreur
        } else {
            cout << "ERREUR : veuillez saisir une expression valide";
                          //Menu = 1;
                    return 0;
        }
    }
   string AfficheNPI;
    i=0;
    while (i < tailleTab) {
        AfficheNPI += tab[i];
        AfficheNPI += " ";
         i+=1;
    }
    cout << endl << "Notation classique : " << notationNormale << endl;
    cout <<"Notation polonaise inversée : " << AfficheNPI << endl;
    cout << "Valeur de l’expression : ";
    tabOperation[tailleOperation - 1]->afficher();
    return 0;

}


string modifieChaine(string notationNormale, int leSigne) {
    int j = 0;
    while ((notationNormale[j] != ')') || (notationNormale[j + 1] != '(')) {
        j++;
    }
    notationNormale += ')';
    for (int k = notationNormale.size(); k > j; k--) {
        notationNormale[k] = notationNormale[k - 1];
    }
    switch (leSigne) {
        case (1):
            notationNormale[j + 1] = '+';
            break;
        case (2):
            notationNormale[j + 1] = '-';
            break;
        case (3):
            notationNormale[j + 1] = '*';
            break;
        case (4):
            notationNormale[j + 1] = '/';
            break;
    }
    notationNormale += ')';
    for (int k = notationNormale.size(); k > 0; k--) {
        notationNormale[k] = notationNormale[k - 1];
    }
    notationNormale += ')';
    notationNormale[0] = '(';

    return notationNormale;
}

string modifieChaine(string notationNormale) {
    int j = notationNormale.size();
    while (notationNormale[j] != '(') {
        j--;
    }
    notationNormale += ')';
    for (int k = notationNormale.size(); k > j; k--) {
        notationNormale[k] = notationNormale[k - 1];
    }
    notationNormale += ')';
    notationNormale[j] = '(';
    return notationNormale;
}
                    
