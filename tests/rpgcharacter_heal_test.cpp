#include <gtest/gtest.h>

#include "constants.hpp"
#include "rpgcharacter.hpp"

using namespace ::testing;

class RPGCharacterHealTest : public ::testing::Test {
protected:
    RPGCharacterHealTest()
        : heroB()
    { }
    RPGCharacter const heroA;
    RPGCharacter heroB;

    void killHeroB();
};

void RPGCharacterHealTest::killHeroB() { heroA.dealDamageTo(heroB, heroB.getHealth()); }

TEST_F(RPGCharacterHealTest, DeadCharacterCannotBeHealed)
{
    killHeroB();
    heroB.applyHealingTo(heroB, 1);
    ASSERT_EQ(heroB.isAlive(), false);
}

TEST_F(RPGCharacterHealTest, CharacterCannotBeHealedAboveMaximum)
{
    heroB.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.getHealth(), maximum_health);
}

TEST_F(RPGCharacterHealTest, CharacterCanNotHealOtherCharacter)
{
    heroA.dealDamageTo(heroB, 1);
    heroA.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.getHealth(), maximum_health - 1);
}

TEST_F(RPGCharacterHealTest, CharacterCanHealSelf)
{
    heroA.dealDamageTo(heroB, 1);
    heroB.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.getHealth(), maximum_health);
}
