#pragma once
#include "StaticChar.h"
class Gift :public StaticChar {
public:
	Gift(int x, int y, Sprite shape) :StaticChar(x, y, shape) {}
	virtual void* get() const= 0;
};