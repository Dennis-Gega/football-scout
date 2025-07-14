#include "Player.h"
#include "CsvParser.h"
#include "FeatureEngineer.h"
#include <iostream>

int main()
{
    std::cout << "main" << std::endl;
    std::string filepath = "../data/football_player_data.csv";
    std::vector<Player> players = loadPlayersFromCsv(filepath);
    FeatureEngineer::normalizeNumericalFeatures(players);
    FeatureEngineer::calculateIndividualPercentiles(players);
    FeatureEngineer::calculatePerformanceScore(players);
    FeatureEngineer::calculateUndervaluationScore(players);
    FeatureEngineer::generateReport(players, 10); //

    return 0;
}
