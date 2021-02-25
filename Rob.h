#pragma once
#include "StaticChar.h"
class Rob :public StaticChar {
public:
	Rob(int x, int y, Sprite shape) : StaticChar(x, y, shape) {}
};