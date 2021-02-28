#pragma once
#include "GameCharacter.h"
#include "Direction.h"
#include "Board.h"
//=========================================================

//=========================================================

class MovingChar :public  GameCharacter {
public:
    MovingChar(int x, int y, Sprite shape) : GameCharacter(x, y, shape) {}
    virtual void move(Board&);
protected:
    bool isLegalMove(Direction, Board&) const;
    bool isFall(Board&);
    void moveShape(Direction);
    virtual Direction getDirection() {};
    virtual void giftOrDeath(Board&)  = 0;
    virtual void FailedMove() = 0;

};
