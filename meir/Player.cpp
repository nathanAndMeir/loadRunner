
#include "Player.h"
#include "PointsGift.h"
#include "LifeGift.h"
//=============================================================================
Player::Player(int x, int y, Sprite shape, int life) : MovingChar(x, y, shape)
{
    m_life = life;
    m_points = 0;
}
//-----------------------------------------------------------------------------
Direction Player::getDirection()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return UP;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return DWON;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return RIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return LEFT;
    return NON;
}
//---------------------------------------------------------------------
void Player::giftOrDeath(Board& board) {
    if (board.isEnemy(m_shape.getGlobalBounds()))
        board.death();
//    auto gift = board.getGift(m_shape.getGlobalBounds());
//    if (gift) {
//        if (typeid(*gift) == typeid(PointsGift))
//            m_points += *(int*)(gift->get());
//        if (typeid(*gift) == typeid(LifeGift))
//            m_life += *(int*)(gift->get());
//        board.giftTaken();
//    }
}
//---------------------------------------------------------------------
void Player::FailedMove() {
    //make noiz
}

