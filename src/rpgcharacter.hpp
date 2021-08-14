#ifndef CODE_KATA_RPGCHARACTER_HPP
#define CODE_KATA_RPGCHARACTER_HPP

#include "healthchangereceptor.hpp"
#include "position.hpp"
#include <cstdint>
#include <memory>
#include <set>

struct Faction;

enum FighterType { MeleeFighter, RangedFighter };

class RPGCharacter : public HealthChangeReceptor {
private:
    float m_health { 1000.0f };
    std::uint8_t m_level { 1u };
    FighterType m_fighterType;
    Position m_position;
    std::set<std::shared_ptr<Faction>> m_factions;

    void changeHealth(float health_value) override;

    void modifyDamage(
        HealthChangeReceptor const* other_character, float& damage_value) const override;

    float getMaximumHealth() const override;
    float getMinimumHealth() const;

public:
    RPGCharacter(float initial_health = 1000.0f, uint8_t level = 1,
        FighterType fighterType = FighterType::MeleeFighter);
    virtual ~RPGCharacter() = default;

    bool isAlive() const override;
    float getHealth() const override;
    std::uint8_t getLevel() const override;
    void dealDamageTo(HealthChangeReceptor& other_character, float damage_value = 1) const;
    void applyHealingTo(HealthChangeReceptor& other_character, float healing_value = 1) const;
    double getAttackRange() const;
    void setPosition(Position const pos);
    double getDistance(Position const pos) const;
    void joinFaction(std::shared_ptr<Faction> faction);
    void leaveFaction(std::shared_ptr<Faction> faction);
    bool isMemberOfFaction(std::shared_ptr<Faction> faction) const;
    bool isAllyWith(HealthChangeReceptor const* character) const override;
    std::set<std::shared_ptr<Faction>> getFactions() const override { return m_factions; }
};

#endif // CODE_KATA_RPGCHARACTER_HPP
