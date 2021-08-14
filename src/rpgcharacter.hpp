#ifndef CODE_KATA_RPGCHARACTER_HPP
#define CODE_KATA_RPGCHARACTER_HPP

#include "position.hpp"
#include <cstdint>
#include <memory>
#include <set>

struct Faction;

enum FighterType { MeleeFighter, RangedFighter };

class RPGCharacter {
private:
    float m_health { 1000.0f };
    std::uint8_t m_level { 1u };
    FighterType m_fighterType;
    Position m_position;
    std::set<std::shared_ptr<Faction>> m_factions;

    void changeHealth(float health_value);
    void modifyDamage(RPGCharacter& other_character, float& damage_value) const;

    float getMaximumHealth() const;
    float getMinimumHealth() const;

public:
    RPGCharacter(float initial_health = 1000.0f, uint8_t level = 1,
        FighterType fighterType = FighterType::MeleeFighter);
    virtual ~RPGCharacter() = default;

    bool isAlive() const;
    float getHealth() const;
    std::uint8_t getLevel() const;
    void dealDamageTo(RPGCharacter& other_character, float damage_value = 1) const;
    void applyHealingTo(RPGCharacter& other_character, float healing_value = 1) const;
    double getAttackRange() const;
    void setPosition(Position const pos);
    double getDistance(Position const pos) const;
    std::set<std::shared_ptr<Faction>> getFactions() const;
    void joinFaction(std::shared_ptr<Faction> faction);
    void leaveFaction(std::shared_ptr<Faction> faction);
    bool isMemberOfFaction(std::shared_ptr<Faction> faction) const;
    bool isAllyWith(RPGCharacter const& character) const;
};

#endif // CODE_KATA_RPGCHARACTER_HPP
