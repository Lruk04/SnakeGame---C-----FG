#include "ScoreSystem.h"

ScoreSystem::ScoreSystem()
{
    m_Scores = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

ScoreSystem::~ScoreSystem()
{
    m_Scores.clear();
    
}

void ScoreSystem::AddScore(int score, int& multiplier, int PlayerID)
{
    m_Scores[PlayerID] += score * multiplier;
}

int ScoreSystem::GetScore() const
{
    return 0;
}

void ScoreSystem::ResetScore()
{
}

