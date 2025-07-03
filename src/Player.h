#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player
{
private:
    std::string name;
    std::string position;
    
    long long value;
    
    int player_id;
    int age;
    int goals;
    int assists;
    
    double goals_per_90;
    double assists_per_90;
    double goals_contributions_per_90;


public:
    Player() : player_id{0}, value{0LL}, age{0}, goals{0},
    assists{0}, goals_per_90{0.0f}, assists_per_90{0.0f},
    name{""}, position{""} {}
    
    Player(int player_id, int value, int age, int goals, int assists,
             double goals_per_90, double assists_per_90,
             const std::string& name, const std::string& position)
          : player_id(player_id), value(value), age(age),
            goals(goals), assists(assists),
            goals_per_90(goals_per_90), assists_per_90(assists_per_90),
            name(name), position(position) {}
    
    std::string getName() const { return name; }
    std::string getPosition() const { return position; }
    long long getValue() const { return value; }
    int getPlayerId() const { return player_id; }
    int getAge() const { return age; }
    int getGoals() const { return goals; }
    int getAssists() const { return assists; }
    double getGoalsPer90() const { return goals_per_90; }
    double getAssistsPer90() const { return assists_per_90; }
    
    void print_info() const
    {
        std::cout << name << ", value: " << value << '\n';
    }
};

#endif
