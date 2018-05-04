/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Division.cpp
 * Author: Nicolas
 * 
 * Created on 4 mai 2018, 14:26
 */

#include "Division.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Multiplication.cpp
 * Author: Nicolas
 * 
 * Created on 4 mai 2018, 14:26
 */

#include "Division.h"
#include <iostream>
using namespace std;


Division::Division(Expression* e1, Expression* e2) {
    _operandeG = e1;
    _operandeD = e2; 
}

Division::Division(const Division& orig) {
}

Division::~Division() {
}

float Division::calculer() {
    return _operandeG->calculer() / _operandeD->calculer();
}

void Division::afficher(){
    cout << calculer() << endl;
}
void Division::afficher_npi(){
    //cout << 
}

