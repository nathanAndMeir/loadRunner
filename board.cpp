#include "Board.h"
#include "DumbEnemy.h"
#include "RandomEnemy.h"
#include "SmartEnemy.h"
#include "Player.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Board::setBoard(ifstream& fileStream, int n)
{
	auto line = std::string();
	for (int i = 0;i < n;i++)
	{
		std::getline(fileStream, line);
		m_charBoard.push_back(line);
	}
	setStartData();
}
//==============================================================
void Board::setStartData()
{
	for (int i = 0;size_t(i) < m_charBoard.size();i++)
		for (int j = 0;j < m_charBoard[i].size();j++)
			setOneObject(i, j);
	m_playerDead = false;
	m_boardSize.x = m_charBoard.size() * SHAPE_SIZE;
	m_boardSize.y = m_charBoard.size() * SHAPE_SIZE;
}
//==============================================================
void Board::setOneObject(int row, int col)
{
	int x = col, y = row;
	switch (m_charBoard[row][col])
	{
	case WALL:
		m_walls.push_back(Wall(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_wall)));
		break;
	case LADDER:
		m_ladders.push_back(Ladder(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_ladder)));
		break;
	case ROB:
		m_robs.push_back(Rob(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_rob)));
		break;
	case BAD_GIFT:
		m_gifts.push_back(new BadGift(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_gift), Sprite(m_objectsShapes.m_enemy)));
		break;
	case POINTS_GIFT:
		m_gifts.push_back(new PointsGift(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_gift)));
		break;
	case LIFE_GIFT:
		m_gifts.push_back(new LifeGift(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_gift)));
		break;
	case PLAYER:
		m_player = new Player(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_player), 0);
		break;
	case SMART_ENEMY:
		m_enemies.push_back(new SmartEnemy(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_enemy)));
		break;
	case RANDOM_ENEMY:
		m_enemies.push_back(new RandomEnemy(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_enemy)));
		break;
	case DUMB_ENEMY:
		m_enemies.push_back(new DumbEnemy(x * SHAPE_SIZE, y * SHAPE_SIZE, Sprite(m_objectsShapes.m_enemy)));
		break;
	}
}
//==============================================================
bool Board::isPlayer(const FloatRect& otherGlobalBounds) const
{
	return m_player->getBounds().intersects(otherGlobalBounds);
}
//==============================================================
bool Board::isEnemy(const FloatRect& otherGlobalBounds) const
{
	int n = m_enemies.size();
	for (int i = 0;i < n;i++)
		if (m_enemies[i]->getBounds().intersects(otherGlobalBounds))
				return true;
	return false;
}
//==============================================================
bool Board::isWall(const FloatRect& otherGlobalBounds) const
{
	if (otherGlobalBounds.left < 0 || otherGlobalBounds.top < 0
		|| otherGlobalBounds.left + otherGlobalBounds.width > m_boardSize.x
		|| otherGlobalBounds.top + otherGlobalBounds.height > m_boardSize.y)
		return true;
	int n = m_walls.size();
	for (int i = 0;i < n;i++)
		if (m_walls[i].getBounds().intersects(otherGlobalBounds))
			return true;
	return false;
}
//==============================================================
sf::Vector2f Board::isLadder(const FloatRect& otherGlobalBounds) const
{
	int n = m_ladders.size();
	FloatRect temp;
	for (int i = 0;i < n;i++)
		if (m_ladders[i].getBounds().intersects(otherGlobalBounds, temp))
			return Vector2f(temp.width, temp.height);
	return Vector2f(0, 0);
}
//==============================================================
sf::Vector2f Board::isRob(const FloatRect& otherGlobalBounds) const
{
	int n = m_robs.size();
	FloatRect temp;
	for (int i = 0;i < n;i++)
		if (m_robs[i].getBounds().intersects(otherGlobalBounds, temp))
			return Vector2f(temp.width, temp.height);
	return Vector2f(0, 0);
}
//==============================================================
Gift* Board::getGift(const FloatRect& otherGlobalBounds)
{
	int n = m_gifts.size(), i;
	for (i = 0;i < n;i++)
		if (m_gifts[i]->getBounds().intersects(otherGlobalBounds))
			break;
	//case that there is no gift within these global bounds
	if (i == n)
		return NULL;

	//there is a gift in these global bounds and this gift is in index i in the gifts vector
	//and will be deleted when calling function giftTaken()
	m_indx = i;

	//case that it's it a bad gift then push the enemy returned from the board to the 
	//m_enemies vector
	if (typeid(*m_gifts[i]) == typeid(BadGift))
	{
		m_enemies.push_back((Enemy*)m_gifts[i]->get());
		giftTaken();
		return NULL;
	}

	//other gifts are returned to take what they can give
	return m_gifts[i];
}
//==============================================================
void Board::giftTaken()
{
	//delete the gift in the index m_indx
	delete m_gifts[m_indx];
	m_gifts.erase(m_gifts.begin() + m_indx);
}
//==============================================================
void Board::draw(sf::RenderWindow& window) const
{
	//draw the walls
	int n = m_walls.size();
	for (int i = 0;i < n;i++)
		m_walls[i].draw(window);

	//draw the robs
	n = m_robs.size();
	for (int i = 0;i < n;i++)
		m_robs[i].draw(window);

	//draw the ladders
	n = m_ladders.size();
	for (int i = 0;i < n;i++)
		m_ladders[i].draw(window);

	//draw the gifts
	n = m_gifts.size();
	for (int i = 0;i < n;i++)
		m_gifts[i]->draw(window);

	//draw the player
	m_player->draw(window);

	//draw the enemies
	n = m_enemies.size();
	for (int i = 0;i < n;i++)
		m_enemies[i]->draw(window);

}
//==============================================================
void Board::reset()
{
	clear();
	setStartData();
}
//==============================================================
void Board::clear()
{
	//clear the non-pointers vectors
	m_walls.clear();
	m_ladders.clear();
	m_robs.clear();

	//clear the pointers vectors
	//clear gifts
	int n = m_gifts.size();
	for (int i = 0;i < n;i++)
		delete m_gifts[i];
	m_gifts.clear();

	//clear player
	delete m_player;

	//clear enemies
	n = m_enemies.size();
	for (int i = 0;i < n;i++)
		delete m_enemies[i];
	m_enemies.clear();
}
//==============================================================
void Board::moveObjects()
{
	m_player->move(*this);
	for (int i = 0;i < m_enemies.size();i++)
		m_enemies[i]->move(*this);
}
//==============================================================
bool Board::allGiftsTaken()
{
	return !m_gifts.size();
}
//==============================================================
void Board::death()
{
	m_player->setLife(m_player->getLife() - 1);
	if (m_player->getLife() == 0)
		return;
	clear();
	reset();
}
//==============================================================
bool Board::playerDead()
{
	return m_player->getLife();
}
//==============================================================
Vector2f Board::playerLoc()
{
	return m_player->getLocation();
}
//==============================================================
sf::Vector2u Board::getSize()
{
	return m_boardSize;
}
//==============================================================
