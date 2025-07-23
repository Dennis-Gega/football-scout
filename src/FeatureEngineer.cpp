#include "FeatureEngineer.h"

#include <algorithm>

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

void FeatureEngineer::sortByUndervaluationScore(std::vector<Player> &players) {
    std::sort(players.begin(), players.end(), [](const Player &a, const Player &b) {
        return a.getUndervaluationScore() > b.getUndervaluationScore();
    });
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