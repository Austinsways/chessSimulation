#include "game.h"
#include "move.h"
#include <set>
using namespace std;

//this is the advance to make a move
void Game::advance(Interface* pUI) {
	//first we check if a piece is selected, if one isn't then we dont do anything. 
	if (!(pUI->getSelectPosition() >= 0 && pUI->getSelectPosition() <= 63)) {
		
		return;
	}

	
	
	//this will only fire when you first select a piece.
	if (pUI->getSelectPosition() != -1 && startPosition == -2) {
		Position colorCheck(pUI->getSelectPosition());
		//this makes it so you cannot select an item that isnt on your team.
		if (board.get(colorCheck).isWhite() == whiteTurn) {
			startPosition = pUI->getSelectPosition();
		}
	}
	

	//if start position has been initiated and we could potentially select a move...
	else {
		if (pUI->getSelectPosition() != startPosition) {
			desiredPosition = pUI->getSelectPosition();
		}
		else {
			return;
		}
		Position startingPosition(startPosition);
		if (board.get(startingPosition).isWhite() != whiteTurn) {
			return;
		}
		Position movingPosition(desiredPosition);
		Move desiredMovement(startingPosition, movingPosition, board.get(startingPosition).isWhite());
		//check if the piece is attempting to capture by seeing if the pieces are the same color
		if (board.get(movingPosition).isWhite() != board.get(startingPosition).isWhite()) {
			//if they're not the same color, allow a capture. the getmoves function will decide if the piece can actually capture or not. 
			desiredMovement.setCapture(board.get(desiredPosition).getLetter());
		}

		list<Move> moves = board.get(startingPosition).getMoves(board);
		bool valid = false;
		for (auto move : moves)
		{
			if (move.getText() == desiredMovement.getText()) {
				valid = true;
			}
		}


		if (valid) {
			board.move(desiredMovement);
			startPosition = -2;
			//switch turns each time a player moves.
			whiteTurn = whiteTurn ? false : true; 
		}
		else {
			startPosition = pUI->getSelectPosition();
		}
	}

};

//this draws the board.
void Game::draw(Interface* pUI) {
	
	
	board.draw(pUI);
};

void Game::checkWin() {
	board.checkWin();
}