#include <gtest/gtest.h>

#include "constants.hpp"
#include "rpgcharacter.hpp"

using namespace ::testing;

class RPGCharacterDealDamageTest : public ::testing::Test {
protected:
    RPGCharacterDealDamageTest() { }
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

    heroA.dealDamageTo(heroB, heroB.getHealth() + 1.0f);
    ASSERT_EQ(heroB.getHealth(), 0.0f);
}

TEST_F(RPGCharacterDealDamageTest, DealDamageToKill)
{

    heroA.dealDamageTo(heroB, initial_health);
    ASSERT_EQ(heroB.isAlive(), false);
}

TEST_F(RPGCharacterDealDamageTest, CharacterCantDealDamageToSelf)
{
    heroB.dealDamageTo(heroB, 1.0f);
    ASSERT_EQ(heroB.getHealth(), initial_health);
}

RPGCharacter getHeroLevel(std::uint8_t level) { return RPGCharacter{initial_health, level}; }

TEST_F(RPGCharacterDealDamageTest, DamageToHighLevelCharacterIsReduced)
{
    heroB = getHeroLevel(100);
    heroA.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), 750.0f);
}
