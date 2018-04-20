/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Expression.h
 * Author: joris.lacroix
 *
 * Created on 20 avril 2018, 14:47
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    Expression();
    Expression(const Expression& orig);
    virtual void calculer()=0;
    virtual void afficher()=0;
    virtual void afficher_npi()=0;
    
    virtual ~Expression();
private:

};

#endif /* EXPRESSION_H */

