
#include "Enemy.h"
//============================
void Enemy::giftOrDeath(Board& board) {
    if (board.isPlayer(m_shape.getGlobalBounds()))
        board.death();
}
