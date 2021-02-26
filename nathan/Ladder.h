#pragma once
#include "StaticChar.h"
class Ladder :public StaticChar {
public:
	Ladder(int x, int y, Sprite shape) :StaticChar(x, y, shape) {}
};