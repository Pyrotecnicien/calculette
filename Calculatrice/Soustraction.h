/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Soustraction.h
 * Author: Nicolas
 *
 * Created on 4 mai 2018, 14:26
 */

#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "Operation.h"

class Soustraction : public Operation 
{
    protected:
    Expression* _operandeG;
    Expression* _operandeD;
public:
    Soustraction(Expression* e1, Expression* e2);
    Soustraction(const Soustraction& orig);
    virtual ~Soustraction();
float calculer();
void afficher();
void afficher_npi();

private:

};

#endif /* SOUSTRACTION_H */

