#include "ReportGenerator.h"
#include "Player.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

void ReportGenerator::printSinglePlayerReport(Player& player) {
    std::cout << "\nPlayer: " << player.getName() << std::endl;
    std::cout << std::string(30, '=') << std::endl;

    // Basic Information
    std::cout << "\nBasic Information:" << std::endl;
    std::cout << std::string(20, '-') << std::endl;
    std::cout << "Position: " << getPositionName(player.getPosition()) << std::endl;
    std::cout << "Age: " << player.getAge() << " years" << std::endl;
    std::cout << "Market Value: EUR " << std::fixed << std::setprecision(1)
              << player.getValue() << " million" << std::endl;

    // Performance Statistics
    std::cout << "\nPerformance Statistics:" << std::endl;
    std::cout << std::string(20, '-') << std::endl;
    std::cout << "Goals: " << player.getGoals() << std::endl;
    std::cout << "Assists: " << player.getAssists() << std::endl;
    std::cout << "Goals per 90min: " << std::fixed << std::setprecision(2)
              << player.getGoalsPer90() << std::endl;
    std::cout << "Assists per 90min: " << std::fixed << std::setprecision(2)
              << player.getAssistsPer90() << std::endl;

    // Market Analysis
    std::cout << "\nMarket Analysis:" << std::endl;
    std::cout << std::string(20, '-') << std::endl;

    double underval = player.getUndervaluationScore();
    std::cout << "Undervaluation Score: " << std::fixed << std::setprecision(3) << underval << std::endl;

    std::cout << "Assessment: ";
    if (underval > 0.2) {
        std::cout << "HIGHLY UNDERVALUED" << std::endl;
        std::cout << "Recommendation: Excellent investment opportunity" << std::endl;
    } else if (underval > 0.05) {
        std::cout << "UNDERVALUED" << std::endl;
        std::cout << "Recommendation: Good value for performance level" << std::endl;
    } else if (underval > -0.05) {
        std::cout << "FAIRLY VALUED" << std::endl;
        std::cout << "Recommendation: Market price reflects performance" << std::endl;
    } else if (underval > -0.2) {
        std::cout << "OVERVALUED" << std::endl;
        std::cout << "Recommendation: Price premium may not be justified" << std::endl;
    } else {
        std::cout << "HIGHLY OVERVALUED" << std::endl;
        std::cout << "Recommendation: Consider alternatives at this price point" << std::endl;
    }

    std::cout << std::string(30, '=') << std::endl;
}

std::string ReportGenerator::getPositionName(Position pos) {
    switch (pos) {
        case Position::DEFENDER: return "Defender";
        case Position::MIDFIELDER: return "Midfielder";
        case Position::FORWARD: return "Forward";
        default: return "Unknown";
    }
}

void ReportGenerator::generateReport(const std::vector<Player> &players, int num_top_players) {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "              UNDERVALUED PLAYERS REPORT" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "Analysis of top " << num_top_players << " undervalued players by position\n" << std::endl;

    std::vector<Player> forwards, midfielders, defenders;

    // Group players by position
    for (const Player &player: players) {
        switch (player.getPosition()) {
            case FORWARD:
                forwards.push_back(player);
                break;
            case MIDFIELDER:
                midfielders.push_back(player);
                break;
            case DEFENDER:
                defenders.push_back(player);
                break;
            default:
                break;
        }
    }

    // Sort each group by undervaluation score
    auto compareByUndervaluation = [](const Player &a, const Player &b) {
        return a.getUndervaluationScore() > b.getUndervaluationScore();
    };

    std::sort(forwards.begin(), forwards.end(), compareByUndervaluation);
    std::sort(midfielders.begin(), midfielders.end(), compareByUndervaluation);
    std::sort(defenders.begin(), defenders.end(), compareByUndervaluation);

    // Print top players for each position using consistent formatting
    printPositionHeader(FORWARD);
    for (int i = 0; i < std::min(num_top_players, static_cast<int>(forwards.size())); ++i) {
        printPlayerSummary(forwards[i], i + 1);
    }

    printPositionHeader(MIDFIELDER);
    for (int i = 0; i < std::min(num_top_players, static_cast<int>(midfielders.size())); ++i) {
        printPlayerSummary(midfielders[i], i + 1);
    }

    printPositionHeader(DEFENDER);
    for (int i = 0; i < std::min(num_top_players, static_cast<int>(defenders.size())); ++i) {
        printPlayerSummary(defenders[i], i + 1);
    }

    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "                    END OF REPORT" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

void ReportGenerator::printPlayerSummary(const Player& player, int rank) {
    std::cout << "\n" << rank << ". " << player.getName() << std::endl;
    std::cout << std::string(25, '-') << std::endl;

    // Key information in compact format
    std::cout << "Age: " << player.getAge() << " years  |  "
              << "Value: EUR " << std::fixed << std::setprecision(1) << player.getValue() << "M" << std::endl;

    std::cout << "Goals: " << player.getGoals() << "  |  "
              << "Assists: " << player.getAssists() << "  |  "
              << "G+A/90: " << std::fixed << std::setprecision(2)
              << (player.getGoalsPer90() + player.getAssistsPer90()) << std::endl;

    // Undervaluation score with assessment
    double underval = player.getUndervaluationScore();
    std::cout << "Undervaluation Score: " << std::fixed << std::setprecision(3) << underval;

    if (underval > 0.2) {
        std::cout << " (HIGHLY UNDERVALUED)" << std::endl;
    } else if (underval > 0.1) {
        std::cout << " (UNDERVALUED)" << std::endl;
    } else if (underval > 0.05) {
        std::cout << " (SLIGHTLY UNDERVALUED)" << std::endl;
    } else {
        std::cout << " (MODERATELY UNDERVALUED)" << std::endl;
    }
}

void ReportGenerator::printPositionHeader(Position pos) {
    std::string position_name;
    switch (pos) {
        case FORWARD: position_name = "FORWARDS"; break;
        case MIDFIELDER: position_name = "MIDFIELDERS"; break;
        case DEFENDER: position_name = "DEFENDERS"; break;
        default: position_name = "UNKNOWN"; break;
    }

    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TOP UNDERVALUED " << position_name << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}
