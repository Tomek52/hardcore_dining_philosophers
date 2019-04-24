#include <gtest/gtest.h>
#include "Philosopher.hpp"
#include "Table.hpp"
#include "Fork.hpp"

struct PhilosopherTests : public ::testing::Test
{
    //GIVEN
    Table table;
    std::string philosopherName = "Platon";
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
