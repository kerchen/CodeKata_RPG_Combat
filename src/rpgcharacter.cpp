#include "rpgcharacter.hpp"
#include <iostream>

RPGCharacter::RPGCharacter(float initial_health, std::uint8_t level):
m_health {initial_health}, m_level{level}
{ }

bool RPGCharacter::isAlive() const { return m_health > 0; }

float RPGCharacter::getHealth() const { return m_health; }

std::uint8_t RPGCharacter::getLevel() const { return m_level; }

void RPGCharacter::calcDamage(RPGCharacter& other_character, float& damage_value) const{
    
    auto const myLevel = static_cast<int>(getLevel());
    auto const otherLevel = static_cast<int>(other_character.getLevel());


    int level_difference = myLevel - otherLevel;

    if ( level_difference <= -5 )
    {
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

    calcDamage(other_character , damage_value);

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
