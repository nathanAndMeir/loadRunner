#include "BadGift.h"
#include "DumbEnemy.h"
#include "RandomEnemy.h"
#include "SmartEnemy.h"

BadGift::BadGift(int x,int y, Sprite shape, Sprite enemyShape)
	:Gift(x,y, shape),m_enemyShape(enemyShape)
{
}

void* BadGift::get() const
{
	int enemytype = rand() % 3;
	switch (enemytype)
	{
	case 0:
		return (void*)new DumbEnemy(0, 0, m_enemyShape);
	case 1:
		return (void*)new RandomEnemy(0, 0, m_enemyShape);
	case 2:
		return (void*)new SmartEnemy(0, 0, m_enemyShape);
	}
	return NULL;
}