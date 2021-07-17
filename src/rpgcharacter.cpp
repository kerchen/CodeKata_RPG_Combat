#include "rpgcharacter.hpp"

RPGCharacter::RPGCharacter() { }

bool RPGCharacter::isAlive() const { return true; }

std::uint16_t RPGCharacter::getHealth() const { return m_health; }

std::uint8_t RPGCharacter::getLevel() const { return m_level; }