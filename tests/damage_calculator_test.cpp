#include "damagecalculator.hpp"
#include "faction.hpp"
#include "prop.hpp"
#include "rpgcharacter.hpp"
#include <gtest/gtest.h>

TEST(DamageCalculatorTest, SameCharacterReturnsZeroDamage)
{
    RPGCharacter c;
    DamageCalculator const dc;
    ASSERT_FLOAT_EQ(dc.getResultingDamage(c, c, 100.0f), 0.0f);
}

TEST(DamageCalculatorTest, DefenderOutOfRangeReturnsZeroDamage)
{
    RPGCharacter attacker;
    RPGCharacter defender;
    defender.setPosition(Position { 1000.0f });

    DamageCalculator const dc;

    ASSERT_FLOAT_EQ(dc.getResultingDamage(attacker, defender, 100.0f), 0.0f);
}

TEST(DamageCalculatorTest, AllyDefenderReturnsZeroDamage)
{
    auto f = std::make_shared<Faction>();

    RPGCharacter attacker;
    attacker.joinFaction(f);
    RPGCharacter defender;
    defender.joinFaction(f);

    DamageCalculator const dc;

    ASSERT_FLOAT_EQ(dc.getResultingDamage(attacker, defender, 100.0f), 0.0f);
}

TEST(DamageCalculatorTest, DamageIsUnmodified)
{
    DamageCalculator const dc;

    auto const unmodified_damage = 1000.0f;
    auto const modified_damage = dc.modifyDamage(5, 5, unmodified_damage);

    ASSERT_FLOAT_EQ(unmodified_damage, modified_damage);
}

TEST(DamageCalculatorTest, DamageIsModifiedUp)
{
    DamageCalculator const dc;

    auto const unmodified_damage = 1000.0f;
    auto const modified_damage = dc.modifyDamage(15, 5, unmodified_damage);

    ASSERT_GT(modified_damage, unmodified_damage);
}

TEST(DamageCalculatorTest, DamageIsModifiedDown)
{
    DamageCalculator const dc;

    auto const unmodified_damage = 1000.0f;
    auto const modified_damage = dc.modifyDamage(5, 15, unmodified_damage);

    ASSERT_LT(modified_damage, unmodified_damage);
}

TEST(DamageCalculatorTest, ResultingDamageForPropIsUnmodified)
{
    RPGCharacter attacker;
    Prop tree;
    DamageCalculator const dc;

    ASSERT_FLOAT_EQ(dc.getResultingDamage(attacker, tree, 100.0f), 100.0f);
}
