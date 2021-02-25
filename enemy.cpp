//
//  Enemy.cpp
//  loadRunner
//
//  Created by meir benin on 19/02/2021.
//  Copyright � 2021 meir benin. All rights reserved.
//

#include "Enemy.h"
//============================
void Enemy::giftOrDeath(Board& board) {
    if (board.isPlayer(m_shape.getGlobalBounds()))
        board.death();
//just test if work
}
