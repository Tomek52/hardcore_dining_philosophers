#pragma once

#include <string>
#include <thread>
#include <functional>
#include "Table.hpp"

class Philosopher
{
    const std::string name_;
    Table const& dinnerTable_; 
    Fork& leftFork_;
    Fork& rightFork_;
    mutable std::mutex mtxLockPrint;

    public:
    Philosopher(const std::string& name, 
                Table const& dinnerTable, 
                Fork& leftFork, 
                Fork& rightFork);
    std::string getName() const;
    void print(std::string text) const;
    int evaluateAnswer( std::string question, std::string answer);
    virtual void think();
    void eat();
    void dine();
    void joinToTable();
};
