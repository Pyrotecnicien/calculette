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
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"


/*
 * 
 */
int main(int argc, char** argv) {



    float x = 5;
    float y = 9;
    //l'interface pour cahnger la valeur des variables
    cout << "Les variables acceptés sont x et y, leurs valeurs de base sont 5 et 9, souhaitez vous les changer ? (y/n), double entrée pour valider" << endl;
    string c;
    while (c != "y" && c != "n" && c != "Y" && c != "N") {
        cin >> c;
        if (c != "y" && c != "n" && c != "Y" && c != "N") {
            cout << c << endl;
            cout << "veuillez entrer une lettre valide (y ou n), double entrée pour valider" << endl;
        } else
            cout << c << endl;
    }
    if (c == "y" || c == "Y") {
        string variable;
        cout << "affectez une nouvelle valeur à x, double entrée pour valider :" << endl;
        cin >> variable;
        cout << variable << endl;
        if (regex_match(variable, regex{"[+-]?([0-9]*[.])?[0-9]+"}) == 1) {
            x = stof(variable);
        } else {
            cout << "erreur, la valeur entrée est incorecte, x vaut toujours 5" << endl;
        }
        cout << "affectez une nouvelle valeur à y, double entrée pour valider :" << endl;
        cin >> variable;
        cout << variable << endl;
        if (regex_match(variable, regex{"[+-]?([0-9]*[.])?[0-9]+"}) == 1) {
            y = stof(variable);
        } else {
            cout << "erreur, la valeur entrée est incorecte, y vaut toujours 8" << endl;
        }
    }
    
    //l'interface pour faire écrire à l'itulisateur son appération
    string* tab;
    int VALEUR_MAX_TABLEAU = 20;
    tab = new string[VALEUR_MAX_TABLEAU];
    int tailleTab = 0;
    cout << "entrez votre oppération, appuyez sur entrée après chaque saisie, appuyez sur la touche q suivie de deux fois la touche entrée pour terminer la saisie" << endl;
    cout << "rappel, les variables acceptées sont x et y" << endl;
    while (c != "q" && c != "Q") {
        cin >> c;
        if (c != "q" && c != "Q") {
            tab[tailleTab] = c;
            cout << c << endl;
            tailleTab++;
        }
    }

    Constante * tabConstante[VALEUR_MAX_TABLEAU];
    Operation * tabOperation[VALEUR_MAX_TABLEAU];

    int tailleConstante = 0;
    int tailleOperation = 0;
    
    int i = 0;
    //traitement de l'oppération avec vérification d'erreur
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
                            tailleOperation += 1;
                            break;
                        case '-':
                            break;
                        case '*':
                            break;
                        case '/':
                            break;
                    }
                    i += 3;
                    //sinon le troisieme est une erreur
                } else {
                    cout << "ERREUR : veuillez saisir une expression valide";
                    return 0;
                }
                //si le deuxieme est un signe
            } else if (regex_match(tab[i + 1], regex{"^[/+*-]$"}) == 1) {

                switch (tab[i + 1].c_str()[0]) {
                    case '+':
                        tabOperation[tailleOperation] = new Addition(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        tailleOperation += 1;
                        break;
                    case '-':
                        break;
                    case '*':
                        break;
                    case '/':
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
                            tailleOperation += 1;
                            break;
                        case '-':
                            break;
                        case '*':
                            break;
                        case '/':
                            break;
                    }
                    i += 3;
                    //sinon le troiseme est une erreur
                } else {
                    cout << "ERREUR : veuillez saisir une expression valide";
                    return 0;
                }
                //sinon le deuxieme est une erreur
            } else {
                cout << "ERREUR : veuillez saisir une expression valide";
                return 0;
            }
            //si le premier est un signe
        } else if (regex_match(tab[i], regex{"^[/+*-]$"}) == 1) {
            switch (tab[i].c_str()[0]) {
                case '+':
                    tabOperation[tailleOperation] = new Addition(tabOperation[tailleOperation - 1], tabOperation[tailleOperation - 2]);
                    tailleOperation += 1;
                    break;
                case '-':
                    break;
                case '*':
                    break;
                case '/':
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
                            tailleOperation += 1;
                            break;
                        case '-':
                            break;
                        case '*':
                            break;
                        case '/':
                            break;
                    }
                    i += 3;
                    //sinon le troisieme est une erreur
                } else {
                    cout << "ERREUR : veuillez saisir une expression valide";
                    return 0;
                }
                //si le deuxieme est un signe
            } else if (regex_match(tab[i + 1], regex{"^[/+*-]$"}) == 1) {

                switch (tab[i + 1].c_str()[0]) {
                    case '+':
                        tabOperation[tailleOperation] = new Addition(tabOperation[tailleOperation - 1], tabConstante[tailleConstante - 1]);
                        tailleOperation += 1;
                        break;
                    case '-':
                        break;
                    case '*':
                        break;
                    case '/':
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
                            tailleOperation += 1;
                            break;
                        case '-':
                            break;
                        case '*':
                            break;
                        case '/':
                            break;
                    }
                    i += 3;
                    //sinon le troiseme est une erreur
                } else {
                    cout << "ERREUR : veuillez saisir une expression valide";
                    return 0;
                }
                //sinon le deuxieme est une erreur
            } else {
                cout << "ERREUR : veuillez saisir une expression valide";
                return 0;
            }
            // sinon le premier est une erreur
        } else {
            cout << "ERREUR : veuillez saisir une expression valide";
            return 0;
        }
    }
    cout << "résultat :";
    tabOperation[tailleOperation - 1]->afficher();
    return 0;
}

