#include "GameCharacter.h"
//++++++++++++++++++++++++++++++++++++++++++++
GameCharacter::GameCharacter(int x, int y, Sprite shape)
{
	m_shape = shape;
	m_shape.setPosition(x, y);
}
//--------------------------------------------
void GameCharacter::draw(RenderWindow& window) const
{
	window.draw(m_shape);
}
//--------------------------------------------
FloatRect GameCharacter::getBounds() const
{
	return m_shape.getGlobalBounds();
}
