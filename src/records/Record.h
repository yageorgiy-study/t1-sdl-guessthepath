//
// Created by Gosha on 15.06.2022.
//

#ifndef GUESSTHEPATH_RECORD_H
#define GUESSTHEPATH_RECORD_H


#include <string>
#include <ostream>

class Record {
public:
    Record(const std::string &player, int score);
    std::string player = "Player";
    int score = 0;

//public:
//    friend std::ostream &operator<<(std::ostream &os, const Record &record);
};


#endif //GUESSTHEPATH_RECORD_H
