/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soustraction.cpp
 * Author: Nicolas
 * 
 * Created on 4 mai 2018, 14:26
 */

#include "Soustraction.h"
#include <iostream>
using namespace std;

Soustraction::Soustraction(Expression* e1, Expression* e2) {
    _operandeG = e1;
    _operandeD = e2; 
}

Soustraction::Soustraction(const Soustraction& orig) {
}

Soustraction::~Soustraction() {
}

void Soustraction::afficher(){
    cout << calculer() << endl;
}

float Soustraction::calculer() {
    return _operandeG->calculer() + _operandeD->calculer();
}

void Soustraction::afficher_npi(){}

