#pragma once
#include "Enemy.h"

enum PlayerDirect_t { UP_RIGHT, UP_LEFT, DWON_RIGHT, DWON_LEFT };




class SmartEnemy :public Enemy {
public:
    SmartEnemy(int x, int y, Sprite shape) : Enemy(x, y, shape) {}
    void move(Board&)override;
private:
    Direction_t smartDirection(Board& board);
    PlayerDirect_t directionToPlayer(Board&);
    Direction_t findLegalDirection(Direction_t, Direction_t, Direction_t, Direction_t, Board& board);
    void FailedMove() override {}// do nothing
};
