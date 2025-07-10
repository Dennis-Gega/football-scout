//
// Created by dennis gega on 7/10/25.
//

#include "FeatureEngineer.h"

#include <algorithm>

PlayerStats FeatureEngineer::calculateStats(std::vector<Player> &players) {
    PlayerStats stats;

    for (Player &player : players) {
        stats.ages.update(player.getAge());
        stats.goals.update(player.getGoals());
        stats.assists.update(player.getAssists());
        stats.goals_per_90.update(player.getGoalsPer90());
        stats.assists_per_90.update(player.getAssistsPer90());
        stats.contributions_per_90.update(player.getGoalsPer90() + player.getAssistsPer90());
    }

    return stats;
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

