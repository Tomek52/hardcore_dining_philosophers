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

std::string Philosopher::getName() const
{
    return name_;
}

void Philosopher::print(std::string text) const
{
    std::lock_guard<std::mutex> lg(mtxLockPrint);
    std::cout<<name_<<" "<<text<<'\n';
}