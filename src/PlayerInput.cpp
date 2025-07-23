#include "PlayerInput.h"
#include "Player.h"
#include "ScoringEngine.h"

Player PlayerInput::generatePlayerFromInput() {
    Player player;
    int player_id;
    int value;
    int age;
    int goals;
    int assists;
    double goals_per_90;
    double assists_per_90;
    std::string name;
    Position position;
    
    std::cout << "Enter player ID: ";
    std::cin >> player_id;
    
    std::cout << "Enter player value: ";
    std::cin >> value;
    
    std::cout << "Enter player age: ";
    std::cin >> age;
    
    std::cout << "Enter player goals: ";
    std::cin >> goals;
    
    std::cout << "Enter player assists: ";
    std::cin >> assists;
    
    std::cout << "Enter player goals per 90: ";
    std::cin >> goals_per_90;
    
    std::cout << "Enter player assists per 90: ";
    std::cin >> assists_per_90;
    
    std::cout << "Enter player name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "Enter player position (GK, DF, MF, FW): ";
    std::string position_str;
    std::cin >> position_str;
    position = position_str == "DF" ? Position::DEFENDER : position_str == "MF" ? Position::MIDFIELDER : Position::FORWARD;
    
    player = Player(player_id, value, age, goals, assists, goals_per_90, assists_per_90, name, position);
    ScoringEngine::evaluateSinglePlayer(player);
    
    return player;
}