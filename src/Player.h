#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

enum Position {
    DEFENDER,
    MIDFIELDER,
    FORWARD,
    UNKNOWN
};

class Player
{
public:
    Player() : position(), value{0LL}, player_id{0}, age{0}, goals{0},
               assists{0}, goals_per_90{0.0f}, assists_per_90{0.0f}, goal_contributions_per_90(0),
               normalized_age(0),
               normalized_goals(0),
               normalized_assists(0),
               normalized_goals_per_90(0),
               normalized_assists_per_90(0),
               normalized_goal_contributions_per_90(0) {
    }

    Player(int player_id, int value, int age, int goals, int assists,
           double goals_per_90, double assists_per_90,
           const std::string& name, Position position)
        : player_id(player_id), value(value), age(age),
          goals(goals), assists(assists),
          goals_per_90(goals_per_90), assists_per_90(assists_per_90), goal_contributions_per_90(goals_per_90 + assists_per_90),
          normalized_age(0),
          normalized_goals(0),
          normalized_assists(0),
          normalized_goals_per_90(0),
          normalized_assists_per_90(0),
          normalized_goal_contributions_per_90(0),
          name(name), position(position) {
    }

    // Raw values
    std::string getName() const { return name; }
    Position getPosition() const { return position; }
    long long getValue() const { return value; }
    double getPerformanceScore() const { return performance_score; }
    double getUndervaluationScore() const { return undervaluation_score; }
    double getGoalsPer90() const { return goals_per_90; }
    double getAssistsPer90() const { return assists_per_90; }
    double getGoalsContributionsPer90() const { return goal_contributions_per_90; }
    int getPlayerId() const { return player_id; }
    int getAge() const { return age; }
    int getGoals() const { return goals; }
    int getAssists() const { return assists; }


    void setName(std::string n) { name = n; }
    void setPosition(Position p) { position = p; }
    void setValue(long long v) { value = v; }
    void setPerformanceScore(double score) { performance_score = score; }
    void setUndervaluationScore(double score) { undervaluation_score = score; }
    void setGoalsPer90(double player_goals_per_90) { goals_per_90 = player_goals_per_90; }
    void setAssistsPer90(double player_assists_per_90) { assists_per_90 = player_assists_per_90; }
    void setGoalsContributionsPer90(double player_goals_contributions_per_90) { goal_contributions_per_90 = player_goals_contributions_per_90; }
    void setPlayerId(int id) { player_id = id; }
    void setAge(int player_age) { age = player_age; }
    void setGoals(int player_goals) { goals = player_goals; }
    void setAssists(int player_assists) { assists = player_assists; }

    // Normalized values
    void setNormalizedAge(const double value) { normalized_age = value; }
    void setNormalizedGoals(const double value) { normalized_goals = value; }
    void setNormalizedAssists(const double value) { normalized_assists = value; }
    void setNormalizedGoalsPer90(const double value) { normalized_goals_per_90 = value; }
    void setNormalizedAssistsPer90(const double value) { normalized_assists_per_90 = value; }
    void setNormalizedGoalsContributionsPer90(double value) { normalized_goal_contributions_per_90 = value; }

    // Percentile values
    void setPercentileRankAge(const double value) { percentile_rank_age = value; }
    void setPercentileRankGoals(const double value) { percentile_rank_goals = value; }
    void setPercentileRankAssists(const double value) { percentile_rank_assists = value; }
    void setPercentileRankGoalsPer90(const double value) { percentile_rank_goals_per_90 = value; }
    void setPercentileRankAssistsPer90(const double value) { percentile_rank_assists_per_90 = value; }
    void setPercentileRankGoalsContributionsPer90(const double value) { percentile_rank_goal_contributions_per_90 = value; }
    void setPercentileRankValue(const double value) { percentile_rank_value = value; }

    double getPercentileRankAge() const { return percentile_rank_age; }
    double getPercentileRankGoals() const { return percentile_rank_goals; }
    double getPercentileRankAssists() const { return percentile_rank_assists; }
    double getPercentileRankGoalsPer90() const { return percentile_rank_goals_per_90; }
    double getPercentileRankAssistsPer90() const { return percentile_rank_assists_per_90; }
    double getPercentileRankGoalsContributionsPer90() const { return percentile_rank_goal_contributions_per_90; }
    double getPercentileRankValue() const { return percentile_rank_value; }


private:
    std::string name;
    Position position;
    double performance_score;
    double undervaluation_score;

    // Raw values
    long long value;
    int player_id;
    int age;
    int goals;
    int assists;
    double goals_per_90;
    double assists_per_90;
    double goal_contributions_per_90;

    // Normalized values
    double normalized_age;
    double normalized_goals;
    double normalized_assists;
    double normalized_goals_per_90;
    double normalized_assists_per_90;
    double normalized_goal_contributions_per_90;

    // Percentile values
    double percentile_rank_age;
    double percentile_rank_goals;
    double percentile_rank_assists;
    double percentile_rank_goals_per_90;
    double percentile_rank_assists_per_90;
    double percentile_rank_goal_contributions_per_90;
    double percentile_rank_value;
};

#endif // PLAYER_H
