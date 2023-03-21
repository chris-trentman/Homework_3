/*This program runs a new version of the card game, War.  In this game, the player will play 
against the computer.  A card will be drawn by each game participant (player and 
computer).  The winner of the round will get to keep both cards.  The new rules for this are 
each player can peek at their card and decide to pull an additional card out of a pile on the 
side or push this card onto a pile on the side.  Should the participant push the card, they will 
draw a new card from their deck and only be able to play that one card this round.  Should 
the participant pull a card from their side pile, they must play both cards this round.  The 
winner of the round is determined by the sum of the face value of the cards being higher 
than the opponent.  Ties go to the computer.  If a participant runs out of cards in their deck, 
they must play cards from their side pile.  If a participant runs out of cards in there deck and 
side pile, they lose.  */

#include <iostream>
#include "SidePile.h"
#include "Deck.h"
#include <random>
#include <time.h>

using namespace std;

const int DECK_SIZE = 52;
int main()
{
	system("Color 0A");
	//the player will play against the computer.
	Deck playerDeck;
	SidePile playerSidePile;
	Deck compDeck;
	SidePile compSidePile;
	int l = -1;
	//the computer has a great memory and keeps track of what cards are in its side pile
	int copyCompSidePile[SIZE];


	/*srand(time(0));
	//create a deck to shuffle and divide among player and computer
	int deck[DECK_SIZE] = { 0 };
	//Aces count as 1s!
	int faceValue = 1;
	int j = -1;
	for (int i = 0; i < DECK_SIZE; i += 4)
	{
		deck[i] = faceValue;
		deck[i + 1] = faceValue;
		deck[i + 2] = faceValue;
		deck[i + 3] = faceValue;
		faceValue++;
		j += 4;
	}
	int deckInd = -1;
	for (int i = 0; i < DECK_SIZE / 2; i++)
	{
		deckInd = static_cast<int>(rand() / static_cast<double>(RAND_MAX) * (j + 1));
		faceValue = deck[deckInd];
		playerDeck.replace(faceValue);
		for (int k = deckInd; k < j; k++)
		{
			deck[k] = deck[k + 1];
		}
		deck[j] = 0;
		j--;
		deckInd = static_cast<int>(rand() / static_cast<double>(RAND_MAX) * (j + 1));
		faceValue = deck[deckInd];
		compDeck.replace(faceValue);
		for (int k = deckInd; k < j; k++)
		{
			deck[k] = deck[k + 1];
		}
		deck[j] = 0;
		j--;
	}*/
	//Testing: computer deck will contain cards in ascending order 
	for (int i = 1; i <= DECK_SIZE/4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			compDeck.replace(i);
		}
	}
	//Testing: player deck will contain cards in ascending order
	for (int i = 1; i <= DECK_SIZE / 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			playerDeck.replace(i);
		}
	}
	//Testing: choose # of rounds
	cout << "Choose your game mode by entering the corresponding number:\n";
	cout << "1. # of rounds\n";
	cout << "2. until out of cards\n";
	int answer;
	cin >> answer;
	if (answer == 1)
	{
		//Testing: # of rounds will be 5
		cout << "How many rounds do you want to play? ";
		int numRounds;
		cin >> numRounds;
		cout << "Let the game of War begin!\n";
		int roundNum = 1;
		int compWins = 0;
		int playerWins = 0;
		
		while (roundNum <= numRounds && (playerDeck.getNumCards() != 0 || playerSidePile.getNumCards() != 0) && (compDeck.getNumCards() != 0 || compSidePile.getNumCards() != 0))
		{
			cout << "Round " << roundNum << ":\n";
			cout << "Do you want to see how many cards are in your deck? Enter 'Y' if so: ";
			char answer;
			cin >> answer;
			if (answer == 'Y')
			{
				cout << "The number of cards in your deck: " << playerDeck.getNumCards() << "\n";
			}
			cout << "Do you want to see how many cards are in your side pile? Enter 'Y' if so: ";
			cin >> answer;
			if (answer == 'Y')
			{
				cout << "The number of cards in your side pile: " << playerSidePile.getNumCards() << "\n";
			}
			cout << "Do you want to see how many cards are in the computer's deck? Enter 'Y' if so: ";
			cin >> answer;
			if (answer == 'Y')
			{
				cout << "The number of cards in the computer's deck: " << compDeck.getNumCards() << "\n";
			}
				//A card will be drawn by each game participant (player and computer).
			int playerCard = 0;
			int compCard = 0;
			if (playerDeck.getNumCards() == 0)
			{
				playerCard = playerSidePile.draw();
			}
			else
			{
				playerCard = playerDeck.draw();
			}

			if (compDeck.getNumCards() == 0)
			{
				compCard = compSidePile.draw();
			}
			else
			{
				compCard = compDeck.draw();
			}
			/*try {
				if (playerDeck.getNumCards() == 0)
				{
					throw Deck::DeckUnderflowException("Player can not draw from empty deck");
				}
				playerCard = playerDeck.draw();

			}
			
			catch (const Deck::DeckUnderflowException& e) {
				std::cerr << "Caught Deck Exception: " << e.what() << std::endl;
				playerCard = playerSidePile.draw();
			}
			
			try {
				if (compDeck.getNumCards() == 0)
				{
					throw Deck::DeckUnderflowException("Computer can not draw from empty deck");
				}
				compCard = compDeck.draw();
			}
			catch (const Deck::DeckUnderflowException& e) {
				std::cerr << "Caught Deck Exception: " << e.what() << std::endl;
				compCard=compSidePile.draw();
			}
			*/


			
			cout << "Drawing cards from deck...\n";
			//each player can peek at their card and decide to pull an additional card out of a pile on the side or push this card onto a pile on the side.
			cout << "Your card is " << playerCard << ".\n";
			int secondPlayerCard = 0;
			int secondCompCard = 0;

			if (playerSidePile.getNumCards() == 0 && playerDeck.getNumCards() == 0)
			{
			}
			else if (playerSidePile.getNumCards() == 0)
			{
				cout << "Do you want place this card onto your side pile and draw a new one from the deck? Enter 'Y' if so: ";
				char answer;
				cin >> answer;
				if (answer == 'Y')
				{
					playerSidePile.place(playerCard);
					playerCard = playerDeck.draw();
					cout << "Your new card is " << playerCard << ".\n";
				}
			}
			else if (playerDeck.getNumCards() == 0 || playerSidePile.getNumCards() == SIZE)
			{
				cout << "Do you want to draw an additional card out of your side pile? Enter 'Y' if so: ";
				char answer;
				cin >> answer;
				if (answer == 'Y')
				{
					secondPlayerCard = playerSidePile.draw();
					cout << "Your second card is " << secondPlayerCard << ".\n";
				}
			}
			else
			{
				cout << "Do you want to:\n1. draw an additional card out of your side pile,\n2. place this card onto it and draw a new one from the deck, or\n3. play this card?\nEnter the corresponding number: ";
				int answer;
				cin >> answer;
				switch (answer)
				{
				case 1:
				{
					secondPlayerCard = playerSidePile.draw();
					cout << "Your second card is " << secondPlayerCard << ".\n";
					break;
				}
				case 2:
				{
					playerSidePile.place(playerCard);
					playerCard = playerDeck.draw();
					cout << "Your new card is " << playerCard << ".\n";
					break;
				}
				default:
				{
					break;
				}
				}
			}
			/*Strategy: Put high cards in side pile whenever possible. Draw a card from side pile if card from deck is low.
if playing # of rounds mode, if you are winning, play conservatively. This means lowering the bar for high cards and middle cards.
If losing, play riskily. This means raising the bar for high cards and middle cards. If side pile is near full, play riskily. If side pile is near empty, play conservatively.
If near the end of the game and winning, play even more conservatively. If near the end of the game and losing, play even more riskily.*/
			int roundsRemaining = numRounds - roundNum+1;
			int highCard = 10;
			int middleCard = 5;
			if (compDeck.getNumCards() >= playerDeck.getNumCards())
			{
				//play conservatively.
				highCard--;
				middleCard--;
			}
			else
			{
				//play riskily.
				highCard++;
				middleCard++;
			}
			if (roundsRemaining <= 0.1 * numRounds)
			{
				//near the end of game
				if (compDeck.getNumCards() >= playerDeck.getNumCards())
				{
					//play conservatively.
					highCard--;
					middleCard--;
				}
				else
				{
					//play riskily.
					highCard++;
					middleCard++;
				}
			}
			if (compSidePile.getNumCards() == 0 && compDeck.getNumCards() == 0)
			{
				//must play card
			}
			else if (compSidePile.getNumCards() == 0)
			{
				//either play card of put card on side pile and draw new card
				
				//side pile empty, so play conservatively
				highCard--;
				middleCard--;
				if (compCard >= highCard)
				{
					//put high cards in side pile whenever possible
					compSidePile.place(compCard);
					l++;
					copyCompSidePile[l] = compCard;
					compCard = compDeck.draw();
				}
				else if (compCard >= middleCard)
				{
					//always play middle cards
				}
				else
				{
					//play low cards with card from side pile, if possible
				}

			}
			else if (compDeck.getNumCards() == 0 || compSidePile.getNumCards() == SIZE)
			{
				//(deck is empty and side pile not empty) or side pile is full. either way, Play riskily
				highCard++;
				middleCard++;
				if (compCard >= highCard)
				{
					//cannot put high card on side pile, so it must be played
				}
				else if (compCard >= middleCard)
				{
					//always play middle cards
				}
				else
				{
					//play low cards with card from side pile
					secondCompCard = compSidePile.draw();
					copyCompSidePile[l] = 0;
					l--;
				}
			}
			else
			{
				//deck is not empty and side pile is not empty and side pile is not full. 
				if (compSidePile.getNumCards() <= SIZE / 3)
				{
					//side pile low on cards. play conservatively.
					highCard--;
					middleCard--;
				}
				else if (compSidePile.getNumCards() > SIZE * 2 / 3)
				{
					//side pile high on cards. play riskily.
					highCard++;
					middleCard++;
				}
				if (compCard >= highCard)
				{
					answer = 1;
				}
				else if (compCard < middleCard)
				{
					answer = 2;
				}
				else
				{
					answer = 3;
				}
				switch (answer)
				{
				case 1:
				{
					secondCompCard = compSidePile.draw();
					break;
				}
				case 2:
				{
					compSidePile.place(compCard);
					compCard = compDeck.draw();
					break;
				}
				default:
				{
					break;
				}
				}
			}
			cout << "Player plays " << playerCard << ".\n";
			if (secondPlayerCard != 0)
			{
				cout << "Player also plays " << secondPlayerCard << ".\n";
			}
			cout << "Computer plays " << compCard << ".\n";
			if (secondCompCard != 0)
			{
				cout << "Computer also plays " << secondCompCard << ".\n";
			}
			//The winner of the round will get to keep both cards.
			if (playerCard + secondPlayerCard > compCard + secondCompCard)
			{
				playerDeck.replace(playerCard);
				playerDeck.replace(compCard);
				if (secondPlayerCard != 0)
				{
					playerDeck.replace(secondPlayerCard);
				}
				if (secondCompCard != 0)
				{
					playerDeck.replace(secondCompCard);
				}
				playerWins++;
				cout << "Player wins the round.\n";
			}
			else
			{
				compDeck.replace(playerCard);
				compDeck.replace(compCard);
				if (secondPlayerCard != 0)
				{
					compDeck.replace(secondPlayerCard);
				}
				if (secondCompCard != 0)
				{
					compDeck.replace(secondCompCard);
				}
				compWins++;
				cout << "Computer wins the round.\n";
			}
			roundNum++;
		}
		cout << "Game over. Player won " << playerWins << " rounds. Computer won " << compWins << " rounds.\n";
		if (playerWins > compWins)
		{
			cout << "Player wins the game!\n";
		}
		else
		{
			cout << "Computer wins the game!\n";
		}
	}
	else
	{
	while ((playerDeck.getNumCards() != 0 || playerSidePile.getNumCards() != 0) && (compDeck.getNumCards() != 0 || compSidePile.getNumCards() != 0))
	{
		cout << "Do you want to see how many cards are in your deck? Enter 'Y' if so: ";
		char answer;
		cin >> answer;
		if (answer == 'Y')
		{
			cout << "The number of cards in your deck: " << playerDeck.getNumCards() << "\n";
		}
		cout << "Do you want to see how many cards are in your side pile? Enter 'Y' if so: ";
		cin >> answer;
		if (answer == 'Y')
		{
			cout << "The number of cards in your side pile: " << playerSidePile.getNumCards() << "\n";
		}
		cout << "Do you want to see how many cards are in the computer's deck? Enter 'Y' if so: ";
		cin >> answer;
		if (answer == 'Y')
		{
			cout << "The number of cards in the computer's deck: " << compDeck.getNumCards() << "\n";
		}
		//A card will be drawn by each game participant (player and computer).
		int playerCard = 0;
		int compCard = 0;
		if (playerDeck.getNumCards() == 0)
		{
			playerCard = playerSidePile.draw();
		}
		else
		{
			playerCard = playerDeck.draw();
		}

		if (compDeck.getNumCards() == 0)
		{
			compCard = compSidePile.draw();
		}
		else
		{
			compCard = compDeck.draw();
		}

		/*try {
			if(playerDeck.getNumCards()==0)
				throw Deck::DeckUnderflowException("Player can not draw from empty deck");
			playerCard = playerDeck.draw();
			
		}
		catch(const Deck::DeckUnderflowException& e) {
			std::cerr << "Caught Deck Exception: " << e.what() << std::endl;
			playerCard=playerSidePile.draw();
		}
		try {
		if (compDeck.getNumCards() == 0)
			throw Deck::DeckUnderflowException("Computer can not draw from empty deck");
			compCard = compDeck.draw();
		}
		catch (const Deck::DeckUnderflowException& e) {
			std::cerr << "Caught Deck Exception: " << e.what() << std::endl;
			compCard=compSidePile.draw();
		}*/

		cout << "Drawing a card from each deck...\n";
		//each player can peek at their card and decide to pull an additional card out of a pile on the side or push this card onto a pile on the side.
		cout << "Your card is " << playerCard << ".\n";
		int secondPlayerCard = 0;
		int secondCompCard = 0;

		if (playerSidePile.getNumCards() == 0 && playerDeck.getNumCards() == 0)
		{
		}
		else if (playerSidePile.getNumCards() == 0)
		{
			cout << "Do you want place this card onto your side pile and draw a new one from the deck? Enter 'Y' if so: ";
			char answer;
			cin >> answer;
			if (answer == 'Y')
			{
				playerSidePile.place(playerCard);
				playerCard = playerDeck.draw();
				cout << "Your new card is " << playerCard << ".\n";
			}
		}
		else if (playerDeck.getNumCards() == 0 || playerSidePile.getNumCards() == SIZE)
		{
			cout << "Do you want to draw an additional card out of your side pile? Enter 'Y' if so: ";
			char answer;
			cin >> answer;
			if (answer == 'Y')
			{
				secondPlayerCard = playerSidePile.draw();
				cout << "Your second card is " << secondPlayerCard << ".\n";
			}
		}
		else
		{
			cout << "Do you want to:\n1. draw an additional card out of your side pile,\n2. place this card onto it and draw a new one from the deck, or\n3. play this card?\nEnter the corresponding number: ";
			int answer;
			cin >> answer;
			switch (answer)
			{
			case 1:
			{
				secondPlayerCard = playerSidePile.draw();
				cout << "Your second card is " << secondPlayerCard << ".\n";
				break;
			}
			case 2:
			{
				playerSidePile.place(playerCard);
				playerCard = playerDeck.draw();
				cout << "Your new card is " << playerCard << ".\n";
				break;
			}
			default:
			{
				break;
			}
			}
		}

		/*Strategy: Put high cards in side pile whenever possible. Draw a card from side pile if card from deck is low.
if playing until out of cards mode, if you are winning, play conservatively. This means lowering the bar for high cards and middle cards.
If losing, play riskily. This means raising the bar for high cards and middle cards. If side pile is near full, play riskily. If side pile is near empty, play conservatively*/
		int highCard = 10;
		int middleCard = 5;
		if (compDeck.getNumCards() >= playerDeck.getNumCards())
		{
			//winning, so play conservatively
			highCard--;
			middleCard--;
		}
		else
		{
			//losing, so play riskily
			highCard++;
			middleCard++;
		}
		if (compSidePile.getNumCards() == 0 && compDeck.getNumCards() == 0)
		{
			//must play card in hand
		}
		else if (compSidePile.getNumCards() == 0)
		{
			//side pile empty, so play conservatively
			highCard--;
			middleCard--;
			if (compCard >=highCard)
			{
				//put high cards in side pile whenever possible
				compSidePile.place(compCard);
				l++;
				copyCompSidePile[l] = compCard;
				compCard = compDeck.draw();
			}
			else if (compCard >= middleCard)
			{
				//always play middle cards
			}
			else
			{
				//play low cards with card from side pile, if possible
			}
		}
		else if (compDeck.getNumCards() == 0 || compSidePile.getNumCards() == SIZE)
		{
			//(deck is empty and side pile not empty) or side pile is full. either way, Play riskily
			highCard++;
			middleCard++;
			if (compCard >= highCard)
			{
				//cannot put high card on side pile, so it must be played
			}
			else if (compCard >= middleCard)
			{
				//always play middle cards
			}
			else
			{
				//play low cards with card from side pile
				secondCompCard = compSidePile.draw();
				copyCompSidePile[l] = 0;
				l--;
			}
		}
		else
		{
			//deck is not empty and side pile is not empty and side pile is not full. 
			if (compSidePile.getNumCards() <= SIZE / 3)
			{
				//side pile low on cards. play conservatively.
				highCard--;
				middleCard--;
			}
			else if (compSidePile.getNumCards() > SIZE * 2 / 3)
			{
				//side pile high on cards. play riskily.
				highCard++;
				middleCard++;
			}
			if (compCard >= highCard)
			{
				answer = 1;
			}
			else if (compCard<middleCard)
			{
				answer = 2;
			}
			else
			{
				answer = 3;
			}
			switch (answer)
			{
			case 1:
			{
				secondCompCard = compSidePile.draw();
				break;
			}
			case 2:
			{
				compSidePile.place(compCard);
				compCard = compDeck.draw();
				break;
			}
			default:
			{
				break;
			}
			}
		}
		cout << "Player plays " << playerCard << ".\n";
		if (secondPlayerCard != 0)
		{
			cout << "Player also plays " << secondPlayerCard << ".\n";
		}
		cout << "Computer plays " << compCard << ".\n";
		if (secondCompCard != 0)
		{
			cout << "Computer also plays " << secondCompCard << ".\n";
		}
		//The winner of the round will get to keep both cards.
		if (playerCard + secondPlayerCard > compCard + secondCompCard)
		{
			playerDeck.replace(playerCard);
			playerDeck.replace(compCard);
			if (secondPlayerCard != 0)
			{
				playerDeck.replace(secondPlayerCard);
			}
			if (secondCompCard != 0)
			{
				playerDeck.replace(secondCompCard);
			}
			cout << "Player wins the round.\n";
		}
		else
		{
			compDeck.replace(playerCard);
			compDeck.replace(compCard);
			if (secondPlayerCard != 0)
			{
				compDeck.replace(secondPlayerCard);
			}
			if (secondCompCard != 0)
			{
				compDeck.replace(secondCompCard);
			}
			cout << "Computer wins the round.\n";
		}
	}
	cout << "Game over.\n";
	if ((playerDeck.getNumCards() != 0 || playerSidePile.getNumCards() != 0))
	{
		cout << "Player wins the game!\n";
	}
	else
	{
		cout << "Computer wins the game!\n";
	}
 }
	return 0;
}