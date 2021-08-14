#ifndef CODE_KATA_PROP_HPP
#define CODE_KATA_PROP_HPP

#include "healthchangereceptor.hpp"
#include "position.hpp"

class Prop : public HealthChangeReceptor {
private:
    float m_health { getMaximumHealth() };

public:
    float getMinimumHealth() const;
    float getMaximumHealth() const ;
    float getHealth() const ;
    void changeHealth(float health_value) override;
};

#endif // CODE_KATA_PROP_HPP
