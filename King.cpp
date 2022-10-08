/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "king.h"
#include "move.h"
#include "board.h"

#include <list>

using namespace std;

list<Move> Pawn::getMoves(const Board& board) const
{
    list<Move> moves;
    int lastRow = white ? 7 : 0;

    // Normal forward and backwards move
    Position oneAhead(position);
    oneAhead.adjustRow(white ? 1 : -1);
    if (oneAhead.isValid() && board.get(oneAhead).getLetter() == ' ')
    {
        Move move(position, oneAhead, white);
        moves.push_back(Move(position, oneAhead, white));
    }
    
    Position oneBack(position);
    oneBack.adjustRow(white ? -1 : 1);
    if (oneBack.isValid() && board.get(oneBack).getLetter() == ' ')
    {
        Move move(position, oneBack, white);
        moves.push_back(Move(position, oneBack, white));
    }

    //normal sideways moves
    Position sideRight(position);
    sideRight.adjustCol(white ? 1 : -1);
    if (sideRight.isValid() && board.get(sideRight).getLetter() == ' ')
    {
        Move move(position, sideRight, white);
        moves.push_back(Move(position, sideRight, white));
    }
    Position sideLeft(position);
    sideLeft.adjustCol(white ? -1 : 1);
    if (sideLeft.isValid() && board.get(sideLeft).getLetter() == ' ')
    {
        Move move(position, sideLeft, white);
        moves.push_back(Move(position, sideLeft, white));
    }

    //diagonal moves
    Position sideRightUp(position);
    sideRightUp.adjustCol(white ? 1 : -1);
    sideRightUp.adjustRow(white ? 1 : -1);

    if (sideRightUp.isValid() && board.get(sideRightUp).getLetter() == ' ')
    {
        Move move(position, sideRightUp, white);
        moves.push_back(Move(position, sideRightUp, white));
    }

    Position sideLeftUp(position);
    sideLeftUp.adjustCol(white ? 1 : -1);
    sideLeftUp.adjustRow(white ? -1 : 1);

    if (sideLeftUp.isValid() && board.get(sideLeftUp).getLetter() == ' ')
    {
        Move move(position, sideLeftUp, white);
        moves.push_back(Move(position, sideLeftUp, white));
    }

    Position sideRightDown(position);
    sideRightDown.adjustCol(white ? -1 : 1);
    sideRightDown.adjustRow(white ? 1 : -1);

    if (sideRightDown.isValid() && board.get(sideRightDown).getLetter() == ' ')
    {
        Move move(position, sideRightDown, white);
        moves.push_back(Move(position, sideRightDown, white));
    }

    Position sideLeftDown(position);
    sideLeftDown.adjustCol(white ? -1 : 1);
    sideLeftDown.adjustRow(white ? -1 : 1);

    if (sideLeftDown.isValid() && board.get(sideLeftDown).getLetter() == ' ')
    {
        Move move(position, sideLeftDown, white);
        moves.push_back(Move(position, sideLeftDown, white));
    }

    



    // captures


    Position diagonals[8]{ sideRightUp,sideLeftUp, sideLeftDown, sideRightDown, sideRight, sideLeft, oneAhead, oneBack };
    for (const auto& diagonal : diagonals)
    {
        if (diagonal.isValid())
        {
            const Piece& opponent = board.get(diagonal);
            if (opponent.getLetter() != ' ' && opponent.isWhite() != white)
            {
                Move move(position, diagonal, white);
                move.setCapture(opponent.getLetter());
                
            }
        }
    }


    //castle
    if (getNMoves() > 0) {
        //first 3 is for the three spots between rook and king, increasing or decreasing based on color
        bool valid = true;
        //we'll need to add a thing to find if the rook is there later.
        for (int i = 0; white ? i < -3 : i >3;white ?  i -= 1: i+=1) {
            Position locationCheck(getPosition());
            locationCheck.adjustRow(i);
            if (!(locationCheck.isValid() && board.get(locationCheck).getLetter() == ' ')) {
                valid = false;
            };
        }
        if (valid) {
            Position newPosition(white ? 3 : 3, white ? 0 : 7 );
            Move move(position, newPosition, white);
        }

        //first 2 is for the three spots between rook and king, increasing or decreasing based on color
        bool valid = true;
        //we'll need to add a thing to find if the rook is there later.
        for (int i = 0; white ? i < -2 : i >2; white ? i += 1 : i -= 1) {
            Position locationCheck(getPosition());
            locationCheck.adjustRow(i);
            if (!(locationCheck.isValid() && board.get(locationCheck).getLetter() == ' ')) {
                valid = false;
            };
        }
        if (valid) {
            Position newPosition(white ? 7 : 7, white ? 0 : 7);
            Move move(position, newPosition, white);
        }
    }
    

    return moves;
}
