#include "rpgcharacter.hpp"
#include "faction.hpp"
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>

RPGCharacter::RPGCharacter(float initial_health, uint8_t level, FighterType fighterType)
    : m_health { initial_health }
    , m_level { level }
    , m_fighterType { fighterType }
{
}

bool RPGCharacter::isAlive() const { return m_health > getMinimumHealth(); }

float RPGCharacter::getHealth() const { return m_health; }

std::uint8_t RPGCharacter::getLevel() const { return m_level; }

void RPGCharacter::modifyDamage(
    HealthChangeReceptor const* other_character, float& damage_value) const
{
    auto const myLevel = static_cast<int>(getLevel());
    auto const otherLevel = static_cast<int>(other_character->getLevel());

    int level_difference = myLevel - otherLevel;

    if (level_difference <= -5) {
        damage_value *= 1.5f;
    }
    if (level_difference >= 5) {
        damage_value *= 0.5f;
    }
}

void RPGCharacter::dealDamageTo(HealthChangeReceptor& recipient, float damage_value) const
{
    if (&recipient == this) {
        return;
    }

    if (recipient.getDistance(m_position) > getAttackRange()) {
        return;
    }
    if (recipient.isAllyWith(this)) {
        return;
    }

    recipient.modifyDamage(this, damage_value);

    recipient.changeHealth(-damage_value);
}

void RPGCharacter::changeHealth(float health_value)
{
    auto const newHealth = health_value + m_health;
    if (newHealth > getMaximumHealth()) {
        m_health = getMaximumHealth();
    } else {
        if (newHealth < getMinimumHealth()) {
            m_health = getMinimumHealth();
        } else {
            m_health = newHealth;
        }
    }
}

float RPGCharacter::getMinimumHealth() const { return 0.0f; }
float RPGCharacter::getMaximumHealth() const { return 1000.0f; }

void RPGCharacter::applyHealingTo(HealthChangeReceptor& other_character, float healing_value) const
{
    bool trying_to_heal_self = &other_character == this;
    bool trying_to_heal_ally = other_character.isAllyWith(this);

    if (!trying_to_heal_self && !trying_to_heal_ally) {
        return;
    }

    if (other_character.isAlive()) {
        other_character.changeHealth(healing_value);
    }
}
double RPGCharacter::getAttackRange() const
{
    std::map<FighterType, double> attack_range_lookup { { FighterType::MeleeFighter, 2.0 },
        { FighterType::RangedFighter, 20.0 } };
    return attack_range_lookup[m_fighterType];
}

void RPGCharacter::setPosition(Position const pos) { m_position = pos; }

double RPGCharacter::getDistance(Position const pos) const { return m_position.getDistance(pos); }

void RPGCharacter::joinFaction(std::shared_ptr<Faction> faction) { m_factions.insert(faction); }

void RPGCharacter::leaveFaction(std::shared_ptr<Faction> faction) { m_factions.erase(faction); }

bool RPGCharacter::isMemberOfFaction(std::shared_ptr<Faction> faction) const
{
    return std::count(m_factions.begin(), m_factions.end(), faction) == 1;
}

bool RPGCharacter::isAllyWith(HealthChangeReceptor const* character) const
{
    std::vector<std::shared_ptr<Faction>> intersection;

    std::set<std::shared_ptr<Faction>> factions(character->getFactions());
    std::set_intersection(m_factions.begin(), m_factions.end(), factions.begin(), factions.end(),
        std::back_inserter(intersection));

    return !intersection.empty();
}
