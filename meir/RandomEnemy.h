#pragma once
#include "Enemy.h"
#include "Direction.h"
//++++++++++++++++++++++++++++++++++++++++
class RandomEnemy :public Enemy {
public:
    RandomEnemy(int x, int y, Sprite shape);
private:
    Direction m_direction;
    int m_counter;
//+++++++++++++++++++++++++++++++
    void randDirection();
    Direction getDirection() override;
    void FailedMove()override;
};
