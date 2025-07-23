#include "PlayerInput.h"
#include "Player.h"
#include "ScoringEngine.h"
#include <iostream>
#include <string>
#include <limits>

Player PlayerInput::generatePlayerFromInput() {
    std::cout << "Please provide player information:\n" << std::endl;
    
    std::string name = getPlayerName();
    Position position = getPlayerPosition();
    int age = getPlayerAge();
    long long value = getPlayerValue();
    
    std::cout << "\nPerformance Statistics:" << std::endl;
    int goals = getPlayerGoals();
    int assists = getPlayerAssists();
    double goals_per_90 = getGoalsPer90();
    double assists_per_90 = getAssistsPer90();
    
    std::cout << "\nProcessing player data..." << std::flush;
    
    int player_id = 9999;
    Player player(player_id, value, age, goals, assists, goals_per_90, assists_per_90, name, position);
    ScoringEngine::evaluateSinglePlayer(player);
    
    std::cout << " Complete" << std::endl;
    return player;
}

std::string PlayerInput::getPlayerName() {
    std::string name;
    std::cout << "Player Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    while (name.empty()) {
        std::cout << "Name cannot be empty. Player Name: ";
        std::getline(std::cin, name);
    }
    
    return name;
}

Position PlayerInput::getPlayerPosition() {
    std::cout << "\nPosition Options:" << std::endl;
    std::cout << "1. Defender" << std::endl;
    std::cout << "2. Midfielder" << std::endl;
    std::cout << "3. Forward" << std::endl;
    
    int choice;
    while (true) {
        std::cout << "Select position (1-3): ";
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. ";
            continue;
        }
        
        switch (choice) {
            case 1: return Position::DEFENDER;
            case 2: return Position::MIDFIELDER;
            case 3: return Position::FORWARD;
            default:
                std::cout << "Invalid selection. ";
        }
    }
}

int PlayerInput::getPlayerAge() {
    int age;
    std::cout << "\nPlayer Age (16-45): ";
    
    while (true) {
        std::cin >> age;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter age: ";
            continue;
        }
        
        if (age < 16 || age > 45) {
            std::cout << "Age must be between 16-45. Enter age: ";
            continue;
        }
        
        return age;
    }
}

long long PlayerInput::getPlayerValue() {
    double value_millions;
    std::cout << "Market Value (millions EUR): ";
    std::cout << "\nExamples: 50.0 for 50M EUR, 1.5 for 1.5M EUR" << std::endl;
    std::cout << "Enter value: ";
    
    while (true) {
        std::cin >> value_millions;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter value: ";
            continue;
        }
        
        if (value_millions < 0 || value_millions > 500) {
            std::cout << "Value must be between 0-500 million. Enter value: ";
            continue;
        }
        
        return static_cast<long long>(value_millions);
    }
}

int PlayerInput::getPlayerGoals() {
    int goals;
    std::cout << "Goals scored this season: ";
    
    while (true) {
        std::cin >> goals;
        
        if (std::cin.fail() || goals < 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter goals: ";
            continue;
        }
        
        return goals;
    }
}

int PlayerInput::getPlayerAssists() {
    int assists;
    std::cout << "Assists this season: ";
    
    while (true) {
        std::cin >> assists;
        
        if (std::cin.fail() || assists < 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter assists: ";
            continue;
        }
        
        return assists;
    }
}

double PlayerInput::getGoalsPer90() {
    double goals_per_90;
    std::cout << "Goals per 90 minutes: ";
    
    while (true) {
        std::cin >> goals_per_90;
        
        if (std::cin.fail() || goals_per_90 < 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter goals per 90: ";
            continue;
        }
        
        return goals_per_90;
    }
}

double PlayerInput::getAssistsPer90() {
    double assists_per_90;
    std::cout << "Assists per 90 minutes: ";
    
    while (true) {
        std::cin >> assists_per_90;
        
        if (std::cin.fail() || assists_per_90 < 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter assists per 90: ";
            continue;
        }
        
        return assists_per_90;
    }
}
