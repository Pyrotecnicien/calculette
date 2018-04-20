/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Constante.h
 * Author: joris.lacroix
 *
 * Created on 20 avril 2018, 15:04
 */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"
#include <iostream>
using namespace std;

class Constante : public Expression {
    protected:
        float _constante;
public:
    Constante( float c);
    Constante(const Constante& orig);
    virtual ~Constante();
    float calculer(){return _constante;}
    void afficher(){cout << _constante<<endl;}
    void afficher_npi(){cout << _constante<<endl;}
private:

};

#endif /* CONSTANTE_H */

