/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include "position.h"

#include <iostream>
#include <string>

/**************************************************
 * MOVE
 * Represents the different types of moves in chess
 **************************************************/
class Move
{
public:
   Move() : piece(' '), capture(' '), enpassant(false), castleK(false), castleQ(false), isWhite(false) {}
   Move(Position source, Position dest, bool isWhite) :
      source(source),
      dest(dest),
      piece(' '),
      capture(' '),
      enpassant(false),
      castleK(false),
      castleQ(false),
      isWhite(isWhite) {}
   std::string getText() const;
   Position getSrc() const { return source; }
   Position getDest() const { return dest; }
   char getPromotion() const { return piece; }
   char getCapture() const { return capture; }
   bool getEnPassant() const { return enpassant; }
   bool getCastleK() const { return castleK; }
   bool getCastleQ() const { return castleQ; }
   bool isWhiteMove() const { return isWhite; }
   void setPromotion(char piece) { this->piece = piece; }
   void setCapture(char capture) { this->capture = capture; }
   void setEnPassant(bool enpassant) { this->enpassant = enpassant; }
   void setCastleK(bool castleK) { this->castleK = castleK; }
   void setCastleQ(bool castleQ) { this->castleQ = castleQ; }
   void setWhiteMove(bool isWhite) { this->isWhite = isWhite; }
   void assign(const Move& move) {}
   void assign(const std::string& move) {}

private:
   Position source;
   Position dest;
   char piece;
   char capture;
   bool enpassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   std::string error;
};

std::ostream& operator<<(std::ostream& out, const Move& move);
