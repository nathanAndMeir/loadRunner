#pragma once
#include <SFML/Graphics.hpp>
using sf::Texture;

struct ObjectsShapes {
	ObjectsShapes(){
		m_player.loadFromFile("player.png");
		m_ladder.loadFromFile("ladder.png");
		m_enemy.loadFromFile("enemy.png");
		m_gift.loadFromFile("gift.png");
		m_wall.loadFromFile("wall.png");
		m_rob.loadFromFile("rob.png");
	}
	Texture
		m_player,
		m_ladder,
		m_enemy,
		m_gift,
		m_wall,
		m_rob;
};
