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

#include "Multiplication.h"
#include <iostream>
using namespace std;


Multiplication::Multiplication(Expression* e1, Expression* e2) {
    _operandeG = e1;
    _operandeD = e2; 
}

Multiplication::Multiplication(const Multiplication& orig) {
}

Multiplication::~Multiplication() {
}

float Multiplication::calculer() {
    return _operandeG->calculer() * _operandeD->calculer();
}

void Multiplication::afficher(){
    cout << calculer() << endl;
}
void Multiplication::afficher_npi(){
    //cout << 
}

