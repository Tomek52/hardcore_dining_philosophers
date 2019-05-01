#include <gtest/gtest.h>
#include <functional>
#include "Philosopher.hpp"
#include "Table.hpp"
#include "Fork.hpp"

struct PhilosopherTests : public ::testing::Test
{
    Table table;
    std::string philosopherName = "Platon";
    std::vector<std::string> platonAnswers = {
        "Truth.",                                   
        "Fruitless effort.",    
        "Strawberry.",  
        "Soul.",
        "Eureka.",
        "Hmm.",
        "I need to find someone wiser then me.",
        "Ok, I see. Now I need to prove it.",
        "World of sets. Lol. There is some order.",
        "Hahaha. No way."
    };
    Philosopher philosopher1{philosopherName, table, table.forks[0], table.forks[1]};

};

TEST_F(PhilosopherTests, checkIfTrueIsEqTrue)
{
    ASSERT_TRUE(true);
}

TEST_F(PhilosopherTests, checkIfFunctionGetNameReturnProperValue)
{
    ASSERT_EQ(philosopher1.getName(), philosopherName);
}

TEST_F(PhilosopherTests, checkIfTrueIsEqTrue2)
{
    //GIVEN
    std::string text = "testing";
    std::string expectedStdOutput = philosopher1.getName() + " " + text + '\n';
    testing::internal::CaptureStdout();
    philosopher1.print(text);
    std::string stdOutput = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedStdOutput, stdOutput);
}


TEST_F(PhilosopherTests, evaluateAnwserAsStandardHash)
{
    //GIVEN
    std::string text = "testing";
    std::string expectedStdOutput = philosopher1.getName() + " " + text + '\n';
    auto philosophMethod = [](std::string question, std::string anwser, std::string name )  
    {
        std::size_t h1 = std::hash<std::string>{}(question);
        std::size_t h2 = std::hash<std::string>{}(anwser);
        std::size_t h3 = std::hash<std::string>{}(name);
        return h1 ^ (h2 << 1) ^ ( h3 << 2 ); 
    };
    int result = philosophMethod( "Really?", "Yes.", "Platon" );
    ASSERT_EQ( result , philosopher1.evaluateAnswer( "Really?", "Yes." ) );
}
