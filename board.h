#pragma once

#include <memory>

//#include "piece.h"

class Piece;
class TestBoard;

/**************************************************
 * BOARD
 * The chess board
 **************************************************/
class Board
{
public:
   friend TestBoard;

   Board() {}

   void assign(Piece& piece) {}

private:

};

