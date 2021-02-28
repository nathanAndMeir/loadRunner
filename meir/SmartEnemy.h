#pragma once
#include "Enemy.h"

enum PlayerDirect { UP_RIGHT, UP_LEFT, DWON_RIGHT, DWON_LEFT };

class SmartEnemy :public Enemy {
public:
    SmartEnemy(int x, int y, Sprite shape) : Enemy(x, y, shape) {}
    void move(Board&)override;
private:
    Direction smartDirection(Board& board);
    PlayerDirect directionToPlayer(Board&);
    Direction findLegalDirection(Direction, Direction, Direction, Direction, Board& board);
    void FailedMove() override {}// do nothing
};
