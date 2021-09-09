#ifndef SCORE_H
#define SCORE_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"game.h"


class PrintScore
{
private:
    std::ifstream myfile;
    std::string line,Id,Id_Val;
    const std::string path="BestScore.dat";
    bool checkScore(int score);


public:
    void getScore(int score);
    void UpdateScore(int score);
    
};

#endif