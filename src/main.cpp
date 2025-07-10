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
    
    for (int i = 0; i < 5; i++)
        players[i].print_info();
    return 0;
}
