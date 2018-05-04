/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Multiplication.h
 * Author: Nicolas
 *
 * Created on 4 mai 2018, 14:26
 */

#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H
#include "Operation.h"

class Multiplication : public Operation
{
protected:
    Expression* _operandeG;
    Expression* _operandeD;
public:
    Multiplication(Expression* e1, Expression* e2);
    Multiplication(const Multiplication& orig);
    virtual ~Multiplication();
    
    float calculer();
    void afficher();
    void afficher_npi();
private:

};

#endif /* MULTIPLICATION_H */

