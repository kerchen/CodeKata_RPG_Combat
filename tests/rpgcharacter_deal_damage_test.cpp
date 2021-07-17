#include <gtest/gtest.h>

#include "constants.hpp"
#include "rpgcharacter.hpp"

using namespace ::testing;

class RPGCharacterDealDamageTest : public ::testing::Test {
protected:
    RPGCharacter const heroA;
    RPGCharacter heroB;
};

TEST_F(RPGCharacterDealDamageTest, DealDamageReducesHealthOfTargetCharacter)
{
    heroA.dealDamageTo(heroB);
    ASSERT_LT(heroB.getHealth(), initial_health);
}

TEST_F(RPGCharacterDealDamageTest, DealDamageForHealthZero)
{

    heroA.dealDamageTo(heroB, initial_health);
    ASSERT_EQ(heroB.getHealth(), 0);
}

TEST_F(RPGCharacterDealDamageTest, DealingDamageInExcessOfCurrentHealthResultsInZeroHealth)
{

    heroA.dealDamageTo(heroB, heroB.getHealth() + 1);
    ASSERT_EQ(heroB.getHealth(), 0);
}

TEST_F(RPGCharacterDealDamageTest, DealDamageToKill)
{

    heroA.dealDamageTo(heroB, initial_health);
    ASSERT_EQ(heroB.isAlive(), false);
}