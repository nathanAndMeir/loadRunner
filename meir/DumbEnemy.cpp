
#include "DumbEnemy.h"
#include  <cstdlib>
//==============================================================

DumbEnemy::DumbEnemy(int x, int y, Sprite shape) :Enemy(x, y, shape) {
        m_direction = LEFT;
}
//-------------------------------------------------------------
Direction DumbEnemy::getDirection(){
    return m_direction;
}
//--------------------------------------------------------------
void DumbEnemy::FailedMove() {
    switch (m_direction) {
    case RIGHT:
        m_direction = LEFT;
        break;
    case LEFT:
        m_direction = RIGHT;
        break;

    }
}
//--------------------------------------------------------------
