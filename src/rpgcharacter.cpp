#include "rpgcharacter.hpp"

RPGCharacter::RPGCharacter() { }

bool RPGCharacter::isAlive() const { 
    return m_health > 0; 
}

std::uint16_t RPGCharacter::getHealth() const { return m_health; }

std::uint8_t RPGCharacter::getLevel() const { return m_level; }

void RPGCharacter::dealDamageTo(RPGCharacter& other_character , int damage_value) const {
    other_character.takeDamage(damage_value);
}

void RPGCharacter::takeDamage(int damage_value) {
    m_health -= damage_value;
}
