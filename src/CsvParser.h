#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <vector>
#include "Player.h"

/**
 * @brief Parse csv file into football player instances
 * @param filepath String containing path to csv file
 * @return A vector containing instances of the Player class
 */
std::vector<Player> loadPlayersFromCsv(std::string& filepath);

#endif //
