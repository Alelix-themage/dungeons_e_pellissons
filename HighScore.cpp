#include "HighScore.h"
#include <fstream>
#include <string>
#include<iostream>

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

void HighScore(std::string player, int score){
    //Função responsável por registrar a pontuação do jogador
    std::ofstream registro_game("HighScore.txt", std::ios::out | std::ios::app);
    
    registro_game << "----------------------------------------------------------" << std::endl;
    registro_game << "Player: " << player << std::endl;
    registro_game << "Score: " << score << std::endl;
    registro_game << "----------------------------------------------------------" << std::endl;
    
    registro_game.close();
}

#endif
