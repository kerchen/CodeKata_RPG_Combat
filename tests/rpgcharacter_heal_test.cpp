#include <gtest/gtest.h>

#include "rpgcharacter.hpp"
#include "constants.hpp"

using namespace ::testing;

class RPGCharacterHealTest : public ::testing::Test {
protected:
    RPGCharacter const heroA;
    RPGCharacter heroB;
};

TEST_F(RPGCharacterHealTest, DeadCharacterCannotBeHealed)
{
    heroA.dealDamageTo(heroB, heroB.getHealth());
    heroA.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.isAlive(), false);
}

TEST_F(RPGCharacterHealTest, CharacterCannotBeHealedAboveMaximum)
{
    heroA.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.getHealth(), maximum_health);
}
