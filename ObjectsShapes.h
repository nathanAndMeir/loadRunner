#pragma once
#include <SFML/Graphics.hpp>
using sf::Texture;

struct ObjectsShapes {
	ObjectsShapes(){
		m_player.loadFromFile("/Users/meirbenin/Desktop/test/test/player.png");
		m_ladder.loadFromFile("/Users/meirbenin/Desktop/test/test/ladder.png");
		m_enemy.loadFromFile("/Users/meirbenin/Desktop/test/test/enemy.png");
		m_gift.loadFromFile("/Users/meirbenin/Desktop/test/test/gift.png");
		m_wall.loadFromFile("/Users/meirbenin/Desktop/test/test/wall.png");
		m_rob.loadFromFile("/Users/meirbenin/Desktop/test/test/rob.png");
	}
	Texture
		m_player,
		m_ladder,
		m_enemy,
		m_gift,
		m_wall,
		m_rob;
};
