#ifndef CODE_KATA_RPGCHARACTER_HPP
#define CODE_KATA_RPGCHARACTER_HPP

#include <cstdint>

class RPGCharacter {
private:
    int m_health { 1000 };
    std::uint8_t m_level { 1u };

    void takeDamage(int damage_value);

public:
    RPGCharacter();
    virtual ~RPGCharacter() = default;

    bool isAlive() const;
    std::uint16_t getHealth() const;
    std::uint8_t getLevel() const;
    void dealDamageTo(RPGCharacter& other_character, int damage_value = 1) const;

};

#endif // CODE_KATA_RPGCHARACTER_HPP
