#pragma once
#include "MovingChar.h"
#include "Direction.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++
class Enemy : public MovingChar {
public:
	Enemy(int x, int y, Sprite shape) : MovingChar(x, y, shape) {}
protected:
    void giftOrDeath(Board&) ;
};
