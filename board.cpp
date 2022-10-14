/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "board.h"
#include "space.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
using namespace std;

/**************************************************
 * BOARD CONSTRUCTOR
 **************************************************/
Board::Board() : currentMove(0)
{
   reset();
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

/**************************************************
 * BOARD :: RESET
 * Set up the chess board with all the pieces
 **************************************************/
void Board::reset()
{
   char setup[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'
   };
   for (int i = 0; i < 64; i++)
   {
      int row = i / 8;
      int col = i % 8;
      switch (setup[i])
      {
      case 'p':
         board[i] = make_unique<Pawn>(Pawn(row, col, i < 16));
         break;
      case 'r':
         board[i] = make_unique<Rook>(Rook(row, col, i < 16));
         break;
      case 'n':
         board[i] = make_unique<Knight>(Knight(row, col, i < 16));
         break;
      case 'b':
         board[i] = make_unique<Bishop>(Bishop(row, col, i < 16));
         break;
      case 'q':
         board[i] = make_unique<Queen>(Queen(row, col, i < 16));
         break;
      case 'k':
         board[i] = make_unique<King>(King(row, col, i < 16));
         break;
      default:
         board[i] = make_unique<Space>(Space(row, col, false));
         break;
      }
   }
}

/**************************************************
 * BOARD :: CLEAR
 * Fill the board with spaces
 **************************************************/
void Board::clear()
{
   for (int i = 0; i < 64; i++)
   {
      int row = i / 8;
      int col = i % 8;
      board[i] = make_unique<Space>(Space(row, col, i < 16));
   }
}