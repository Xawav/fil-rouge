#ifndef PHYSICAL_ENTITY
#define PHYSICAL_ENTITY
#include "strategy.h"
#include <vector>
#include <SFML/Graphics/Transformable.hpp>

class Hitbox{};

class PhysicalEntity : public sf::Transformable, public Strategy 
{
/*Maybe the most important strategy
PhysicalEntity (or later simply "Physical" ? "Physicable" ?) has to describe physical caracteristics of his entity:
mass, touchable, (not invisible --> in Drawable), elasticity (wait ?), forceSensible (if he is or isn't sensible to some)..

Maybe we would like to store damage hitboxes in here instead of Character, 
or damageHitbox != physicalHitbox (like i can touch with my legs) but they can't take damages
*/
private:
    //position, rotation etc in the parent class Transformable

    Hitbox physicalHitbox; // boolean solid (or touchable ?) in here

    double mass; //mass > 0
    signed short gravityReaction; //-1 if the PhysicalEntity is likely to fly
    double bouncyness; // [0,1] absorb every momentum (0) or none (1), maybe it will increase it's internal energy ( to satisfy conservation of energy)
    double internalEnergy; //for characters that can absorb energy and then liberate it ?
    double electricCharge; //mdr

public:
    static void
    correction(std::vector<PhysicalEntity> phxEtts, std::vector<std::vector<double, double>> correctionMatrix);



    //setPosition already handle in parent class Transformable: Google "sfml Transformable"

    /*
    the Physic toolbox will access position and then update position of every Entity
    with this strategy, these functions aren't implemented here

    only get and set positions are needed
    */

    PhysicalEntity(/* args */);

    ~PhysicalEntity();

    //getters and setters ...
    void setMass(double _mass);

    double getMass();

    void setHitbox(Hitbox &_Hitbox); //with stored reference...
    Hitbox getHitbox();

    void setGravityReaction(signed short _gravityReaction);

    signed short getGravityReaction();

    void setBouncyness(double _bouncyness);

    double getBouncyness();

    void setInternalEnergy(double _internalEnergy);

    double getInternalEnergy();

    void setElectricCharge(double eC);

    double getElectricCharge();

};




#endif