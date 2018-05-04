/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Constante.cpp
 * Author: joris.lacroix
 * 
 * Created on 20 avril 2018, 15:04
 */

#include "Constante.h"
#include <iostream>
using namespace std;

Constante::Constante(float c, float x, float y) {
    _constante = c;
}
Constante::Constante(char valeur, float x, float y) {
    switch (valeur){
        case 'x':
            _constante = x;
            break;
        case 'y':
            _constante = y;
            break;
    }
}

Constante::Constante(const Constante& orig) {
}

Constante::~Constante() {
}

