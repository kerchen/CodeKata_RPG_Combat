#include "constants.hpp"
#include "faction.hpp"
#include "position.hpp"
#include "rpgcharacter.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ::testing;

class RPGCharacterDealDamageTest : public ::testing::Test {
protected:
    RPGCharacterDealDamageTest() { }
    RPGCharacter const heroA {};
    RPGCharacter heroB {};
};

TEST_F(RPGCharacterDealDamageTest, DealDamageReducesHealthOfTargetCharacter)
{
    heroA.dealDamageTo(heroB);
    ASSERT_LT(heroB.getHealth(), initial_health);
}

TEST_F(RPGCharacterDealDamageTest, DealDamageForHealthZero)
{

    heroA.dealDamageTo(heroB, initial_health);
    ASSERT_EQ(heroB.getHealth(), 0);
}

TEST_F(RPGCharacterDealDamageTest, DealingDamageInExcessOfCurrentHealthResultsInZeroHealth)
{

    heroA.dealDamageTo(heroB, heroB.getHealth() + 1.0f);
    ASSERT_EQ(heroB.getHealth(), 0.0f);
}

TEST_F(RPGCharacterDealDamageTest, DealDamageToKill)
{

    heroA.dealDamageTo(heroB, initial_health);
    ASSERT_EQ(heroB.isAlive(), false);
}

TEST_F(RPGCharacterDealDamageTest, CharacterCantDealDamageToSelf)
{
    heroB.dealDamageTo(heroB, 1.0f);
    ASSERT_EQ(heroB.getHealth(), initial_health);
}

RPGCharacter getMeleeHeroAtLevel(std::uint8_t level)
{
    return RPGCharacter { initial_health, level };
}
RPGCharacter getRangedHeroAtLevel(std::uint8_t level)
{
    return RPGCharacter { initial_health, level, FighterType::RangedFighter };
}

TEST_F(RPGCharacterDealDamageTest, DamageToHighLevelCharacterIsReduced)
{
    heroB = getMeleeHeroAtLevel(100);
    heroA.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), 750.0f);
}

TEST_F(RPGCharacterDealDamageTest, DamageToLowLevelCharacterIsIncreased)
{
    RPGCharacter heroC = getMeleeHeroAtLevel(100);
    heroC.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), 250.0f);
}

TEST_F(RPGCharacterDealDamageTest, DamageToHighLevelCharacterIsReducedWith5LevelsDifference)
{
    heroB = getMeleeHeroAtLevel(6);
    heroA.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), 750.0f);
}

TEST_F(RPGCharacterDealDamageTest, DamageToLowLevelCharacterIsIncreasedWith5LevelsDifference)
{
    RPGCharacter heroC = getMeleeHeroAtLevel(6);
    heroC.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), 250.0f);
}

TEST_F(RPGCharacterDealDamageTest, DamageToHighLevelCharacterIsNotReducedWith4LevelsDifference)
{
    heroB = getMeleeHeroAtLevel(5);
    heroA.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), 500.0f);
}

TEST_F(RPGCharacterDealDamageTest, DamageToLowLevelCharacterIsNotIncreasedWith4LevelsDifference)
{
    RPGCharacter heroC = getMeleeHeroAtLevel(5);
    heroC.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), 500.0f);
}

TEST_F(RPGCharacterDealDamageTest, OutOfRangeMeleeCharacterDoesntDealDamage)
{
    RPGCharacter const heroC = getMeleeHeroAtLevel(1);
    Position const positionHeroB { 15.0 };

    heroB.setPosition(positionHeroB);
    heroC.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), initial_health);
}

TEST_F(RPGCharacterDealDamageTest, OutOfRangeRangedCharacterDoesntDealDamage)
{
    RPGCharacter const heroC = getRangedHeroAtLevel(1);
    Position const positionHeroB { 25.0 };

    heroB.setPosition(positionHeroB);
    heroC.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), initial_health);
}

TEST_F(RPGCharacterDealDamageTest, InRangeRangedCharacterDealsDamage)
{
    RPGCharacter const heroC = getRangedHeroAtLevel(1);
    Position const positionHeroB { 15.0 };

    heroB.setPosition(positionHeroB);
    heroC.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), 500.0f);
}

TEST_F(RPGCharacterDealDamageTest, AlliesCannotDealDamageToEachOther)
{
    RPGCharacter heroC = getRangedHeroAtLevel(1);
    Position const positionHeroB { 15.0 };
    auto f = std::make_shared<Faction>(Faction { "awesome guild" });
    heroB.joinFaction(f);
    heroC.joinFaction(f);

    heroC.dealDamageTo(heroB, 500.0f);
    ASSERT_EQ(heroB.getHealth(), initial_health);
}
