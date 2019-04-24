#pragma once

#include <atomic>
#include <array>

#include "Fork.hpp"

constexpr int numberOfPhilosophers = 5;

class Table
{    
    public:
    std::atomic<bool> ready{false};
    std::array<Fork, numberOfPhilosophers> forks;
};
