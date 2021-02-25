//
//  SmartEnemy.cpp
//  loadRunner
//
//  Created by meir benin on 23/02/2021.
//  Copyright © 2021 meir benin. All rights reserved.
//

#include "SmartEnemy.h"

void SmartEnemy::move(Board& board) {
    if (isFall(board))
        return;
    Direction_t direction = smartDirection(board);
    if (direction == NON_D)
        return;
    moveShape(direction);
    giftOrDeath(board);
}
//---------------------------------------------
Direction_t SmartEnemy::smartDirection(Board& board) {
    auto direction = directionToPlayer(board);
    switch (direction) {
    case UP_RIGHT:
        return findLegalDirection(UP_D, RIGHT_D, LEFT_D, DWON_D, board);
        break;
    case UP_LEFT:
        return findLegalDirection(UP_D, LEFT_D, RIGHT_D, DWON_D, board);
        break;
    case DWON_RIGHT:
        return findLegalDirection(RIGHT_D, DWON_D, LEFT_D, UP_D, board);
        break;
    case DWON_LEFT:
        return findLegalDirection(LEFT_D, DWON_D, RIGHT_D, UP_D, board);
        break;
    }
}

//---------------------------------------------
PlayerDirect_t SmartEnemy::directionToPlayer(Board& board) {
    auto playerLoc = board.playerLoc();
    auto myLoc = m_shape.getPosition();
    if (playerLoc.y <= myLoc.y && playerLoc.x >= myLoc.x)
        return UP_RIGHT;
    if (playerLoc.y <= myLoc.y && playerLoc.x < myLoc.x)
        return UP_LEFT;
    if (playerLoc.y > myLoc.y && playerLoc.x >= myLoc.x)
        return DWON_RIGHT;
    if (playerLoc.y > myLoc.y && playerLoc.x < myLoc.x)
        return DWON_LEFT;
    return UP_RIGHT;//not heppen never
}
//---------------------------------------------
Direction_t SmartEnemy::findLegalDirection(Direction_t first, Direction_t second, Direction_t third, Direction_t fourth, Board& board) {
    if (isLegalMove(first, board))
        return first;
    if (isLegalMove(second, board))
        return second;
    if (isLegalMove(third, board))
        return third;
    if (isLegalMove(fourth, board))
        return fourth;
    return NON_D;//
}
