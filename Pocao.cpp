#include "Pocao.h"
#include <iostream>
using namespace std;


#ifndef POCAO_H
#define POCAO_H
void Pocao::CuraHeroi(int &vida){
    vida = vida + cura;
    cout << "O heroi ganhou +" << vida << endl;

}



#endif