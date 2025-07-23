#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "Player.h"

class PlayerInput {
public:
    static Player generatePlayerFromInput();
private:
    static std::string getPlayerName();
    static Position getPlayerPosition();
    static int getPlayerAge();
    static long long getPlayerValue();
    static int getPlayerGoals();
    static int getPlayerAssists();
    static double getGoalsPer90();
    static double getAssistsPer90();
    
};

#endif // PLAYERINPUT_H