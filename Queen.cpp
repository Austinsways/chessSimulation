/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "queen.h"
#include "move.h"

#include <list>

using namespace std;

list<Move> Queen::getMoves(const Board& board) const
{
   list<Move> moves;
   Delta deltas[8]{ {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };
   for (auto& delta : deltas)
   {
      auto slideMoves = getSlideMoves(board, delta);
      moves.splice(moves.end(), slideMoves);
      //moves.merge(slideMoves);
   }
   return moves;

   //int lastRow = white ? 7 : 0;


   ////these booleans tell us which directions have been blocked out of the 8 possible directions
   //bool blockedForward = false;
   //bool blockedBackward = false;
   //bool blockedRight = false;
   //bool blockedLeft = false;
   //bool blockedPosXPosY = false;
   //bool blockedNegXPosY = false;
   //bool blockedNegXNegY = false;
   //bool blockedPosXNegY = false;
   ////the queen can move forwards and backwards as many spaces as she wants. This loop covers every space possible
   //for (int f = 0; f < 8; f++)
   //{
   //    //first we check the forward movement
   //    Position possiblePosition(position);
   //    possiblePosition.adjustRow(f);
   //    if (!blockedForward)
   //        checkPossibleMove(blockedForward, moves, possiblePosition, board);

   //    //now checking backward
   //    possiblePosition.adjustRow(-(f * 2));
   //    if (!blockedBackward)
   //        checkPossibleMove(blockedBackward, moves, possiblePosition, board);

   //    //now right
   //    possiblePosition.adjustRow(f); //this resets the row
   //    possiblePosition.adjustCol(f);
   //    if (!blockedRight)
   //        checkPossibleMove(blockedRight, moves, possiblePosition, board);

   //    //now left
   //    possiblePosition.adjustCol(-(f * 2));
   //    if (!blockedLeft)
   //        checkPossibleMove(blockedBackward, moves, possiblePosition, board);

   //    //resetting the position
   //    possiblePosition.adjustCol(f);

   //    //now we need to check all the diagonal directions. 
   //    //first is positive x positive y (or positive row change, positive column change)
   //    possiblePosition.adjustRow(f);
   //    possiblePosition.adjustCol(f);
   //    if (!blockedPosXPosY)
   //        checkPossibleMove(blockedPosXPosY, moves, possiblePosition, board);
   //    
   //    //next is negative x positive y
   //    possiblePosition.adjustRow(-(f * 2)); // this is resetting the row and making it negative.
   //    if (!blockedNegXPosY)
   //        checkPossibleMove(blockedNegXPosY, moves, possiblePosition, board);

   //    //next is negative x negative y
   //    possiblePosition.adjustCol(-(f * 2)); //this both resets the position and makes it negative. 
   //    if (!blockedNegXNegY)
   //        checkPossibleMove(blockedNegXNegY, moves, possiblePosition, board);

   //    //next is positive x negative y
   //    possiblePosition.adjustRow(f * 2); //this both resets x and makes its change positive.
   //    if (!blockedPosXNegY)
   //        checkPossibleMove(blockedPosXNegY, moves, possiblePosition, board);

   //}

   //return moves;
}

void Queen::draw() const {
    Rect rectangles[] =
    {
       { 8,8,   5,8,   5,5,   8,5 },     // right crown jewel
       {-8,8,  -5,8,  -5,5,  -8,5 },     // left crown jewel
       { 2,8,  -2,8,  -2,5,   2,5 },     // center crown jewel
       { 7,5,   5,5,   1,0,   5,0 },     // right crown holder
       {-7,5,  -5,5,  -1,0,  -5,0 },     // left crown holder
       { 1,5,   1,0,  -1,0,  -1,5 },     // center crown holder
       { 4,0,  -4,0,  -4,-2,  4,-2},     // upper base
       { 6,-3, -6,-3, -6,-5,  6,-5},     // middel base
       { 8,-6, -8,-6, -8,-8,  8,-8}      // base
    };

    drawPiece(xFromPosition(position.getLocation()), yFromPosition(position.getLocation()), white, rectangles, 9);
}


