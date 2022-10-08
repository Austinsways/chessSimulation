/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "move.h"

#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const Move& move)
{
   out << move.getText();
   return out;
}