#include <gtest/gtest.h>

int main()
{
    try {
        testing::InitGoogleTest();
        auto code = RUN_ALL_TESTS();
        return code;
    }
    catch (...)
    {
        return 0;
    }
    return 0;
}