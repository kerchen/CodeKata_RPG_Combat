#include <gtest/gtest.h>

#include "constants.hpp"
#include "rpgcharacter.hpp"

using namespace ::testing;

class RPGCharacterHealTest : public ::testing::Test {
protected:
    RPGCharacter const heroA;
    RPGCharacter heroB;

    void killHeroB();
};

void RPGCharacterHealTest::killHeroB() { heroA.dealDamageTo(heroB, heroB.getHealth()); }

TEST_F(RPGCharacterHealTest, DeadCharacterCannotBeHealed)
{
    killHeroB();
    heroA.applyHealingTo(heroB, 1);
    ASSERT_EQ(heroB.isAlive(), false);
}

TEST_F(RPGCharacterHealTest, CharacterCannotBeHealedAboveMaximum)
{
    heroA.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.getHealth(), maximum_health);
}
