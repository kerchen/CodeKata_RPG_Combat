#ifndef CODE_KATA_RPGCHARACTER_HPP
#define CODE_KATA_RPGCHARACTER_HPP

class RPGCharacter
{
public:
    RPGCharacter();
    virtual ~RPGCharacter() = default;

    bool isAlive();
};
#endif // CODE_KATA_RPGCHARACTER_HPP
