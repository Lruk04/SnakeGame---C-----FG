#pragma once
#include <vector>

class ScoreSystem
{
private:
    std::vector<int> m_Scores;
    int m_multiplier;

    

    
public:
    ScoreSystem();
    ~ScoreSystem();
    
    void AddScore(int score, int& multiplier, int PlayerID);
    int GetScore() const;
    void ResetScore();
};
