/*
 * To change this license header, choose License Headers in Project Properties.
 * To change thizaes template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicolas
 *
 * Created on 20 avril 2018, 10:56
 */
#include <iostream>
using namespace std;
#include <cstdlib>
#include "Constante.h"
#include "Addition.h"



/*
 * 
 */
int main(int argc, char** argv) {

    
    Constante c1(10);
    Constante c2(20);
    Addition add1(&c1,&c2);
    add1.afficher();
    
    
    return 0;
}

