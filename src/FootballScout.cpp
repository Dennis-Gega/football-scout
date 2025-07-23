#include "FootballScout.h"
#include "CsvParser.h"
#include "FeatureEngineer.h"
#include "PlayerInput.h"
#include "ReportGenerator.h"
#include "ScoringEngine.h"

#include <iostream>

void FootballScout::StartSession() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "         FOOTBALL SCOUT ANALYSIS SYSTEM" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Player valuation system based on performance metrics\n" << std::endl;

    std::vector<Player> players = processDataset();

    int selection = 0;
    while (selection != 3) {
        displayMainMenu();

        std::cout << "Enter your choice: ";
        std::cin >> selection;

        if (std::cin.fail() || selection < 1 || selection > 3) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\nInvalid input. Please enter 1, 2, or 3.\n" << std::endl;
            continue;
        }

        std::cout << std::endl;

        switch (selection) {
            case 1:
                std::cout << "Generating undervalued players report...\n" << std::endl;
                ReportGenerator::generateReport(players, 10);
                pressEnterToContinue();
                break;
            case 2:
                std::cout << "Starting player analysis...\n" << std::endl;
                processPlayer();
                pressEnterToContinue();
                break;
            case 3:
                std::cout << "Exiting Football Scout." << std::endl;
                break;
        }
    }
}

std::vector<Player> FootballScout::processDataset() {
    std::cout << "Loading player database..." << std::flush;
    std::string filepath = "../data/football_player_data.csv";
    std::vector<Player> players = loadPlayersFromCsv(filepath);
    std::cout << " Complete (" << players.size() << " players loaded)" << std::endl;

    std::cout << "Processing performance analytics..." << std::flush;
    FeatureEngineer::normalizeNumericalFeatures(players);
    ScoringEngine::calculateAllPercentiles(players);
    ScoringEngine::calculateAllPerformanceScores(players);
    ScoringEngine::calculateAllUndervaluationScores(players);
    std::cout << " Complete\n" << std::endl;

    return players;
}

void FootballScout::processPlayer() {
    std::cout << "Custom Player Analysis\n" << std::endl;
    Player player = PlayerInput::generatePlayerFromInput();
    std::cout << "\n" << std::string(50, '-') << std::endl;
    std::cout << "PLAYER ANALYSIS REPORT" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    ReportGenerator::printSinglePlayerReport(player);
}

void FootballScout::displayMainMenu() {
    std::cout << std::string(35, '-') << std::endl;
    std::cout << "MAIN MENU" << std::endl;
    std::cout << std::string(35, '-') << std::endl;
    std::cout << "1. View Most Undervalued Players" << std::endl;
    std::cout << "2. Analyze Custom Player" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << std::string(35, '-') << std::endl;
}

void FootballScout::pressEnterToContinue() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
    std::cout << std::endl;
}
