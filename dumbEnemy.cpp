//
//  DumbEnemy.cpp
//  loadRunner
//
//  Created by meir benin on 19/02/2021.
//  Copyright © 2021 meir benin. All rights reserved.
//

#include "DumbEnemy.h"
#include  <cstdlib>
//==============================================================

DumbEnemy::DumbEnemy(int x, int y, Sprite shape) :Enemy(x, y, shape) {
    std::srand(std::time(nullptr));
    int random_variable = (std::rand()) % 4 + 1;
    switch (random_variable) {
    case 1:
        m_direction = UP_D;
        break;
    case 2:
        m_direction = DWON_D;
        break;
    case 3:
        m_direction = RIGHT_D;
        break;
    case 4:
        m_direction = LEFT_D;
        break;
    }
}
//--------------------------------------------------------------
Direction_t DumbEnemy::getDirection() {
    return m_direction;
}
//--------------------------------------------------------------
void DumbEnemy::FailedMove() {
    switch (m_direction) {
    case UP_D:
        m_direction = DWON_D;
        break;
    case DWON_D:
        m_direction = UP_D;
        break;
    case RIGHT_D:
        m_direction = LEFT_D;
        break;
    case LEFT_D:
        m_direction = RIGHT_D;
        break;

    }
}
//--------------------------------------------------------------
