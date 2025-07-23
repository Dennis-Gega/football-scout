#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Player.h"
#include <vector>

class ReportGenerator {
public:
    static void printSinglePlayerReport(Player& player);
    static void generateReport(const std::vector<Player>& players, int num_top_players);

private:
    static void printPositionHeader(Position pos);
    static void printPlayerSummary(const Player& player, int rank);
    static std::string getPositionName(Position pos);
};

#endif // REPORTGENERATOR_H
