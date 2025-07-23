#include "ReportGenerator.h"
#include "Player.h"
#include <iostream>

void ReportGenerator::printSinglePlayerReport(Player& player) {

    std::cout << player.getName() << " Player Report:" << '\n';
    std::cout << "Age: " << player.getAge() << '\n';
    std::cout << "Position: " << player.getPosition() << '\n';
    std::cout << "Goals: " << player.getGoals() << '\n';
    std::cout << "Assists: " << player.getAssists() << '\n';
    std::cout << "Value: " << player.getValue() * 1'000'000 << "€" << '\n';
    std::cout << "Undervaluation Score: " << player.getUndervaluationScore() << '\n';
}
