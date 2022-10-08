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

	string text = "";
	text+=(char)('a' + source.getCol());
	text += (char)('1' + source.getRow());

	text += (char)('a' + dest.getCol());
	text += (char)('1' + dest.getRow());

	if (capture) {
		text += capture;
	}

	return text;

	//	row = source / 8;
	//col = source % 8;

	//text = text + ('a' + col); // concatenate a character according to row
	//text = text + tostr(row); // concatenate the row as a character

	//row = dest / 8;
	//col = dest % 8;

	//text = text + ('a' + col); // concatenate a character according to row
	//text = text + tostr(row); // concatenate the row as a character

	//return text;
 //  return "";
}

ostream& operator<<(ostream& out, const Move& move)
{
   out << move.getText();
   return out;
}
