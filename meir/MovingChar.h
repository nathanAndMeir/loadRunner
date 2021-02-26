#pragma once
#include "GameCharacter.h"
#include "Direction.h"
#include "Board.h"
//=========================================================

//=========================================================

class MovingChar :public  GameCharacter {
public:
    MovingChar(int x, int y, Sprite shape) : GameCharacter(x, y, shape) {}
    bool isLegalMove(Direction_t, Board&) const;
    bool isFall(Board&);
    virtual void move(Board&);
    void moveShape(Direction_t);
    virtual Direction_t getDirection() { return UP_D; }
    virtual void giftOrDeath(Board&)  = 0;
    virtual void FailedMove() = 0;

};
