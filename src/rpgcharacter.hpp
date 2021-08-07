#ifndef CODE_KATA_RPGCHARACTER_HPP
#define CODE_KATA_RPGCHARACTER_HPP

#include <cstdint>

enum FighterType {
        MeleeFighter,
        RangedFighter
};

class RPGCharacter {
private:
    float m_health { 1000.0f };
    std::uint8_t m_level { 1u };

    void changeHealth(float health_value);
    void calcDamage(RPGCharacter& other_character, float& damage_value) const;

public:
    RPGCharacter(float initial_health = 1000.0f, uint8_t level = 1,
        FighterType fighterType = FighterType::MeleeFighter);
    virtual ~RPGCharacter() = default;

    bool isAlive() const;
    float getHealth() const;
    std::uint8_t getLevel() const;
    void dealDamageTo(RPGCharacter& other_character, float damage_value = 1) const;
    void applyHealingTo(RPGCharacter& other_character, float healing_value = 1) const;
    double getAttackRange () const;
    FighterType m_fighterType;
};

#endif // CODE_KATA_RPGCHARACTER_HPP
