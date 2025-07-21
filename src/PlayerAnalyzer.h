//
// Created by dennis gega on 7/10/25.
//

#ifndef PLAYER_ANALYZER_H
#define PLAYER_ANALYZER_H

#include <vector>
#include <map>
#include "Player.h"

/**
 * @class PlayerAnalyzer
 * @brief Provides functionalities for analyzing player performance through
 *        percentile calculations and undervaluation scoring.
 */
class PlayerAnalyzer {
public:
    /**
     * @brief Calculates the individual percentile ranks for various attributes
     *        (such as age, goals, assists, values, etc.) for a given collection of players.
     * @param players A vector containing Player objects, representing the
     *                collection of players whose individual percentiles are to be calculated.
     */
    static void calculateIndividualPercentiles(std::vector<Player>& players);
    
    /**
     * @brief Calculates performance scores for players based on position-specific weights
     * @param players A vector containing Player objects to calculate performance scores for
     */
    static void calculatePerformanceScore(std::vector<Player>& players);
    
    /**
     * @brief Calculates undervaluation scores by comparing performance to market value percentiles
     * @param players A vector containing Player objects to calculate undervaluation scores for
     */
    static void calculateUndervaluationScore(std::vector<Player>& players);

    /**
     * @brief Calculates the percentile rank of a value within a sorted vector of values
     * @tparam T The numeric type of the values being ranked
     * @param values Vector of sorted values to calculate the percentile against
     * @param value The specific value to find the percentile rank for
     * @return The percentile rank as a value between 0 and 1
     */
    template<typename T>
    static double calculatePercentileRank(const std::vector<T>& values, T value) {
        return std::distance(values.begin(), std::lower_bound(values.begin(), values.end(), value)) / static_cast<double>(values.size());
    }

private:
    /**
     * @brief Gets position-specific weights for performance score calculation
     * @param position The player position to get weights for
     * @return Map containing attribute names and their corresponding weights
     */
    static std::map<std::string, double> getPositionWeights(Position position);
};

#endif //PLAYER_ANALYZER_H