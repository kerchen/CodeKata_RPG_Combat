#include "prop.hpp"

float Prop::getMaximumHealth() const { return 2000.0f; }

float Prop::getHealth() const { return m_health; }

void Prop::changeHealth(float deltaHealth) { m_health += deltaHealth; }