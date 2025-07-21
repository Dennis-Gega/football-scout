//
// Created by dennis gega on 7/10/25.
//

#include "PlayerAnalyzer.h"
#include "FeatureEngineer.h"
#include <algorithm>

void PlayerAnalyzer::calculateIndividualPercentiles(std::vector<Player>& players) {
    // Get references to the sorted vectors from FeatureEngineer
    const auto& all_ages = FeatureEngineer::getAllAges();
    const auto& all_goals = FeatureEngineer::getAllGoals();
    const auto& all_assists = FeatureEngineer::getAllAssists();
    const auto& all_goals_per_90 = FeatureEngineer::getAllGoalsPer90();
    const auto& all_assists_per_90 = FeatureEngineer::getAllAssistsPer90();
    const auto& all_contributions_per_90 = FeatureEngineer::getAllContributionsPer90();
    const auto& all_values = FeatureEngineer::getAllValues();

    for (Player& player : players) {
        player.setPercentileRankAge(calculatePercentileRank(all_ages, player.getAge()));
        player.setPercentileRankGoals(calculatePercentileRank(all_goals, player.getGoals()));
        player.setPercentileRankAssists(calculatePercentileRank(all_assists, player.getAssists()));
        player.setPercentileRankGoalsPer90(calculatePercentileRank(all_goals_per_90, player.getGoalsPer90()));
        player.setPercentileRankAssistsPer90(calculatePercentileRank(all_assists_per_90, player.getAssistsPer90()));
        player.setPercentileRankGoalsContributionsPer90(calculatePercentileRank(all_contributions_per_90, player.getGoalsPer90() + player.getAssistsPer90()));
        player.setPercentileRankValue(calculatePercentileRank(all_values, player.getValue()));
    }
}

std::map<std::string, double> PlayerAnalyzer::getPositionWeights(Position position) {
    switch (position) {
        case FORWARD:
            return {
                {"age", 0.20},
                {"goals", 0.20},
                {"assists", 0.05},
                {"goals_per_90", 0.20},
                {"assists_per_90", 0.05},
                {"contributions_per_90", 0.30}
            };
        case MIDFIELDER:
            return {
                {"age", 0.20},
                {"goals", 0.10},
                {"assists", 0.15},
                {"goals_per_90", 0.10},
                {"assists_per_90", 0.15},
                {"contributions_per_90", 0.30}
            };
        case DEFENDER:
            return {
                {"age", 0.30},
                {"goals", 0.05},
                {"assists", 0.10},
                {"goals_per_90", 0.05},
                {"assists_per_90", 0.20},
                {"contributions_per_90", 0.30}
            };
        default:
            // Default to forward weights for unknown positions
            return {
                {"age", 0.20},
                {"goals", 0.20},
                {"assists", 0.05},
                {"goals_per_90", 0.20},
                {"assists_per_90", 0.05},
                {"contributions_per_90", 0.30}
            };
    }
}

void PlayerAnalyzer::calculatePerformanceScore(std::vector<Player>& players) {
    for (Player& player : players) {
        const auto weights = getPositionWeights(player.getPosition());

        double score =
            weights.at("age") * player.getPercentileRankAge() +
            weights.at("goals") * player.getPercentileRankGoals() +
            weights.at("assists") * player.getPercentileRankAssists() +
            weights.at("goals_per_90") * player.getPercentileRankGoalsPer90() +
            weights.at("assists_per_90") * player.getPercentileRankAssistsPer90() +
            weights.at("contributions_per_90") * player.getPercentileRankGoalsContributionsPer90();

        player.setPerformanceScore(score);
    }
}

void PlayerAnalyzer::calculateUndervaluationScore(std::vector<Player>& players) {
    for (Player& player : players) {
        player.setUndervaluationScore(player.getPerformanceScore() - player.getPercentileRankValue());
    }
}