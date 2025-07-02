#include "Player.h"
#include "CsvParser.h"
#include <iostream>

int main()
{
    std::cout << "main" << std::endl;
    std::string filepath = "../data/football_player_data.csv";
    std::vector<Player> players = loadPlayersFromCsv(filepath);
    
    for (const Player& player: players)
        player.print_info();
    return 0;
}
