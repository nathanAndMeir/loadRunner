#pragma once
#include "Gift.h"
class LifeGift :public Gift {
public:
	LifeGift(int x, int y, Sprite shape) :Gift(x, y, shape) {}
	void* get()const { return (void*)&m_life; }
private:
	int m_life = 1;
};