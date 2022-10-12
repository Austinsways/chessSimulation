/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "Queen.h"
#include "move.h"

#include <list>

using namespace std;

list<Move> Queen::getMoves(const Board& board)
{
    list<Move> moves;
    int lastRow = white ? 7 : 0;

   
    //these booleans tell us which directions have been blocked out of the 8 possible directions
    bool blockedForward = false;
    bool blockedBackward = false;
    bool blockedRight = false;
    bool blockedLeft = false;
    bool blockedPosXPosY = false;
    bool blockedNegXPosY = false;
    bool blockedNegXNegY = false;
    bool blockedPosXNegY = false;
    //the queen can move forwards and backwards as many spaces as she wants. This loop covers every space possible
    for (int f = 0; f < 8; f++)
    {
        //first we check the forward movement
        Position possiblePosition(position);
        possiblePosition.adjustRow(f);
        if (!blockedForward)
            checkPossibleMove(blockedForward, moves, possiblePosition, board);

        //now checking backward
        possiblePosition.adjustRow(-(f * 2));
        if (!blockedBackward)
            checkPossibleMove(blockedBackward, moves, possiblePosition, board);

        //now right
        possiblePosition.adjustRow(f); //this resets the row
        possiblePosition.adjustCol(f);
        if (!blockedRight)
            checkPossibleMove(blockedRight, moves, possiblePosition, board);

        //now left
        possiblePosition.adjustCol(-(f * 2));
        if (!blockedLeft)
            checkPossibleMove(blockedBackward, moves, possiblePosition, board);

        //resetting the position
        possiblePosition.adjustCol(f);

        //now we need to check all the diagonal directions. 
        //first is positive x positive y (or positive row change, positive column change)
        possiblePosition.adjustRow(f);
        possiblePosition.adjustCol(f);
        if (!blockedPosXPosY)
            checkPossibleMove(blockedPosXPosY, moves, possiblePosition, board);
        
        //next is negative x positive y
        possiblePosition.adjustRow(-(f * 2)); // this is resetting the row and making it negative.
        if (!blockedNegXPosY)
            checkPossibleMove(blockedNegXPosY, moves, possiblePosition, board);

        //next is negative x negative y
        possiblePosition.adjustCol(-(f * 2)); //this both resets the position and makes it negative. 
        if (!blockedNegXNegY)
            checkPossibleMove(blockedNegXNegY, moves, possiblePosition, board);

        //next is positive x negative y
        possiblePosition.adjustRow(f * 2); //this both resets x and makes its change positive.
        if (!blockedPosXNegY)
            checkPossibleMove(blockedPosXNegY, moves, possiblePosition, board);

    }

    return moves;
}


