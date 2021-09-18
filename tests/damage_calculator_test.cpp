#include "damagecalculator.hpp"
#include "rpgcharacter.hpp"
#include <gtest/gtest.h>

TEST(DamageCalculatorTest, SameCharacterReturnsZeroDamage)
{
    RPGCharacter c;
    DamageCalculator dc;
    ASSERT_FLOAT_EQ(dc.getModifiedDamageValue(c, c, 100.0f), 0.0f);
}
