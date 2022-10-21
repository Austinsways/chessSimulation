/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include "uiInteract.h"
#include "board.h"

class Game
{
public:
	Game() {
		startPosition = -2;
		board.reset();
	}
	void advance(Interface* pUI);
	void draw(Interface* pUI); 
	void checkWin();
	bool getWhiteTurn() { return whiteTurn; };

private:
	bool whiteTurn = true;
	Board board;
	int startPosition;
	int desiredPosition;
};