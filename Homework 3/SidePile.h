#pragma once
const int SIZE = 5;
class SidePile
{
private:
	int sidePile[SIZE];
	int top;
	int numCards;
	class SidePileUnderflowException{
	};
	class SidePileOverflowException {
	};
public:
	SidePile();

	int getNumCards() {
		return numCards;
	}
	int draw();
	void place(int topCard);
	
};

