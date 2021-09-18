#ifndef CODE_KATA_DAMAGECALCULATOR_HPP
#define CODE_KATA_DAMAGECALCULATOR_HPP

class RPGCharacter;

class DamageCalculatorInterface {
public:
    virtual float getModifiedDamageValue(
        RPGCharacter const&, RPGCharacter&, float initial_damage_value)
        = 0;
};

class DamageCalculator : public DamageCalculatorInterface {
public:
    float getModifiedDamageValue(
        RPGCharacter const& attacker, RPGCharacter& defender, float initial_damage_value) override;
};

#endif // CODE_KATA_DAMAGECALCULATOR_HPP
