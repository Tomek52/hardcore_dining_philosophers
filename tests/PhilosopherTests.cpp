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