//
//  DumbEnemy.cpp
//  loadRunner
//
//  Created by meir benin on 19/02/2021.
//  Copyright � 2021 meir benin. All rights reserved.
//

#include "DumbEnemy.h"
#include  <cstdlib>
//==============================================================

DumbEnemy::DumbEnemy(int x, int y, Sprite shape) :Enemy(x, y, shape) {
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
//-------------------------------------------------------------
Direction DumbEnemy::getDirection() {
    return m_direction;
}
//--------------------------------------------------------------
void DumbEnemy::FailedMove() {
    switch (m_direction) {
    case UP:
        m_direction = DWON;
        break;
    case DWON:
        m_direction = UP;
        break;
    case RIGHT:
        m_direction = LEFT;
        break;
    case LEFT:
        m_direction = RIGHT;
        break;

    }
}
//--------------------------------------------------------------
