#include "Player.h"
#include "CsvParser.h"
#include "FeatureEngineer.h"
#include "ReportGenerator.h"
#include "ScoringEngine.h"
#include <iostream>

int main()
{
    std::cout << "main" << std::endl;
    std::string filepath = "../data/football_player_data.csv";
    std::vector<Player> players = loadPlayersFromCsv(filepath);
    FeatureEngineer::normalizeNumericalFeatures(players);
    ScoringEngine::calculateAllPercentiles(players);
    ScoringEngine::calculateAllPerformanceScores(players);
    ScoringEngine::calculateAllUndervaluationScores(players);
    
    ReportGenerator::printSinglePlayerReport(players[4]);
    return 0;
}
