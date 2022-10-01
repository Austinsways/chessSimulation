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
      getMoves__free();
      getMoves_blocked();
      getMoves_capture();
      getMoves__blocked();
      getMoves__capture();




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

   /**************************************************
    * GET MOVES - King can move in all directions
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8                     8
    * 7                     7
    * 6         p p p       6
    * 5         p(k)p       5
    * 4         p p p       4
    * 3                     3
    * 2                     2
    * 1                     1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    **************************************************/
   void getMoves__blocked()
   {
       // setup
       Board board;

       King king;
       king.white = true;
       king.position = Position(4, 4); // e5
       board.assign(king);

       Pawn pawn1;
       pawn2.white = true;
       pawn2.position = Position(3, 5); // d6
       board.assign(pawn1);

       Pawn pawn2;
       pawn2.white = true;
       pawn2.position = Position(4, 5); // e6
       board.assign(pawn2);

       Pawn pawn3;
       pawn2.white = true;
       pawn2.position = Position(5, 5); // f6
       board.assign(pawn3);

       Pawn pawn4;
       pawn2.white = true;
       pawn2.position = Position(3, 4); // d5
       board.assign(pawn4);

       Pawn pawn5;
       pawn2.white = true;
       pawn2.position = Position(5, 4); // f5
       board.assign(pawn5);

       Pawn pawn6;
       pawn2.white = true;
       pawn2.position = Position(3, 3); // d4
       board.assign(pawn6);

       Pawn pawn7;
       pawn2.white = true;
       pawn2.position = Position(4, 3); // e4
       board.assign(pawn7);

       Pawn pawn8;
       pawn2.white = true;
       pawn2.position = Position(5, 3); // f4
       board.assign(pawn8);

       // exercise
       auto moves = king.getMoves(board);

       // verify
       set<string> expectedMoves{ };
       set<string> actualMoves;
       for (auto move : moves)
           actualMoves.insert(move.getText());

       assert(expectedMoves == actualMoves);
       assert(king.position == Position(4, 4));
       assert(pawn1.position == Position(3, 5));
       assert(pawn2.position == Position(4, 5));
       assert(pawn3.position == Position(5, 5));
       assert(pawn4.position == Position(3, 4));
       assert(pawn5.position == Position(5, 4));
       assert(pawn6.position == Position(3, 3));
       assert(pawn7.position == Position(4, 3));
       assert(pawn8.position == Position(5, 3));

   }  // cleanup

   /**************************************************
    * GET MOVES - King can move in all directions
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8                     8
    * 7                     7
    * 6         P P P       6
    * 5         P(k)P       5
    * 4         P P P       4
    * 3                     3
    * 2                     2
    * 1                     1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    **************************************************/
   void getMoves__capture()
   {
       // setup
       Board board;

       King king;
       king.white = true;
       king.position = Position(4, 4); // e5
       board.assign(king);

       Pawn pawn1;
       pawn2.white = false;
       pawn2.position = Position(3, 5); // d6
       board.assign(pawn1);

       Pawn pawn2;
       pawn2.white = false;
       pawn2.position = Position(4, 5); // e6
       board.assign(pawn2);

       Pawn pawn3;
       pawn2.white = false;
       pawn2.position = Position(5, 5); // f6
       board.assign(pawn3);

       Pawn pawn4;
       pawn2.white = false;
       pawn2.position = Position(3, 4); // d5
       board.assign(pawn4);

       Pawn pawn5;
       pawn2.white = false;
       pawn2.position = Position(5, 4); // f5
       board.assign(pawn5);

       Pawn pawn6;
       pawn2.white = false;
       pawn2.position = Position(3, 3); // d4
       board.assign(pawn6);

       Pawn pawn7;
       pawn2.white = false;
       pawn2.position = Position(4, 3); // e4
       board.assign(pawn7);

       Pawn pawn8;
       pawn2.white = false;
       pawn2.position = Position(5, 3); // f4
       board.assign(pawn8);

       // exercise
       auto moves = king.getMoves(board);

       // verify
       set<string> expectedMoves{ "e5d6p", "e5e6p", "e5f6p", "e5d5p", "e5f5p", "e5d4p", "e5e4p", "e5f4p" };
       set<string> actualMoves;
       for (auto move : moves)
           actualMoves.insert(move.getText());

       assert(expectedMoves == actualMoves);
       assert(king.position == Position(4, 4));
       assert(pawn1.position == Position(3, 5));
       assert(pawn2.position == Position(4, 5));
       assert(pawn3.position == Position(5, 5));
       assert(pawn4.position == Position(3, 4));
       assert(pawn5.position == Position(5, 4));
       assert(pawn6.position == Position(3, 3));
       assert(pawn7.position == Position(4, 3));
       assert(pawn8.position == Position(5, 3));


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
