#pragma once

#include "piece.h"
#include <cassert>

using namespace std;

/**************************************************
 * TEST PIECE
 * Unit tests for the Piece class
 **************************************************/
class TestPiece
{
public:
   void run()
   {
	void testAssign();
   void testAssignPiece(Piece piece);
	bool testIsWhite();
	bool testIsMove();
	int testGetNMoves();
	Position testGetPosition();
	bool testJustMoved();
   }

private:
   void testAssign(){
      //setup
      Piece* piece;
      Position pos(5,4);
      
      //excersize
      piece->assign(pos);
      //verify
      assert(pos.row == 5);
      assert(pos.col == 4);
      //cleanup
      delete piece;
   }

   void testAssignPiece(){
      //setup
      Piece* assignToPiece;
      Piece* assignedPiece;
      assignToPiece->position.row = 5;
      assignToPiece->position.col = 5;
      assignedPiece->position.row = 7;
      assignedPiece->position;
      //excersize
      //assignedPiece->assign(assignToPiece);
      //verify
      //assert(assignToPiece.row == assignedPiece.row);
      //assert()
   }

};