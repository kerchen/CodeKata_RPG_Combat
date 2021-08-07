#include <gtest/gtest.h>

#include "constants.hpp"
#include "rpgcharacter.hpp"

using namespace ::testing;

class RPGCharacterInitialValuesTest : public ::testing::Test {
protected:
    RPGCharacter const hero;
};

TEST_F(RPGCharacterInitialValuesTest, characterIsAliveInitially) { ASSERT_TRUE(hero.isAlive()); }

TEST_F(RPGCharacterInitialValuesTest, characterHas1000HealthInitially)
{
    ASSERT_FLOAT_EQ(hero.getHealth(), initial_health);
}

TEST_F(RPGCharacterInitialValuesTest, characterIsLevel1Initially) { ASSERT_EQ(hero.getLevel(), 1); }

TEST_F(RPGCharacterInitialValuesTest, CharacterDoesNotBelongToAnyFaction)
{
    ASSERT_TRUE(hero.getFactions().empty());
}

TEST(RPGCharacterInitialRangeValuesTest, RangeOfMeleeFighterIs2)
{
    RPGCharacter const melee_fighter { initial_health, 1, FighterType::MeleeFighter };
    ASSERT_EQ(melee_fighter.getAttackRange(), 2.0);
}

TEST(RPGCharacterInitialRangeValuesTest, RangeOfRangedFighterIs20)
{
    RPGCharacter const ranged_fighter { initial_health, 1, FighterType::RangedFighter };
    ASSERT_EQ(ranged_fighter.getAttackRange(), 20.0);
}
