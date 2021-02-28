
#include "SmartEnemy.h"
//++++++++++++++++++++++++++++++++++++++++++++
void SmartEnemy::move(Board& board) {
    if (isFall(board))
        return;
    Direction direction = smartDirection(board);
    if (direction == NON)
        return;
    moveShape(direction);
    giftOrDeath(board);
}
//--------------------------------------------
Direction SmartEnemy::smartDirection(Board& board) {
    auto direction = directionToPlayer(board);
    switch (direction) {
    case UP_RIGHT:
        return findLegalDirection(UP, RIGHT, LEFT, DWON, board);
        break;
    case UP_LEFT:
        return findLegalDirection(UP, LEFT, RIGHT, DWON, board);
        break;
    case DWON_RIGHT:
        return findLegalDirection(RIGHT, DWON, LEFT, UP, board);
        break;
    case DWON_LEFT:
        return findLegalDirection(LEFT, DWON, RIGHT, UP, board);
        break;
    }
}

//---------------------------------------------
PlayerDirect SmartEnemy::directionToPlayer(Board& board) {
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
Direction SmartEnemy::findLegalDirection(Direction first, Direction second, Direction third, Direction fourth, Board& board) {
    if (isLegalMove(first, board))
        return first;
    if (isLegalMove(second, board))
        return second;
    if (isLegalMove(third, board))
        return third;
    if (isLegalMove(fourth, board))
        return fourth;
    return NON;//
}
