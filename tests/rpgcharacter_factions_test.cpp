#include "faction.hpp"
#include "rpgcharacter.hpp"
#include <algorithm>
#include <gtest/gtest.h>
#include <memory>

TEST(RPGCharacterFactionTest, HeroCanJoinFaction)
{
    RPGCharacter hero {};
    auto f = std::make_shared<Faction>(Faction { "awesome guild" });
    hero.joinFaction(f);

    auto const factions = hero.getFactions();
    ASSERT_EQ(std::count(factions.begin(), factions.end(), f), 1);
}
