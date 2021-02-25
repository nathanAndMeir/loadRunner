#pragma once
#include "MovingChar.h"
#include "Direction.h"

class Enemy : public MovingChar {
public:
	Enemy(int x, int y, Sprite shape) : MovingChar(x, y, shape) {}
	void giftOrDeath(Board&) ;
	virtual ~Enemy() = 0 {}
private:
};
