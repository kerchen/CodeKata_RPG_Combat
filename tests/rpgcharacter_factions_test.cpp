#include "faction.hpp"
#include "rpgcharacter.hpp"
#include <gtest/gtest.h>
#include <memory>

TEST(RPGCharacterFactionTest, HeroCanJoinFaction)
{
    RPGCharacter hero {};
    auto f = std::make_shared<Faction>(Faction { "awesome guild" });
    hero.joinFaction(f);

    ASSERT_TRUE(hero.isMemberOfFaction(f));
}

TEST(RPGCharacterFactionTest, HeroCanLeaveFaction)
{
    RPGCharacter hero {};
    auto f = std::make_shared<Faction>(Faction { "awesome guild" });
    hero.joinFaction(f);
    hero.leaveFaction(f);

    ASSERT_FALSE(hero.isMemberOfFaction(f));
}

TEST(RPGCharacterFactionTest, HeroCannotJoinSameFactionMultipleTimes)
{
    RPGCharacter hero {};
    auto f = std::make_shared<Faction>(Faction { "awesome guild" });
    hero.joinFaction(f);
    hero.joinFaction(f);
    hero.leaveFaction(f);

    ASSERT_FALSE(hero.isMemberOfFaction(f));
}
