//
// Created by Gosha on 15.06.2022.
//

#include <random>
#include "Utils.h"

int Utils::generateRandomInt(const int min, const int max) {
    static bool is_seeded = false;
    static std::mt19937 generator;

    // Seed once
    if (!is_seeded) {
        std::random_device rd;
        generator.seed(rd());
        is_seeded = true;
    }

    // Use mersenne twister engine to pick a random number
    // within the given range
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}
