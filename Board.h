#pragma once
#include <vector>
#include <typeinfo>
#include <fstream>
#include <thread>
#include <chrono>
#include "ObjectsChar.h"
#include "ObjectsShapes.h"
#include "StaticChar.h"
#include "LifeGift.h"
#include "PointsGift.h"
#include "BadGift.h"
#include "Wall.h"
#include "Ladder.h"
#include "Rob.h"
class MovingChar;
class Enemy;
class Player;
class RandomEnemy;
class DumbEnemy;
class SmartEnemy;

const int SHAPE_SIZE = 70;
using std::ifstream;

class Board {
public:
	//read one stage's from a file of chars and set by that the real object in the static objects or moving objects
	void setBoard(ifstream&, int, const ObjectsShapes&);

	//all these functions get global bouds (rectangle) and return if 
	//there is an overlapping in this bounds with spesific type
	bool isPlayer(const FloatRect&) const;
	bool isEnemy(const FloatRect&) const; 
	bool isWall(const FloatRect&) const;
	sf::Vector2f isLadder(const FloatRect&) const;
	sf::Vector2f isRob(const FloatRect&) const;

	//if there is any gift in the given global bounds then
	//manage it like that:
	//if it's bad gift then the board will add one enemy to the m_movingChar vector and return NULL
	//if it's other gift (points or life) then return the pointer to it
	//the one who call this function can use it and then call the giftTaken() function
	Gift* getGift(const FloatRect&);
	void giftTaken();
	
	//reset the board to the start condition by the char board
	void reset();

	//clear the board's data
	void clear();

	//draw everything on the board
	void draw(sf::RenderWindow&) const;

	void moveObjects();

	//return if there are any gifts in the board
	bool allGiftsTaken();
	
	Vector2f playerLoc();
	void death();

	//return if the player is completely dead and has no life left
	bool playerDead();

	sf::Vector2f getSize();
private:

	//set start data by the char board input
	void setStartData();

	//set one objects by the char in the char board in the cell with the given indexes
	void setOneObject(int, int);

	//vectors of specific characters
	//the ones who use inheritance are vectors of pointers
	std::vector<Wall> m_walls;
	std::vector<Ladder> m_ladders;
	std::vector<Rob> m_robs;
	std::vector<Gift*> m_gifts;
	std::vector<Enemy*> m_enemies;
	Player* m_player;

	//vector of string keeps the char board
	std::vector<std::string> m_charBoard;

	//main source for the objects textures
	ObjectsShapes m_objectsShapes;

	//index for deleting gift from m_gifts vector
	int m_indx;

	bool m_playerDead;

	sf::Vector2f m_boardSize;
};
