#include "constants.hpp"
#include "faction.hpp"
#include "rpgcharacter.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ::testing;

class RPGCharacterHealTest : public ::testing::Test {
protected:
    RPGCharacterHealTest() { }
    RPGCharacter heroA;
    RPGCharacter heroB;

    void killHeroB();
    void reduceHeroBHealth();
};

void RPGCharacterHealTest::killHeroB() { heroA.dealDamageTo(heroB, heroB.getHealth()); }
void RPGCharacterHealTest::reduceHeroBHealth() { heroA.dealDamageTo(heroB, 1); }

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
    reduceHeroBHealth();
    heroA.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.getHealth(), maximum_health - 1);
}

TEST_F(RPGCharacterHealTest, CharacterCanHealSelf)
{
    reduceHeroBHealth();
    heroB.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.getHealth(), maximum_health);
}

TEST_F(RPGCharacterHealTest, CharacterCanHealAlly)
{
    reduceHeroBHealth();

    auto f = std::make_shared<Faction>(Faction { "awesome guild" });

    heroA.joinFaction(f);
    heroB.joinFaction(f);

    heroA.applyHealingTo(heroB, 1);

    ASSERT_EQ(heroB.getHealth(), maximum_health);
}
