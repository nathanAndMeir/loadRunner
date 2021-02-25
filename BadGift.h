#pragma once
#include "Gift.h"
class RandomEnemy;
class DumbEnemy;
class SmartEnemy;


class BadGift :public Gift {
public:
	//build the shape using StaticChar C-tor and in addition set the shape of enmy because
	//it will return enemy
	BadGift(int, int, Sprite, Sprite);

	//return some kind of enemy
	//choosing one of three randomly
	void* get() const;
private:
	//the shape of the enemy
	Sprite m_enemyShape;
};