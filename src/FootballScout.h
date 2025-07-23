#ifndef FOOTBALL_SCOUT_H
#define FOOTBALL_SCOUT_H

#include "Player.h"

#include <vector>

class FootballScout {
public:
    static void StartSession();
private:
    static void processPlayer();
    static std::vector<Player> processDataset();
    static void pressEnterToContinue();
    static void displayMainMenu();
};

#endif // FOOTBALL_SCOUT_H