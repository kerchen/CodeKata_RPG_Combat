#include "prop.hpp"

float Prop::getMinimumHealth() const { return 0.0f; }
float Prop::getMaximumHealth() const { return 2000.0f; }

float Prop::getHealth() const { return m_health; }

void Prop::changeHealth(float deltaHealth)
{
    m_health += deltaHealth;

    if (m_health < getMinimumHealth()) {
        m_health = getMinimumHealth();
    }
}

bool Prop::isAlive() const { return m_health > getMinimumHealth(); }