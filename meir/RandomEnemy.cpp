#include "RandomEnemy.h"
//=============================================================
RandomEnemy::RandomEnemy(int x, int y, Sprite shape) : Enemy(x, y, shape) {
    randDirection();
    m_counter = 0;
}
//------------------------------------------------------------
Direction RandomEnemy::getDirection() {
    m_counter++;
    if (m_counter % 15 == 0)
        randDirection();
    return m_direction;
}
//--------------------------------------------------------------
void RandomEnemy::FailedMove() {
    randDirection();
}
//-------------------------------------------------------------
void RandomEnemy::randDirection() {
    int random_variable = (std::rand()) % 4 ;
    switch (random_variable) {
    case 0:
        m_direction = UP;
        break;
    case 1:
        m_direction = DWON;
        break;
    case 2:
        m_direction = RIGHT;
        break;
    case 3:
        m_direction = LEFT;
        break;
    }
}
