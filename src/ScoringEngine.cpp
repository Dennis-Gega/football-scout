#include "ScoringEngine.h"
#include "FeatureEngineer.h"

#include <map>

template<typename T>
double ScoringEngine::calculatePercentileRank(std::vector<T> &values, T value) {
    return std::distance(values.begin(), std::lower_bound(values.begin(), values.end(), value)) / static_cast<double>(values.size());
}

void ScoringEngine::calculateAllPercentiles(std::vector<Player> &players) {
    for (Player &player : players) {
        player.setPercentileRankAge(calculatePercentileRank(FeatureEngineer::getAllAges(), player.getAge()));
        player.setPercentileRankGoals(calculatePercentileRank(FeatureEngineer::getAllGoals(), player.getGoals()));
        player.setPercentileRankAssists(calculatePercentileRank(FeatureEngineer::getAllAssists(), player.getAssists()));
        player.setPercentileRankGoalsPer90(calculatePercentileRank(FeatureEngineer::getAllGoalsPer90(), player.getGoalsPer90()));
        player.setPercentileRankAssistsPer90(calculatePercentileRank(FeatureEngineer::getAllAssistsPer90(), player.getAssistsPer90()));
        player.setPercentileRankGoalsContributionsPer90(calculatePercentileRank(FeatureEngineer::getAllContributionsPer90(), player.getGoalsPer90() + player.getAssistsPer90()));
        player.setPercentileRankValue(calculatePercentileRank(FeatureEngineer::getAllValues(), player.getValue()));
    }
}

void ScoringEngine::calculateAllPerformanceScores(std::vector<Player> &players) {

    // Initialize weights for each position
    std::map<std::string, double> fw_weights {
        {"age", 0.20},
        {"goals", 0.20},
        {"assists", 0.05},
        {"goals_per_90", 0.20},
        {"assists_per_90", 0.05},
        {"contributions_per_90", 0.30}
    };

    std::map<std::string, double> mf_weights{
        {"age", 0.20},
        {"goals", 0.10},
        {"assists", 0.15},
        {"goals_per_90", 0.10},
        {"assists_per_90", 0.15},
        {"contributions_per_90", 0.30}
    };

    std::map<std::string, double> df_weights{
        {"age", 0.30},
        {"goals", 0.05},
        {"assists", 0.10},
        {"goals_per_90", 0.05},
        {"assists_per_90", 0.20},
        {"contributions_per_90", 0.30}
    };

    for (Player &player: players) {
        const std::map<std::string, double> *weights;
        switch (player.getPosition()) {
            case FORWARD:
                weights = &fw_weights;
                break;
            case MIDFIELDER:
                weights = &mf_weights;
                break;
            case DEFENDER:
                weights = &df_weights;
                break;
            default:
                weights = &fw_weights;
        }


        double score =
                weights->at("age") * player.getPercentileRankAge() +
                weights->at("goals") * player.getPercentileRankGoals() +
                weights->at("assists") * player.getPercentileRankAssists() +
                weights->at("goals_per_90") * player.getPercentileRankGoalsPer90() +
                weights->at("assists_per_90") * player.getPercentileRankAssistsPer90() +
                weights->at("contributions_per_90") * player.getPercentileRankGoalsContributionsPer90();


        player.setPerformanceScore(score);
    }
}

void ScoringEngine::calculateAllUndervaluationScores(std::vector<Player> &players) {
    for (Player &player: players) {
        player.setUndervaluationScore(player.getPerformanceScore() - player.getPercentileRankValue());
    }
}