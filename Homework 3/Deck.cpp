#include "Deck.h"
Deck::Deck() {
	top = nullptr;
	bottom = nullptr;
	numCards = 0;
}

int Deck::draw() {
	int topFaceValue = top->faceValue;
	Card* topCardPtr = top;
	top = top->next;
	delete topCardPtr;
	numCards--;
	if (numCards == 0)
	{
		bottom = nullptr;
	}
	return topFaceValue;
}

void Deck::replace(int bottomFaceValue) {
	//puts a card on bottom of the deck  
	Card* bottomCardPtr = new Card;
	bottomCardPtr->faceValue = bottomFaceValue;
	if (numCards == 0)
	{
		top = bottomCardPtr;
	}
	else {
		bottom->next = bottomCardPtr;
	}
	bottom = bottomCardPtr;
	numCards++;
}