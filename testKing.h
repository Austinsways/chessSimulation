#pragma once

#include <cassert>
#include <set>

#include "king.h"
#include "board.h"
#include "rook.h"

class TestKing
{
public:
   void run()
   {
      getMoves_free();
      getMoves_blocked();
      getMoves_capture();
      getMoves_castleKingMoved();
      getMoves_castleKingMovedNMoves();
      getMoves_castleBlocked();
      getMoves_castle();
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
   void getMoves_free()
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

   void getMoves_blocked(){
      
   
      // setup
      Board board;

      King king;

      Pawn pawn1(3,6,true);
      Pawn pawn2(4,6,true);
      Pawn pawn3(5,6,true);
      Pawn pawn4(5,5,true);
      Pawn pawn5(3,4,true);
      Pawn pawn6(4,4,true);
      Pawn pawn7(5,4,true);
      
      
      king.position = Position(4, 5); // e5

      // exercise
      auto moves = king.getMoves(board);

      // verify
      set<string> expectedMoves{};
      set<string> actualMoves;
      for (auto move : moves)
         actualMoves.insert(move.getText());

      assert(expectedMoves == actualMoves);

     // cleanup
   }

   void getMoves_capture(){
      // setup
      Board board;

      King king;

      Pawn pawn1(3,6,false);
      Pawn pawn2(4,6,false);
      Pawn pawn3(5,6,false);
      Pawn pawn4(5,5,false);
      Pawn pawn5(3,4,false);
      Pawn pawn6(4,4,false);
      Pawn pawn7(5,4,false);
      
      
      king.position = Position(4, 5); // e5

      // exercise
      auto moves = king.getMoves(board);

      // verify
      set<string> expectedMoves{ "e5d6p", "e5e6p", "e5f6p", "e5d5p", "e5f5p", "e5d4p", "e5e4p", "e5f4p"};
      set<string> actualMoves;
      for (auto move : moves)
         actualMoves.insert(move.getText());

      assert(expectedMoves == actualMoves);

     // cleanup
   }

   void getMoves_castleKingMoved(){
      // setup
      Board board;

      King king;
      
      
      king.position = Position(4, 1); // e1
      king.nMoves = 1;

      Pawn pawn1(3,2,true);//d2
      Pawn pawn2(4,2,true);//e2
      Pawn pawn3(5,2,true);//f2

      Rook rook1(1,1,true);//a1
      Rook rook2(7,1,true);//h1

      // exercise
      auto moves = king.getMoves(board);

      // verify
      set<string> expectedMoves{"e1f1", "e1d1"};
      set<string> actualMoves;
      for (auto move : moves)
         actualMoves.insert(move.getText());

      assert(expectedMoves == actualMoves);

     // cleanup
   }

   void getMoves_castleKingMovedNMoves(){
       // setup
      Board board;

      King king;
      
      
      king.position = Position(4, 1); // e1
      

      Pawn pawn1(3,2,true);//d2
      Pawn pawn2(4,2,true);//e2
      Pawn pawn3(5,2,true);//f2

      Rook rook1(1,1,true);//a1
      rook1.nMoves = 1;
      Rook rook2(7,1,true);//h1
      rook1.nMoves = 1;

      // exercise
      auto moves = king.getMoves(board);

      // verify
      set<string> expectedMoves{"e1f1", "e1d1"};
      set<string> actualMoves;
      for (auto move : moves)
         actualMoves.insert(move.getText());

      assert(expectedMoves == actualMoves);

     // cleanup
   }

   void getMoves_castleBlocked(){
      // setup
      Board board;

      King king;

      Pawn pawn1(3,2,false);//d2
      Pawn pawn2(4,2,false);//e2
      Pawn pawn3(5,2,false);//f2
      Pawn pawn4(1,1,false);//b1
      Pawn pawn5(6,2,false);//g2
      
      
      
      king.position = Position(4, 1); // e1

      // exercise
      auto moves = king.getMoves(board);

      // verify
      set<string> expectedMoves{ "e1f1", "e1d1"};
      set<string> actualMoves;
      for (auto move : moves)
         actualMoves.insert(move.getText());

      assert(expectedMoves == actualMoves);

     // cleanup
   }

   void getMoves_castle(){
      // setup
      Board board;

      King king;

      Pawn pawn1(3,2,false);//d2
      Pawn pawn2(4,2,false);//e2
      Pawn pawn3(5,2,false);//f2

      Rook rook1(1,1,true);//a1
      Rook rook2(7,1,true);//h1
      
      
      
      king.position = Position(4, 1); // e1

      // exercise
      auto moves = king.getMoves(board);

      // verify
      set<string> expectedMoves{ "e1f1", "e1d1", "E1g1c", "e1c1C"};
      set<string> actualMoves;
      for (auto move : moves)
         actualMoves.insert(move.getText());

      assert(expectedMoves == actualMoves);

     // cleanup
   }

};
