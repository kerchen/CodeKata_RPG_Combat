#include "damagecalculator.hpp"
#include "prop.hpp"
#include "rpgcharacter.hpp"

float DamageCalculator::modifyDamage(std::uint8_t const attacker_level,
    std::uint8_t const defender_level, float initial_damage_value) const
{
    int level_difference = defender_level - attacker_level;

    if (level_difference <= -5) {
        initial_damage_value *= 1.5f;
    }

    if (level_difference >= 5) {
        initial_damage_value *= 0.5f;
    }

    return initial_damage_value;
}

float DamageCalculator::getResultingDamage(
    RPGCharacter const& attacker, const RPGCharacter& defender, float initial_damage_value) const
{
    if (&attacker == &defender) {
        return 0.0f;
    }

    if (attacker.getDistance(defender.getPosition()) > attacker.getAttackRange()) {
        return 0.0f;
    }

    if (defender.isAllyWith(&attacker)) {
        return 0.0f;
    }

    return modifyDamage(attacker.getLevel(), defender.getLevel(), initial_damage_value);
}

float DamageCalculator::getResultingDamage(
    RPGCharacter const& attacker, Prop const& defender, float initial_damage_value) const
{
    return initial_damage_value;
}
