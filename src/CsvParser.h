#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <vector>
#include "Player.h"

std::vector<Player> loadPlayersFromCsv(std::string& filepath);

#endif