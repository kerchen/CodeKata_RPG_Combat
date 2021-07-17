#include <gtest/gtest.h>

#include "rpgcharacter.hpp"
#include "constants.hpp"

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
