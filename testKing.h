#pragma once

#include <cassert>
#include <set>

#include "king.h"
#include "board.h"

class TestKing
{
public:
   void run()
   {
      getMoves__free();
   }

private:
   /**************************************************
    * GET MOVES - King can move in all directions
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8                     8
    * 7                     7
    * 6         * * *       6
    * 5         *(k)*       5
    * 4         * * *       4
    * 3                     3
    * 2                     2
    * 1                     1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    **************************************************/
   void getMoves__free()
   {
      // setup
      Board board;

      King king;
      king.white = true;
      king.position = Position(4, 4); // e5
      board.assign(king);

      // exercise
      auto moves = king.getMoves(board);

      // verify
      set<string> expectedMoves{ "e5d6", "e5e6", "e5f6", "e5d5", "e5f5", "e5d4", "e5e4", "e5f4" };
      set<string> actualMoves;
      for (auto move : moves)
         actualMoves.insert(move.getText());

      assert(expectedMoves == actualMoves);
      assert(king.position == Position(4, 4));

   }  // cleanup
};
