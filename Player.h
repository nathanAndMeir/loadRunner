#pragma once
#include "MovingChar.h"
#include "Direction.h"





class Player : public MovingChar {
public:
    Player(int x, int y, Sprite shape, int life);
    void setLife(int life) { m_life += life; }
    void setPoints(int points) { m_points += points; }
    int getLife() const { return m_life; }
    int getPoints() const { return m_points; }
    Vector2f getLocation() { return m_shape.getPosition(); }
private:
    int m_life;
    int m_points;
    Direction_t getDirection() override;
    void giftOrDeath(Board&)  override;
    void FailedMove()override;
};
