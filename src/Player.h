#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player
{
private:
    std::string name;
    std::string position;
    
    int player_id;
    int value;
    int age;
    int goals;
    int assists;
    
    float goals_per_90;
    float assists_per_90;


public:
    Player() : player_id{0}, value{0}, age{0}, goals{0},
    assists{0}, goals_per_90{0.0f}, assists_per_90{0.0f},
    name{""}, position{""} {}
    
    Player(int player_id, int value, int age, int goals, int assists,
             float goals_per_90, float assists_per_90,
             const std::string& name, const std::string& position)
          : player_id(player_id), value(value), age(age),
            goals(goals), assists(assists),
            goals_per_90(goals_per_90), assists_per_90(assists_per_90),
            name(name), position(position) {}
    
    void print_info() const
    {
        std::cout << name << ", value: " << value << '\n';
    }
};

#endif
