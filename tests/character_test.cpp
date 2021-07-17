#include <gtest/gtest.h>

#include "rpgcharacter.hpp"

using namespace ::testing;

TEST(CharacterTest, characterIsAliveInitially)
{
    RPGCharacter hero;

    ASSERT_TRUE(hero.isAlive());
}
