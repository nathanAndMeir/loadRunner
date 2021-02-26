#pragma once
#include <SFML/Graphics.hpp>
using sf::Vector2f;
using sf::RenderWindow;
using sf::Sprite;
using sf::FloatRect;

class GameCharacter {
public:
	//constructor of game character
	//sets the location of the object 
	//and the shape of it
	GameCharacter(int,int, Sprite);

	//draw the object's shape on window 
	void draw(RenderWindow&) const;

	//return the global bounds of the shape 
	//which is a rectangle
	FloatRect getBounds() const;

	virtual ~GameCharacter() = 0 {}
protected:
	//shape of the object
	Sprite m_shape;
};