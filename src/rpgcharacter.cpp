#include "rpgcharacter.hpp"
#include "faction.hpp"
#include <algorithm>
#include <map>
#include <vector>

RPGCharacter::RPGCharacter(float initial_health, uint8_t level, FighterType fighterType)
    : m_health { initial_health }
    , m_level { level }
    , m_fighterType { fighterType }
{
}

bool RPGCharacter::isAlive() const { return m_health > 0; }

float RPGCharacter::getHealth() const { return m_health; }

std::uint8_t RPGCharacter::getLevel() const { return m_level; }

void RPGCharacter::calcDamage(RPGCharacter& other_character, float& damage_value) const
{

    auto const myLevel = static_cast<int>(getLevel());
    auto const otherLevel = static_cast<int>(other_character.getLevel());

    int level_difference = myLevel - otherLevel;

    if (level_difference <= -5) {
        damage_value *= 0.5f;
    }
    if (level_difference >= 5) {

        damage_value *= 1.5f;
    }
}

void RPGCharacter::dealDamageTo(RPGCharacter& other_character, float damage_value) const
{
    if (&other_character == this) {
        return;
    }

    if (other_character.getDistance(m_position) > getAttackRange()) {
        return;
    }

    calcDamage(other_character, damage_value);

    other_character.changeHealth(-damage_value);
}

void RPGCharacter::changeHealth(float health_value)
{
    auto const newHealth = health_value + m_health;
    if (newHealth > 1000.0f) {
        m_health = 1000.0f;
    } else if (newHealth < 0.0f) {
        m_health = 0.0f;
    } else {
        m_health = newHealth;
    }
}

void RPGCharacter::applyHealingTo(RPGCharacter& other_character, float healing_value) const
{
    if (&other_character != this) {
        return;
    }

    if (other_character.isAlive()) {
        other_character.changeHealth(healing_value);
    }
}
double RPGCharacter::getAttackRange() const
{
    std::map<FighterType, double> attack_range_lookpu { { FighterType::MeleeFighter, 2.0 },
        { FighterType::RangedFighter, 20.0 } };
    return attack_range_lookpu[m_fighterType];
}

void RPGCharacter::setPosition(Position const pos) { m_position = pos; }

double RPGCharacter::getDistance(Position const pos) { return m_position.getDistance(pos); }

std::set<std::shared_ptr<Faction>> RPGCharacter::getFactions() const { return m_factions; }

void RPGCharacter::joinFaction(std::shared_ptr<Faction> faction) { m_factions.insert(faction); }

void RPGCharacter::leaveFaction(std::shared_ptr<Faction> faction) { m_factions.erase(faction); }

bool RPGCharacter::isMemberOfFaction(std::shared_ptr<Faction> faction)
{
    return std::count(m_factions.begin(), m_factions.end(), faction) == 1;
}
