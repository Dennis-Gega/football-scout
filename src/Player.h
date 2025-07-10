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
    Player() : position(), player_id{0}, value{0LL}, age{0}, goals{0},
               assists{0}, goals_per_90{0.0f}, assists_per_90{0.0f}, goals_contributions_per_90(0), normalized_value(0),
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
          goals_per_90(goals_per_90), assists_per_90(assists_per_90), goals_contributions_per_90(0),
          normalized_value(0), normalized_age(0),
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
    long long getValue() const { return value; }
    int getPlayerId() const { return player_id; }
    int getAge() const { return age; }
    int getGoals() const { return goals; }
    int getAssists() const { return assists; }
    double getGoalsPer90() const { return goals_per_90; }
    double getAssistsPer90() const { return assists_per_90; }

    // Normalized values
    void setNormalizedValue(const double value) { normalized_value = value; }
    void setNormalizedAge(const double value) { normalized_age = value; }
    void setNormalizedGoals(const double value) { normalized_goals = value; }
    void setNormalizedAssists(const double value) { normalized_assists = value; }
    void setNormalizedGoalsPer90(const double value) { normalized_goals_per_90 = value; }
    void setNormalizedAssistsPer90(const double value) { normalized_assists_per_90 = value; }
    void setNormalizedGoalsContributionsPer90(double value) { normalized_goals_contributions_per_90 = value; }

void print_info() const {
        std::cout << "Player ID: " << player_id
                << "\nName: " << name
                << "\nPosition: " << position
                << "\nValue: " << value
                << "\nAge: " << age
                << "\nGoals: " << goals
                << "\nAssists: " << assists
                << "\nGoals per 90: " << goals_per_90
                << "\nAssists per 90: " << assists_per_90
                << "\nGoals contributions per 90: " << goals_contributions_per_90
                << "\nNormalized value: " << normalized_value
                << "\nNormalized age: " << normalized_age
                << "\nNormalized goals: " << normalized_goals
                << "\nNormalized assists: " << normalized_assists
                << "\nNormalized goals per 90: " << normalized_goals_per_90
                << "\nNormalized assists per 90: " << normalized_assists_per_90
                << "\nNormalized goals contributions per 90: " << normalized_goals_contributions_per_90
                << "\n";
    }

private:
    std::string name;
    Position position;

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
    double normalized_value;
    double normalized_age;
    double normalized_goals;
    double normalized_assists;
    double normalized_goals_per_90;
    double normalized_assists_per_90;
    double normalized_goals_contributions_per_90;
};

#endif
