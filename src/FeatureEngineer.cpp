//
// Created by dennis gega on 7/10/25.
//

#include "FeatureEngineer.h"

#include <algorithm>
#include <map>

// Add these definitions at the top of the file, before any function definitions
std::vector<int> FeatureEngineer::all_ages;
std::vector<int> FeatureEngineer::all_goals;
std::vector<int> FeatureEngineer::all_assists;
std::vector<double> FeatureEngineer::all_goals_per_90;
std::vector<double> FeatureEngineer::all_assists_per_90;
std::vector<double> FeatureEngineer::all_contributions_per_90;
std::vector<long long> FeatureEngineer::all_values;

PlayerStats FeatureEngineer::calculateStats(std::vector<Player> &players) {
    PlayerStats stats;

    for (Player &player : players) {
        stats.ages.update(player.getAge());
        all_ages.push_back(player.getAge());
        stats.goals.update(player.getGoals());
        all_goals.push_back(player.getGoals());
        stats.assists.update(player.getAssists());
        all_assists.push_back(player.getAssists());
        stats.goals_per_90.update(player.getGoalsPer90());
        all_goals_per_90.push_back(player.getGoalsPer90());
        stats.assists_per_90.update(player.getAssistsPer90());
        all_assists_per_90.push_back(player.getAssistsPer90());
        stats.contributions_per_90.update(player.getGoalsPer90() + player.getAssistsPer90());
        all_contributions_per_90.push_back(player.getGoalsPer90() + player.getAssistsPer90());
        stats.values.update(player.getValue());
        all_values.push_back(player.getValue());
    }

    return stats;
}

template<typename T>
double FeatureEngineer::calculatePercentileRank(std::vector<T> &values, T value) {
    return std::distance(values.begin(), std::lower_bound(values.begin(), values.end(), value)) / static_cast<double>(values.size());
}

void FeatureEngineer::calculateIndividualPercentiles(std::vector<Player> &players) {
    for (Player &player : players) {
        player.setPercentileRankAge(calculatePercentileRank(all_ages, player.getAge()));
        player.setPercentileRankGoals(calculatePercentileRank(all_goals, player.getGoals()));
        player.setPercentileRankAssists(calculatePercentileRank(all_assists, player.getAssists()));
        player.setPercentileRankGoalsPer90(calculatePercentileRank(all_goals_per_90, player.getGoalsPer90()));
        player.setPercentileRankAssistsPer90(calculatePercentileRank(all_assists_per_90, player.getAssistsPer90()));
        player.setPercentileRankGoalsContributionsPer90(calculatePercentileRank(all_contributions_per_90, player.getGoalsPer90() + player.getAssistsPer90()));
        player.setPercentileRankValue(calculatePercentileRank(all_values, player.getValue()));
    }
}

void FeatureEngineer::calculatePerformanceScore(std::vector<Player> &players) {
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

void FeatureEngineer::applyNormalization(std::vector<Player>& players, const PlayerStats &stats) {
    for (Player& player : players) {
        player.setNormalizedAge(stats.ages.normalize(player.getAge()));
        player.setNormalizedGoals(stats.goals.normalize(player.getGoals()));
        player.setNormalizedAssists(stats.assists.normalize(player.getAssists()));
        player.setNormalizedGoalsPer90(stats.goals_per_90.normalize(player.getGoalsPer90()));
        player.setNormalizedAssistsPer90(stats.assists_per_90.normalize(player.getAssistsPer90()));
        player.setNormalizedGoalsContributionsPer90(stats.contributions_per_90.normalize(player.getGoalsPer90() + player.getAssistsPer90()));
    }
}

void FeatureEngineer::normalizeNumericalFeatures(std::vector<Player> &players) {
   PlayerStats stats = calculateStats(players);
   applyNormalization(players, stats);
}