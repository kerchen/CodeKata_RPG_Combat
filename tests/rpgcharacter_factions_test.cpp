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

TEST(RPGCharacterFactionTest, HerosInSameFactionAreAllies)
{
    RPGCharacter heroA {};
    RPGCharacter heroB {};
    auto f = std::make_shared<Faction>(Faction { "awesome guild" });

    heroA.joinFaction(f);
    heroB.joinFaction(f);

    ASSERT_TRUE(heroA.isAllyWith(heroB));
}

TEST(RPGCharacterFactionTest, HerosNotInSameFactionsAreNotAllies)
{
    RPGCharacter heroA {};
    RPGCharacter heroB {};
    auto f1 = std::make_shared<Faction>(Faction { "Peoples' Front of Judea" });
    auto f2 = std::make_shared<Faction>(Faction { "Judean Peoples' Front" });

    heroA.joinFaction(f1);
    heroB.joinFaction(f2);

    ASSERT_FALSE(heroA.isAllyWith(heroB));
}
