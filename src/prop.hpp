#ifndef CODE_KATA_PROP_HPP
#define CODE_KATA_PROP_HPP

#include "healthchangereceptor.hpp"
#include "position.hpp"
#include <cstdint>

class Prop : public HealthChangeReceptor {
private:
    float m_health { getMaximumHealth() };

public:
    float getMinimumHealth() const;
    float getMaximumHealth() const override;
    float getHealth() const override;
    bool isAlive() const override;
    void changeHealth(float health_value) override;
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
