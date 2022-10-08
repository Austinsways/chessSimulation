/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "board.h"
#include "space.h"
using namespace std;

/**************************************************
 * BOARD CONSTRUCTOR
 **************************************************/
Board::Board() : currentMove(0)
{
   for (int i = 0; i < 64; i++)
   {
      int row = i / 8;
      int col = i % 8;
      board[i] = make_unique<Space>(Space(row, col, i < 16));
   }
}

/**************************************************
 * BOARD :: GET
 * Get a piece from the board
 **************************************************/
const Piece& Board::get(const Position& pos) const
{
   if (!pos.isValid())
      throw "Cannot get piece from invalid position";

   return *board[pos.getLocation()];
}

