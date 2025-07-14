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
               assists{0}, goals_per_90{0.0f}, assists_per_90{0.0f}, goals_contributions_per_90(0),
               normalized_age(0),
               normalized_goals(0),
               normalized_assists(0),
               normalized_goals_per_90(0),
               normalized_assists_per_90(0),
               normalized_goals_contributions_per_90(0) {
    }

    Player(int player_id, int value, int age, int goals, int assists,
           double goals_per_90, double assists_per_90,
           const std::string& name, Position position)
        : player_id(player_id), value(value), age(age),
          goals(goals), assists(assists),
          goals_per_90(goals_per_90), assists_per_90(assists_per_90), goals_contributions_per_90(goals_per_90 + assists_per_90),
          normalized_age(0),
          normalized_goals(0),
          normalized_assists(0),
          normalized_goals_per_90(0),
          normalized_assists_per_90(0),
          normalized_goals_contributions_per_90(0),
          name(name), position(position) {
    }

    // Raw values
    std::string getName() const { return name; }
    Position getPosition() const { return position; }
    double getPerformanceScore() const { return performance_score; }
    double setPerformanceScore(double score) { return performance_score = score; }
    double getUndervaluationScore() const { return undervaluation_score; }
    double setUndervaluationScore(double score) { return undervaluation_score = score; }
    long long getValue() const { return value; }
    int getPlayerId() const { return player_id; }
    int getAge() const { return age; }
    int getGoals() const { return goals; }
    int getAssists() const { return assists; }
    double getGoalsPer90() const { return goals_per_90; }
    double getAssistsPer90() const { return assists_per_90; }

    // Normalized values
    void setNormalizedAge(const double value) { normalized_age = value; }
    void setNormalizedGoals(const double value) { normalized_goals = value; }
    void setNormalizedAssists(const double value) { normalized_assists = value; }
    void setNormalizedGoalsPer90(const double value) { normalized_goals_per_90 = value; }
    void setNormalizedAssistsPer90(const double value) { normalized_assists_per_90 = value; }
    void setNormalizedGoalsContributionsPer90(double value) { normalized_goals_contributions_per_90 = value; }

    // Percentile values
    void setPercentileRankAge(const double value) { percentile_rank_age = value; }
    void setPercentileRankGoals(const double value) { percentile_rank_goals = value; }
    void setPercentileRankAssists(const double value) { percentile_rank_assists = value; }
    void setPercentileRankGoalsPer90(const double value) { percentile_rank_goals_per_90 = value; }
    void setPercentileRankAssistsPer90(const double value) { percentile_rank_assists_per_90 = value; }
    void setPercentileRankGoalsContributionsPer90(const double value) { percentile_rank_goals_contributions_per_90 = value; }
    void setPercentileRankValue(const double value) { percentile_rank_value = value; }

    double getPercentileRankAge() const { return percentile_rank_age; }
    double getPercentileRankGoals() const { return percentile_rank_goals; }
    double getPercentileRankAssists() const { return percentile_rank_assists; }
    double getPercentileRankGoalsPer90() const { return percentile_rank_goals_per_90; }
    double getPercentileRankAssistsPer90() const { return percentile_rank_assists_per_90; }
    double getPercentileRankGoalsContributionsPer90() const { return percentile_rank_goals_contributions_per_90; }
    double getPercentileRankValue() const { return percentile_rank_value; }

void print_info() const {
    // Helper functions to print section header
    auto print_header = [](const std::string& header) {
        std::cout << "\n=== " << header << " ===\n";
    };

    // Basic Information
    print_header("Basic Information");
    std::cout << "Player ID: " << player_id << '\n'
              << "Name: " << name << '\n'
              << "Position: " << position << '\n'
              << "Value: " << value << '\n'
              << "Performance Score: " << performance_score << '\n';

    // Raw Statistics
    print_header("Raw Statistics");
    std::cout << "Age: " << age << '\n'
              << "Goals: " << goals << '\n'
              << "Assists: " << assists << '\n'
              << "Goals per 90: " << goals_per_90 << '\n'
              << "Assists per 90: " << assists_per_90 << '\n'
              << "Goals contributions per 90: " << goals_contributions_per_90 << '\n';

    // Normalized Values
    print_header("Normalized Values");
    std::cout << "Age: " << normalized_age << '\n'
              << "Goals: " << normalized_goals << '\n'
              << "Assists: " << normalized_assists << '\n'
              << "Goals per 90: " << normalized_goals_per_90 << '\n'
              << "Assists per 90: " << normalized_assists_per_90 << '\n'
              << "Goals contributions per 90: " << normalized_goals_contributions_per_90 << '\n';

    // Percentile Rankings
    print_header("Percentile Rankings");
    std::cout << "Age: " << percentile_rank_age << '\n'
              << "Goals: " << percentile_rank_goals << '\n'
              << "Assists: " << percentile_rank_assists << '\n'
              << "Goals per 90: " << percentile_rank_goals_per_90 << '\n'
              << "Assists per 90: " << percentile_rank_assists_per_90 << '\n'
              << "Goals contributions per 90: " << percentile_rank_goals_contributions_per_90 << '\n'
              << "Value: " << percentile_rank_value << '\n';
}

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
    double goals_contributions_per_90;

    // Normalized values
    double normalized_age;
    double normalized_goals;
    double normalized_assists;
    double normalized_goals_per_90;
    double normalized_assists_per_90;
    double normalized_goals_contributions_per_90;

    // Percentile values
    double percentile_rank_age;
    double percentile_rank_goals;
    double percentile_rank_assists;
    double percentile_rank_goals_per_90;
    double percentile_rank_assists_per_90;
    double percentile_rank_goals_contributions_per_90;
    double percentile_rank_value;
};

#endif