#include <gtest/gtest.h>

#include "rpgcharacter.hpp"

using namespace ::testing;

TEST(CharacterTest, characterIsAliveInitially)
{
    RPGCharacter const hero;

    ASSERT_TRUE(hero.isAlive());
}

TEST(CharacterTest, characterHas1000HealthInitially)
{
    RPGCharacter const hero;

    ASSERT_EQ(hero.getHealth(), 1000);
}

TEST(CharacterTest, characterIsLevel1Initially)
{
    RPGCharacter const hero;

    ASSERT_EQ(hero.getLevel(), 1);
}
