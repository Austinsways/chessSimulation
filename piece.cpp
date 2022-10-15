/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "piece.h"
#include "board.h"
#include <GL/glut.h> 


using namespace std;

/**************************************************
 * PIECE :: JUST MOVED
 * Determine if a piece moved during the last turn
 **************************************************/
bool Piece::justMoved(const Board& board) const {
   return board.getCurrentMove() - lastMove == 1;
}

/**************************************************
 * PIECE :: GET SLIDE MOVES
 * Get a list of moves from sliding in a given direction
 **************************************************/
list<Move> Piece::getSlideMoves(const Board& board, const Delta& delta) const
{
   list<Move> moves;
   Position checkPos(position);
   bool blocked = false;
   while (!blocked)
   {
      checkPos += delta;
      if (checkPos.isValid())
      {
         const Piece& piece = board.get(checkPos);
         if (piece == ' ' || piece.isWhite() != white)
         {
            Move move(position, checkPos, white);
            if (piece != ' ')
            {
               move.setCapture(piece.getLetter());
               blocked = true;
            }
            moves.push_back(move);
         }
         else
            blocked = true;
      }
      else
         blocked = true;
   }
   return moves;
}

bool operator==(const Piece& lhs, char rhs)
{
   return lhs.getLetter() == rhs;
}

bool operator!=(const Piece& lhs, char rhs)
{
   return !(lhs == rhs);
}

void Piece::glColor(const int* rgb) const
{
       //this sets the colors for the pieces. It's called only within the draw() function. 
    glColor3f((GLfloat)(rgb[0] / 256.0),
        (GLfloat)(rgb[1] / 256.0),
        (GLfloat)(rgb[2] / 256.0));
}

void Piece::drawPiece(int x, int y, bool black, Rect rectangle[], int num) const
{

    GLint xGL = (GLint)(x + 16 /* half a square width */);
    GLint yGL = (GLint)(y + 16 /* half a square height*/);
    const int RGB_WHITE[] = { 255, 255, 255 };
    const int RGB_BLACK[] = { 0, 0, 0 };
    // get ready to draw
    glBegin(GL_QUADS);
    glColor(black ? RGB_BLACK : RGB_WHITE);

    // iterate through the rectangles
    for (int i = 0; i < num; i++)
    {
        glVertex2i(xGL + rectangle[i].x0, yGL + rectangle[i].y0);
        glVertex2i(xGL + rectangle[i].x1, yGL + rectangle[i].y1);
        glVertex2i(xGL + rectangle[i].x2, yGL + rectangle[i].y2);
        glVertex2i(xGL + rectangle[i].x3, yGL + rectangle[i].y3);
    }

    // finish the drawing
    glEnd();
}