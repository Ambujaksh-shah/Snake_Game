#include"score.h"

bool PrintScore::checkScore(int score) 
{
    myfile.open(path,std::ios::in);

    if(! myfile) 
    {
        myfile.close();
        std::ofstream outfile(static_cast<std::string>(path));  
        outfile<<score;
        outfile.close(); 
        return false;
    }
    else
    {
        while (getline(myfile, line))
        {
            if(std::stoi(line)<score )
                return true;
        }
    }

    return false;

}

void PrintScore::getScore(int score)
{
    if(checkScore(score) )
    {
        std::cout<<"New High Score : "<<score<<std::endl;
        UpdateScore(score);
    }
    else
        std::cout<<"Your Score : "<<score<<std::endl;
    
}

void PrintScore::UpdateScore(int score)
{
    std::ofstream outfile(static_cast<std::string>(path));  
    outfile<<score;
    outfile.close(); 

}