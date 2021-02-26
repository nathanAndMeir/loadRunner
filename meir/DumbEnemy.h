#pragma once
#include "Enemy.h"
#include "Direction.h"

class DumbEnemy :public Enemy {
public:
    DumbEnemy(int x, int y, Sprite shape);
private:
    Direction_t m_direction;
    Direction_t getDirection() override;
    void FailedMove()override;
};
