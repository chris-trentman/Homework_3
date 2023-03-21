#include "SidePile.h"
SidePile::SidePile() {
	//stack with size 5
	for (int card : sidePile)
	{
		card = 0;
	}
	top = -1;
	numCards = 0;
}
int SidePile::draw()
{
	if (numCards == 0)
	{
		throw SidePileUnderflowException();
	}
	numCards--;
	int topCard = sidePile[top];
	top--;
	return topCard;
}
void SidePile::place(int topCard)
{
	//same as replace but places on top
	if (numCards == SIZE)
	{
		throw SidePileOverflowException();
	}
	top++;
	sidePile[top] = topCard;
	numCards++;
}