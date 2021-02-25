#pragma once
#include "GameCharacter.h"

class StaticChar:public GameCharacter {
public:
	StaticChar(int x, int y, Sprite shape) :GameCharacter(x, y, shape) {}
	//virtual ~StaticChar() = 0 {}
};
