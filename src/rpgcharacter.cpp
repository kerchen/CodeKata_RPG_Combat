#include "rpgcharacter.hpp"

RPGCharacter::RPGCharacter() { }

bool RPGCharacter::isAlive() const { 
    return m_health > 0; 
}

std::uint16_t RPGCharacter::getHealth() const { return m_health; }

std::uint8_t RPGCharacter::getLevel() const { return m_level; }

void RPGCharacter::dealDamageTo(RPGCharacter& other_character , int damage_value) const {
    other_character.changeHealth(-damage_value);
}

void RPGCharacter::changeHealth(int health_value) {
    if (health_value + m_health > 1000) {
        m_health = 1000;
    } else if (health_value + m_health < 0) {
        m_health = 0;
    } else {
        m_health += health_value;
    }
}

void RPGCharacter::applyHealingTo(RPGCharacter& other_character, int healing_value) const
{
    if (other_character.isAlive()) {
        other_character.changeHealth(healing_value);
    }
}

