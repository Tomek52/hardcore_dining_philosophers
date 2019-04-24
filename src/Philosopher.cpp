#include <iostream>
#include <string>

#include "Philosopher.hpp"

Philosopher::Philosopher(const std::string& name, 
                Table const& dinnerTable, 
                Fork& leftFork, 
                Fork& rightFork)
                : name_(name)
                , dinnerTable_(dinnerTable)
                , leftFork_(leftFork)
                , rightFork_(rightFork)
{}