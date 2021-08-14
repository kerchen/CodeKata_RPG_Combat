#ifndef CODE_KATA_PROP_HPP
#define CODE_KATA_PROP_HPP

#include "healthchangereceptor.hpp"
#include "position.hpp"
#include <cstdint>

class Prop : public HealthChangeReceptor {
public:
    float getMaximumHealth() const override { return 0; }
    float getHealth() const override { return 0; }
    void changeHealth(float health_value) override { }
    double getDistance(const Position pos) const override { return 0; }
    bool isAllyWith(const HealthChangeReceptor* character) const override { return false; }
    void modifyDamage(
        const HealthChangeReceptor* other_character, float& damage_value) const override
    {
    }
    std::set<std::shared_ptr<Faction>> getFactions() const override
    {
        return std::set<std::shared_ptr<Faction>>();
    }
    uint8_t getLevel() const override { return 0; }
};

#endif // CODE_KATA_PROP_HPP
