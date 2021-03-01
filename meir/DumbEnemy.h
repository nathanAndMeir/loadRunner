#pragma once
#include "Enemy.h"
#include "Direction.h"
//++++++++++++++++++++++++++++++++++++++++++++
class DumbEnemy :public Enemy {
public:
    DumbEnemy(int x, int y, Sprite shape);
private:
    Direction m_direction;
//++++++++++++++++++++++
    Direction getDirection() override ;
    void FailedMove()override;
};
