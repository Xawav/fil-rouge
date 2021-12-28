#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.h"
#include <vector>

class Hitbox {
};


class Character : public Entity {
private:

    std::vector<Hitbox> attackHitbox; //in a strategy ?
    Hitbox damageHitbox;  //-->> in the future stored in strategies ???

    float strength;
    float maxSpeed;
    float jumpHeight;

public:
    const std::vector<Hitbox> &getAttackHitbox() const;

    void setAttackHitbox(const std::vector<Hitbox> &attackHitbox);

    const Hitbox &getDamageHitbox() const;

    void setDamageHitbox(const Hitbox &damageHitbox);

    float getStrength() const;

    void setStrength(float strength);

    float getMaxSpeed() const;

    void setMaxSpeed(float maxSpeed);

    float getJumpHeight() const;

    void setJumpHeight(float jumpHeight);


public:

    /*  Character(std::vector<Strategy*> strategies); //or every player has the same strategies ? to be discussed...
      */ //useless ?... Inheritance ?
    ~Character();

};

#endif