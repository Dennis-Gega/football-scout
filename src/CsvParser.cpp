#include "CsvParser.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Position stringToPosition(std::string& position) {
    if (position == "DF")
        return Position::DEFENDER;
    else if (position == "MF")
        return Position::MIDFIELDER;
    else if (position == "FW")
        return Position::FORWARD;
    else
        return Position::UNKNOWN; // default value
}

std::vector<Player> loadPlayersFromCsv(std::string& filepath) {
    std::vector<Player> players;
    std::ifstream file { filepath };

    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filepath << std::endl;
        return players;
    }

    std::string line;
    std::getline(file, line); // skip header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string stat;
        std::vector<std::string> stats;

        while (std::getline(ss, stat, ',')) {
            stats.push_back(stat);
        }



        Player player {
            std::stoi(stats[0]),  // player_id
            std::stoi(stats[2]) * 1'000'000,  // market_value
            std::stoi(stats[7]),  // age
            std::stoi(stats[11]), // goals
            std::stoi(stats[12]), // assists
            std::stof(stats[17]), // goals_per_90
            std::stof(stats[18]), // assists_per_90
            stats[1],             // name
            stringToPosition(stats[4]),             // position
        };
        

        players.push_back(player);
    }

    file.close();
    return players;
}
