
#include "damagecalculator.hpp"
float DamageCalculator::getModifiedDamageValue(
    RPGCharacter const& attacker, RPGCharacter& defender, float initial_damage_value)
{
    if (&attacker == &defender) {
        return 0.0f;
    }
}
