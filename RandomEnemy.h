#pragma once
#include "Enemy.h"
#include "Direction.h"

class RandomEnemy :public Enemy {
public:
    RandomEnemy(int x, int y, Sprite shape);
    void randDirection();
private:
    Direction_t m_direction;
    int m_counter;
    Direction_t getDirection() override;
    void FailedMove()override;
};
