//
// Created by Gosha on 15.06.2022.
//

#include "Record.h"

Record::Record(const std::string &player, int score) : player(player), score(score) {}

//std::ostream &operator<<(std::ostream &os, const Record &record) {
//    os << "player: " << record.player << " score: " << record.score;
//    return os;
//}
//