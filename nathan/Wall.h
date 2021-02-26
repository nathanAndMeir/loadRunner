#pragma once
#include "StaticChar.h"
class Wall :public StaticChar {
public:
	Wall(int x, int y, Sprite shape) :StaticChar(x, y, shape) {}
};