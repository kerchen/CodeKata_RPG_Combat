#ifndef CODE_KATA_RPGCHARACTER_HPP
#define CODE_KATA_RPGCHARACTER_HPP

#include "damagecalculator.hpp"
#include "healthchangereceptor.hpp"
#include "position.hpp"
#include <cstdint>
#include <memory>
#include <set>

struct Faction;
class Prop;

enum FighterType { MeleeFighter, RangedFighter };

class RPGCharacter : public HealthChangeReceptor {
private:
    float m_health { 1000.0f };
    std::uint8_t m_level { 1u };
    FighterType m_fighterType;
    Position m_position;
    std::set<std::shared_ptr<Faction>> m_factions;
    std::shared_ptr<DamageCalculatorInterface> m_damageCalculator;

    void changeHealth(float health_value) override;

    float getMaximumHealth() const;
    float getMinimumHealth() const;

public:
    RPGCharacter(float initial_health = 1000.0f, uint8_t level = 1,
        FighterType fighterType = FighterType::MeleeFighter,
        std::shared_ptr<DamageCalculatorInterface> damage_calculator = nullptr);
    virtual ~RPGCharacter() = default;

    bool isAlive() const;
    float getHealth() const;
    std::uint8_t getLevel() const;

    template <class DefenderT>
    void dealDamageTo(DefenderT& recipient, float damage_value = 1) const
    {
        recipient.changeHealth(
            -m_damageCalculator->getResultingDamage(*this, recipient, damage_value));
    }

    void applyHealingTo(RPGCharacter& other_character, float healing_value = 1) const;
    double getAttackRange() const;
    Position getPosition() const;
    void setPosition(Position const pos);
    double getDistance(Position const pos) const;
    void joinFaction(std::shared_ptr<Faction> faction);
    void leaveFaction(std::shared_ptr<Faction> faction);
    bool isMemberOfFaction(std::shared_ptr<Faction> faction) const;
    bool isAllyWith(RPGCharacter const* character) const;
    std::set<std::shared_ptr<Faction>> getFactions() const { return m_factions; }
};

#endif // CODE_KATA_RPGCHARACTER_HPP
