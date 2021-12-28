#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "strategy.h"
#include <vector>

class Damageable {
private:
    float maxLife;
    float currentLife;
public:
    static void damage(std::vector<Damageable> damageableArray, std::vector<std::vector<double, double>> damageMatrix);

    void setMaxLife(float &_maxLife);

    float getMaxLife();

    void setCurrentLife(float &_currentLife);

    float getCurrentLife();


    Damageable(/* args */);

    ~Damageable();
};


#endif