#ifndef SCORING_ENGINE_H
#define SCORING_ENGINE_H

#include "Player.h"

#include <map>

/**
 * @class ScoringEngine
 * @brief Provides methods for calculating player scores and percentiles.
 */
class ScoringEngine {
public:

    /**
     * @brief Calculates the individual percentile ranks for various attributes for a given collection of players.
     * @param players A vector containing Player objects, representing the collection of players whose individual percentiles are to be calculated.
     */
    static void calculateAllPercentiles(std::vector<Player> &players);

    /**
     * @brief Calculates the individual performance scores for various attributes for a given collection of players.
     * @param players A vector containing Player objects, representing the collection of players whose individual performance scores are to be calculated.
     */
    static void calculateAllPerformanceScores(std::vector<Player> &players);

    /**
     * @brief Calculates the individual undervaluation scores for various attributes for a given collection of players.
     * @param players A vector containing Player objects, representing the collection of players whose individual undervaluation scores are to be calculated.
     */
    static void calculateAllUndervaluationScores(std::vector<Player> &players);

    /**
     * @brief Calculates the individual percentile ranks, performance, and undervaluation scores for a single player.
     * @param player The Player object for which the scores are to be calculated.
     */
    static void evaluateSinglePlayer(Player& player);

    // Getters for position weights
    static const std::map<std::string, double>& getForwardWeights();
    static const std::map<std::string, double>& getMidfielderWeights();
    static const std::map<std::string, double>& getDefenderWeights();

private:

    /**
     * @brief Calculates the percentile rank of a value within a sorted vector of values.
     * @tparam T The numeric type of the values being ranked.
     * @param values Vector of sorted values to calculate the percentile against.
     * @param value The specific value to find the percentile rank for.
     * @return The percentile rank as a value between 0 and 1.
     */
    template<typename T>
    static double calculatePercentileRank(std::vector<T> &values, T value);
};

#endif // SCORINGENGINE_H
