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


void Philosopher::think()
{
    print("started thinking");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    print("finished thinking");
}

void Philosopher::eat()
{
    std::lock(leftFork_.mutex, rightFork_.mutex);
    std::lock_guard<std::mutex> leftLock(leftFork_.mutex, std::adopt_lock);
    std::lock_guard<std::mutex> rightLock(rightFork_.mutex, std::adopt_lock);

    std::cout<<"started eating"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"finished eating"<<std::endl;
}

void Philosopher::dine()
{
    while(!dinnerTable_.ready)
    do
    {
        think();
        eat();
    } while(dinnerTable_.ready);
}

void Philosopher::joinToTable()
{
    std::thread t(&Philosopher::dine, this);
    t.detach();
}

int Philosopher::evaluateAnswer( std::string question, std::string answer)
{
        std::size_t h1 = std::hash<std::string>{}(question);
        std::size_t h2 = std::hash<std::string>{}(answer);
        std::size_t h3 = std::hash<std::string>{}(name_);
        return h1 ^ (h2 << 1) ^ ( h3 << 2 ); 
}