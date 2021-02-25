//
//  RandomEnemy.cpp
//  loadRunner
//
//  Created by meir benin on 20/02/2021.
//  Copyright © 2021 meir benin. All rights reserved.
//

#include "RandomEnemy.h"
//=============================================================
RandomEnemy::RandomEnemy(int x, int y, Sprite shape) : Enemy(x, y, shape) {
    randDirection();
    m_counter = 0;
}

//-------------------------------------------------------------
Direction_t RandomEnemy::getDirection() {
    m_counter++;
    if (m_counter % 7 == 0)randDirection();
    return m_direction;
}
//--------------------------------------------------------------
void RandomEnemy::FailedMove() {
    randDirection();
}
//-------------------------------------------------------------
void RandomEnemy::randDirection() {
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
