//
// Created by dennis gega on 7/7/25.
//

#ifndef FEATURE_ENGINEER_H
#define FEATURE_ENGINEER_H
#include <vector>
#include "Player.h"

template<typename T>
struct MinMax {
    T min = std::numeric_limits<T>::max();
    T max = std::numeric_limits<T>::min();

    void update(T value) {
        min = std::min(min, value);
        max = std::max(max, value);
    }

    double normalize(T value) const {
        if (max == min) return 0;
        return static_cast<double>(value - min) / (max - min);
    }
};

struct PlayerStats {
    MinMax<int> ages;
    MinMax<int> goals;
    MinMax<int> assists;
    MinMax<double> goals_per_90;
    MinMax<double> assists_per_90;
    MinMax<double> contributions_per_90;
    MinMax<long long> values;
};

/**
 * @class FeatureEngineer
 * @brief Provides functionalities for feature engineering, specifically
 *        normalization of numerical attributes for a collection of players.
 */
class FeatureEngineer {
public:
    /**
     * @brief Normalizes numerical attributes (such as goals, assists, values, etc.)
     *        for a given collection of players.
     * @param players A vector containing Player objects, representing the
     *                collection of players whose numerical attributes need to be normalized.
     */
    static void normalizeNumericalFeatures(std::vector<Player>& players);

    /**
     * @brief Calculates the individual percentile ranks for various attributes
     *        (such as age, goals, assists, values, etc.) for a given collection of players.
     * @param players A vector containing Player objects, representing the
     *                collection of players whose individual percentiles are to be calculated.
     */
    static void calculateIndividualPercentiles(std::vector<Player> &players);
    static void calculatePerformanceScore(std::vector<Player> &players);
    static void calculateUndervaluationScore(std::vector<Player> &players);
    static void generateReport(const std::vector<Player>& players, int num_top_players);
private:
    static void sortByUndervaluationScore(std::vector<Player> &players);
    /**
     * @brief Prints a formatted header for each position group in the report
     * @param pos The position (FORWARD, MIDFIELDER, or DEFENDER) to create the header for
     */
    static void printPositionHeader(Position pos);

    /**
     * @brief Calculates the percentile rank of a value within a sorted vector of values
     * @tparam T The numeric type of the values being ranked
     * @param values Vector of sorted values to calculate the percentile against
     * @param value The specific value to find the percentile rank for
     * @return The percentile rank as a value between 0 and 1
     */
    template<typename T>
    static double calculatePercentileRank(std::vector<T> &values, T value);

    /**
     * @brief Calculates statistical information for all numerical attributes across all players
     * @param players Vector of players to analyze
     * @return PlayerStats struct containing min/max values for all numerical attributes
     */
    static PlayerStats calculateStats(std::vector<Player> &players);

    /**
     * @brief Calculates statistical information for all numerical attributes across all players
     * @param players Vector of players to analyze
     * @return PlayerStats struct containing min/max values for all numerical attributes
     */
    static void applyNormalization(std::vector<Player> &players, const PlayerStats &stats);

    // Static vectors to store all values for percentile calculations
    static std::vector<int> all_ages;
    static std::vector<int> all_goals;
    static std::vector<int> all_assists;
    static std::vector<double> all_goals_per_90;
    static std::vector<double> all_assists_per_90;
    static std::vector<double> all_contributions_per_90;
    static std::vector<long long> all_values;
};

#endif //FEATURE_ENGINEER_H
