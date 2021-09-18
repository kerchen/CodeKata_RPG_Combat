#ifndef CODE_KATA_DAMAGECALCULATOR_HPP
#define CODE_KATA_DAMAGECALCULATOR_HPP

#include <cstdint>

class RPGCharacter;

class DamageCalculatorInterface {
public:
    virtual float getModifiedDamageValue(
        RPGCharacter const&, RPGCharacter&, float initial_damage_value) const = 0;
};

class DamageCalculator : public DamageCalculatorInterface {
public:
    float modifyDamage(std::uint8_t const attacker_level, std::uint8_t const defender_level,
        float initial_damage_value) const;

    float getModifiedDamageValue(RPGCharacter const& attacker, RPGCharacter& defender,
        float initial_damage_value) const override;
};

#endif // CODE_KATA_DAMAGECALCULATOR_HPP
