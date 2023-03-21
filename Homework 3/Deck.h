#pragma once
#include <exception>
#include <string>
#include <iostream>
using namespace std;
class Deck
{
private:
	struct Card {
		int faceValue;
		Card* next;
	};
	
	Card* top;
	
	Card* bottom;
	
	int numCards;
	

	

public:
	Deck();

	int draw();

	void replace(int bottomFaceValue);

	int getNumCards()
	{
		return numCards;
	}

	class DeckUnderflowException :public exception {
	public:
		DeckUnderflowException(const char* message) : msg_(message) {}
		const char* what() const noexcept { return msg_.c_str(); }
	private:
		string msg_;

	};
};

