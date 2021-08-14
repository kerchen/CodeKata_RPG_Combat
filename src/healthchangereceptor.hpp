#ifndef CODE_KATA_HEALTHCHANGERECEPTOR_HPP
#define CODE_KATA_HEALTHCHANGERECEPTOR_HPP

#include "faction.hpp"
#include "position.hpp"
#include <cstdint>
#include <memory>
#include <set>

class HealthChangeReceptor {
public:
    virtual float getMaximumHealth() const = 0;
    virtual float getHealth() const = 0;
    virtual void changeHealth(float health_value) = 0;
    virtual bool isAlive() const = 0;

    virtual double getDistance(Position const pos) const = 0;

    virtual std::set<std::shared_ptr<Faction>> getFactions() const = 0;
    virtual bool isAllyWith(HealthChangeReceptor const* character) const = 0;
    virtual void modifyDamage(
        HealthChangeReceptor const* other_character, float& damage_value) const = 0;
    virtual std::uint8_t getLevel() const = 0;
};

#endif // CODE_KATA_HEALTHCHANGERECEPTOR_HPP
