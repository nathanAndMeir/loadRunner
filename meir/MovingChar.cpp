
#include "MovingChar.h"
//======================================================
void MovingChar::move(Board& board) {
    if (isFall(board))
        return;
    Direction direction = getDirection();
    if (direction == NON)
        return;
    if (isLegalMove(direction, board)) {
        moveShape(direction);
        giftOrDeath(board);
    }
    else
        FailedMove();
}
//------------------------------------------------------------------
bool MovingChar::isLegalMove(Direction dirction, Board& board)const
{
    auto tempRect = m_shape.getGlobalBounds();
    switch (dirction)
    {
    case UP:
        tempRect.top -= MOVE_LENGTH;
        if (board.isLadder(m_shape.getGlobalBounds()).x == m_shape.getGlobalBounds().width &&
            !board.isWall(tempRect))
            return true;
        return false;
    case DWON:
        tempRect.top += MOVE_LENGTH;
        if (!board.isWall(tempRect))
            return true;
        return false;
    case RIGHT:
            tempRect.left += MOVE_LENGTH;
            if (board.isWall(tempRect))
                return false;
    case LEFT:
        tempRect.left -= MOVE_LENGTH;
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
        moveShape(DWON);
        return true;
    }
    return false;
}
//==============================================
void MovingChar::moveShape(Direction direction) {

    switch (direction) {
    case UP:
        m_shape.move(0, -MOVE_LENGTH);
        break;
    case DWON:
        m_shape.move(0, MOVE_LENGTH);
        break;
    case RIGHT:
        m_shape.move(MOVE_LENGTH, 0);
        break;
    case LEFT:
        m_shape.move(-MOVE_LENGTH, 0);
        break;
    }
}

