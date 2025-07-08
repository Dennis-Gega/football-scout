//
// Created by dennis gega on 7/7/25.
//

#ifndef FEATURE_ENGINEER_H
#define FEATURE_ENGINEER_H
#include <vector>

#include "Player.h"

class FeatureEngineer {
public:
    void normalizeNumericalFeatures(std::vector<Player>& players);
};

#endif //FEATURE_ENGINEER_H
