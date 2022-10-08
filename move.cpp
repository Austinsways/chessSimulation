/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "move.h"

#include <iostream>
#include <string>

using namespace std;

string Move::getText() const
{
   // TODO
   return "";
}

ostream& operator<<(ostream& out, const Move& move)
{
   out << move.getText();
   return out;
}