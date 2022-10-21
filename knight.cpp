#include "knight.h"
#include "move.h"
#include <list>


std::list<Move> Knight::getMoves(const Board& board) const {

    std::list<Move> moves;
    Delta deltas[8]{ {2,1}, {2,-1}, {1,2}, {1,-2}, {-2,1}, {-2,-1}, {-1, 2}, {-1,-2} };
    for (auto& delta : deltas)
    {
        //since the knight can jump over any piece it wishes, we do not use slide positioning. 
        Position possiblePosition(position);
        possiblePosition.adjustCol(delta.col);
        possiblePosition.adjustRow(delta.row);
        //bool blocked = false; 
        if (possiblePosition.isValid() && (board.get(possiblePosition).getLetter() == ' ' || board.get(possiblePosition).isWhite() != this->isWhite()))
            {
                Move move(position, possiblePosition, white);
                if (board.get(possiblePosition).getLetter() != ' ') {
                    move.setCapture(board.get(possiblePosition).getLetter());
                }
                moves.push_back(move);
            }
        /*if (board.get(possiblePosition).getLetter() != ' ' && board.get(possiblePosition).isWhite() != white)
            {
                Move move(position, possiblePosition, white);
                move.setCapture(board.get(possiblePosition).getLetter());

            }*/
        /*else {
            blocked = true;
        };*/
    }
    return moves;
}

void Knight::draw() const {
    Rect rectangles[] =
    {
       {-7,3,  -3,6,  -1,3,  -5,0},  // muzzle
       {-2,6,  -2,8,   0,8,   0,3},  // head
       {-3,6,   3,6,   6,1,   1,1},  // main
       { 6,1,   1,1,  -5,-5,  5,-5}, // body
       { 6,-6, -6,-6, -6,-8,  6,-8}  // base

    };

    drawPiece(xFromPosition(position.getLocation()), yFromPosition(position.getLocation()), white, rectangles, 5);
}