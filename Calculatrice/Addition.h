/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Addition.h
 * Author: joris.lacroix
 *
 * Created on 20 avril 2018, 14:32
 */

#ifndef ADDITION_H
#define ADDITION_H

class Addition {
protected:
    Expression _operandeG;
    Expression _operandeD;
public:
    Addition();
    Addition(const Addition& orig);
    virtual ~Addition();
    
    void calculer();
    void afficher();
    void afficher_npi();
private:

};

#endif /* ADDITION_H */

