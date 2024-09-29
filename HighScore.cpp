// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "HighScore.h"
#include <fstream>
#include <string>
#include<iostream>

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

void HighScore(std::string player, int nivel, int quantniveis, int progressplayer, int progresspornivel){
    //Função responsável por registrar a pontuação do jogador
    std::ofstream registro_game("HighScore.txt", std::ios::out | std::ios::app);
    
    registro_game << "----------------------------------------------------------" << std::endl;
    registro_game << "Player: " << player << std::endl;
    registro_game << "Nivel Recorde: " << nivel << "/" << quantniveis << " - Progresso " << progressplayer << "/" << progresspornivel << std::endl;
    registro_game << "----------------------------------------------------------" << std::endl;
    
    registro_game.close();
}

#endif
