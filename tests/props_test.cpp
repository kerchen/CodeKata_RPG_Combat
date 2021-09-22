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

// TEST(HeroPropTest, HeroCanNotHealTree)
//{
//     RPGCharacter hero;
//     Prop tree;
//     hero.dealDamageTo(tree, 100.0f);
//     hero.applyHealingTo(tree, 100.0f);
//     ASSERT_LT(tree.getHealth(), tree.getMaximumHealth());
// }

TEST(HeroPropTest, TreeHealthCannotGoNegative)
{
    RPGCharacter hero;
    Prop tree;
    hero.dealDamageTo(tree, 4000.0f);
    ASSERT_EQ(tree.getHealth(), tree.getMinimumHealth());
}
