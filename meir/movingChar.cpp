//
//  MovingChar.cpp
//  loadRunner
//
//  Created by meir benin on 18/02/2021.
//  Copyright © 2021 meir benin. All rights reserved.
//

#include "MovingChar.h"

//======================================================

void MovingChar::move(Board& board) {
    if (isFall(board))
        return;
    Direction_t direction = getDirection();
    if (direction == NON_D)
        return;
    if (isLegalMove(direction, board)) {
        moveShape(direction);
        giftOrDeath(board);
    }
    else
        FailedMove();
}

//------------------------------------------------------------------
bool MovingChar::isLegalMove(Direction_t dirction, Board& board)const
{
    auto tempRect = m_shape.getGlobalBounds();
    switch (dirction)
    {
    case UP_D:
        tempRect.top -= MOVE_LENGTH;
        if (board.isLadder(m_shape.getGlobalBounds()).x == m_shape.getGlobalBounds().width &&
            !board.isWall(tempRect))
            return true;
        return false;
    case DWON_D:
        tempRect.top += MOVE_LENGTH;
        if (!board.isWall(tempRect))
            return true;
        return false;
    case RIGHT_D:
    case LEFT_D:
        tempRect.left += dirction == RIGHT_D ? MOVE_LENGTH : -MOVE_LENGTH;
        if (board.isWall(tempRect))
            return false;
        return true;
    }
}
//=================================================
bool MovingChar::isFall(Board& board) {
    auto tempRect = m_shape.getGlobalBounds();
    tempRect.top += MOVE_LENGTH;

    //fall as long as the area below is not wall or ladder
    //and this area is not a rob
    if (!board.isWall(tempRect) && board.isLadder(tempRect).y == 0 &&
        board.isRob(m_shape.getGlobalBounds()).y != m_shape.getGlobalBounds().height)
    {
        moveShape(DWON_D);
        return true;
    }
    return false;
}
//==============================================
void MovingChar::moveShape(Direction_t direction) {

    switch (direction) {
    case UP_D:
        m_shape.move(0, -MOVE_LENGTH);
        break;
    case DWON_D:
        m_shape.move(0, MOVE_LENGTH);
        break;
    case RIGHT_D:
        m_shape.move(MOVE_LENGTH, 0);
        break;
    case LEFT_D:
        m_shape.move(-MOVE_LENGTH, 0);
        break;
    }
}

