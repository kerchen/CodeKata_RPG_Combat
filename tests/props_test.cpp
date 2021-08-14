#include "prop.hpp"
#include "rpgcharacter.hpp"
#include <gtest/gtest.h>

TEST(HeroPropTest, HeroCanDamageTree)
{
    RPGCharacter hero;
    Prop tree;
    hero.dealDamageTo(tree, 10.0f);
    ASSERT_LT(tree.getHealth(), tree.getMaximumHealth());
}
