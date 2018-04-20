/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Addition.cpp
 * Author: joris.lacroix
 * 
 * Created on 20 avril 2018, 14:32
 */

#include "Addition.h"

Addition::Addition(Expression e1, Expression e2) {
    _operandeG = e1; _operandeD = e2; 
}

Addition::Addition(const Addition& orig) {
}

Addition::~Addition() {
}

void Operation::calculer(){}
void Operation::afficher(){}
void Operation::afficher_npi(){}

