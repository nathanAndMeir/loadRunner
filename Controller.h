#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Board.h"
#include "Player.h"
#include "ObjectsShapes.h"

enum MenuOp {
	Play, Exit
};


class Controller {
public:
	void run();
private:
	bool play();
	void display();
	void startGame();
	MenuOp menu();
	void checkCloseEvent(sf::Event&);

	int m_stageNumber;
	int m_stageSize;
	Board m_board;
	ObjectsShapes m_shapesSource;
	std::ifstream m_fileName = std::ifstream("board.txt");
	sf::RenderWindow m_window;
};