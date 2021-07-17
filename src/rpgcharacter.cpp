#include "rpgcharacter.hpp"

RPGCharacter::RPGCharacter() { }

bool RPGCharacter::isAlive() const { return true; }

std::uint16_t RPGCharacter::getHealth() const { return m_health; }

std::uint8_t RPGCharacter::getLevel() const { return m_level; }

void RPGCharacter::dealDamageTo(RPGCharacter& other_character) const {
    other_character.takeDamage(1);
}

void RPGCharacter::takeDamage(int damage_value) {
    m_health -= damage_value;
}
