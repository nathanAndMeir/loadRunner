#pragma once
#include "Gift.h"
class PointsGift :public Gift {
public:
	PointsGift(int x, int y, Sprite shape) :Gift(x, y, shape) {}
	void* get() const  {return (void*)&m_points;}
private:
	int m_points = 20;
};