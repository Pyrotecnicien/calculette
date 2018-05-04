/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Division.h
 * Author: Nicolas
 *
 * Created on 4 mai 2018, 14:26
 */

#ifndef DIVISION_H
#define DIVISION_H
#include "Operation.h"

class Division : public Operation
{
protected:
    Expression* _operandeG;
    Expression* _operandeD;
public:
    Division(Expression* e1, Expression* e2);
    Division(const Division& orig);
    virtual ~Division();
    
    float calculer();
    void afficher();
    void afficher_npi();
private:

};

#endif /* DIVISION_H */

