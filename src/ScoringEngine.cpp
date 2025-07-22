#include "ScoringEngine.h"
#include "FeatureEngineer.h"
#include "Player.h"

#include <map>

const std::map<std::string, double>& ScoringEngine::getForwardWeights() {
    static const std::map<std::string, double> fw_weights {
        {"age", 0.20},
        {"goals", 0.20},
        {"assists", 0.05},
        {"goals_per_90", 0.20},
        {"assists_per_90", 0.05},
        {"contributions_per_90", 0.30}
    };
    
    return fw_weights;
}

const std::map<std::string, double>& ScoringEngine::getMidfielderWeights() {
    static const std::map<std::string, double> mf_weights {
        {"age", 0.20},
        {"goals", 0.10},
        {"assists", 0.15},
        {"goals_per_90", 0.10},
        {"assists_per_90", 0.15},
        {"contributions_per_90", 0.30}
    };
    return mf_weights;
}

const std::map<std::string, double>& ScoringEngine::getDefenderWeights() {
    static const std::map<std::string, double> df_weights{
        {"age", 0.30},
        {"goals", 0.05},
        {"assists", 0.10},
        {"goals_per_90", 0.05},
        {"assists_per_90", 0.20},
        {"contributions_per_90", 0.30}
    };
    return df_weights;
}

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

/**
 * @brief Returns the weights for a given position.
 */
static const std::map<std::string, double>& getWeightsForPosition(Position position) {
    switch (position) {
            case Position::FORWARD:
                return ScoringEngine::getForwardWeights();
            case Position::MIDFIELDER:
                return ScoringEngine::getMidfielderWeights();
            case Position::DEFENDER:
                return ScoringEngine::getDefenderWeights();
            default:
                return ScoringEngine::getForwardWeights();
        }
}

void ScoringEngine::calculateAllPerformanceScores(std::vector<Player> &players) {
    for (Player &player: players) {
        const std::map<std::string, double>& weights = getWeightsForPosition(player.getPosition());

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

void ScoringEngine::calculateAllUndervaluationScores(std::vector<Player> &players) {
    for (Player &player: players) {
        player.setUndervaluationScore(player.getPerformanceScore() - player.getPercentileRankValue());
    }
}

void ScoringEngine::evaluateSinglePlayer(Player &player) {
    player.setPercentileRankAge(calculatePercentileRank(FeatureEngineer::getAllAges(), player.getAge()));
    player.setPercentileRankGoals(calculatePercentileRank(FeatureEngineer::getAllGoals(), player.getGoals()));
    player.setPercentileRankAssists(calculatePercentileRank(FeatureEngineer::getAllAssists(), player.getAssists()));
    player.setPercentileRankGoalsPer90(calculatePercentileRank(FeatureEngineer::getAllGoalsPer90(), player.getGoalsPer90()));
    player.setPercentileRankAssistsPer90(calculatePercentileRank(FeatureEngineer::getAllAssistsPer90(), player.getAssistsPer90()));
    player.setPercentileRankGoalsContributionsPer90(calculatePercentileRank(FeatureEngineer::getAllContributionsPer90(), player.getGoalsPer90() + player.getAssistsPer90()));
    player.setPercentileRankValue(calculatePercentileRank(FeatureEngineer::getAllValues(), player.getValue()));
    
    const std::map<std::string, double>& weights = getWeightsForPosition(player.getPosition());
    double score =
            weights.at("age") * player.getPercentileRankAge() +
            weights.at("goals") * player.getPercentileRankGoals() +
            weights.at("assists") * player.getPercentileRankAssists() +
            weights.at("goals_per_90") * player.getPercentileRankGoalsPer90() +
            weights.at("assists_per_90") * player.getPercentileRankAssistsPer90() +
            weights.at("contributions_per_90") * player.getPercentileRankGoalsContributionsPer90();
    player.setPerformanceScore(score);
    
    player.setUndervaluationScore(player.getPerformanceScore() - player.getPercentileRankValue());
}