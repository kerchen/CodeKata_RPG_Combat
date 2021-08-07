#include <gtest/gtest.h>

#include "position.hpp"

class DistanceTest : public ::testing::Test {
protected:
    DistanceTest()
    {
    }
    Position const positionA {10.0};
    Position const positionB { 0.0 };
};

TEST_F(DistanceTest, GetDistanceComputesCorrectValue)
{
    ASSERT_EQ(positionA.getDistance(positionB), 10.0);
}

TEST_F(DistanceTest, GetDistanceComputesCorrectValueForSymmetricCase)
{
    ASSERT_EQ(positionB.getDistance(positionA), 10.0);
}
