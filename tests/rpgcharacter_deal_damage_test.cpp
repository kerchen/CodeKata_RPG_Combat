#include <gtest/gtest.h>

#include "rpgcharacter.hpp"

using namespace ::testing;

class RPGCharacterDealDamageTest : public ::testing::Test {
protected:
    RPGCharacter const heroA;
    RPGCharacter heroB;
};


TEST_F(RPGCharacterDealDamageTest, DealDamageReducesHealthOfTargetCharacter) {
    heroA.dealDamageTo(heroB);
    ASSERT_LT(heroB.getHealth(), 1000);
}
