#include <iostream>
#include "graph1.h"
#include "CardPlayer.h"

CardPlayer::CardPlayer()
{
	//Implement the default Constructor
	this->noCards = 0;
	this->hand = NULL;
	this->color = 'r';

}

CardPlayer::~CardPlayer()
{

	delete[] hand;
}

void CardPlayer::setNoCards(int noCards)
{
	if (noCards < 5) {
		this->noCards = 5;
	}
	else if (noCards > 10) {
		this->noCards = 10;
	}
	else {
		this->noCards = noCards;
	}

	hand = new int[this->noCards];

}

int CardPlayer::getNoCards()
{
	return noCards;
}

void CardPlayer::setColorV(char color)
{
	this->color = color;
}

void CardPlayer::setWager(int wager) {
	if (wager < 5) {
		this->wager = 5;
	}
	else if (wager > 100) {
		this->wager = 100;
	}
	else {
		this->wager = wager;
	}
	
}

int CardPlayer::getWager() {
	return wager;
}

void CardPlayer::deal()
{
	bool duplicate = false;
	for (int i = 0; i < noCards; i++)
	{
		hand[i] = rand() % 13 + 2;
		do
		{
			duplicate = false;
			for (int j = 0; j < i; j++)
			{
				if (hand[i] == hand[j])
				{
					hand[i] = rand() % 13 + 2;
					duplicate = true;
					break;
				}
			}
		} while (duplicate);
	}
}


// rand % (MAX + 1) + MIN 

void CardPlayer::genWildCard() {
	int card = rand() % 13 + 2;
	this->wildCard = card;
}

int CardPlayer::getWildCard() {
	return this->wildCard;
}

void CardPlayer::displayWildCard(int x, int y) {
	
	drawLine(0, 120, 20, 120, 1);
	

	
	int startX = 0; 
	int endX = 20;  
	int step = 40;  

	for (int i = 0; i < 30; i++) {
		drawLine(startX, 120, endX, 120, 1);
		startX += step;
		endX += step;
	}





	if (color == 'r') {
		// hearts
		if (this->wildCard == 2) {
			displayBMP("d2.bmp", x, y);
		}
		else if (this->wildCard == 3) {
			displayBMP("d3.bmp", x, y);
		}
		else if (this->wildCard == 4) {
			displayBMP("d4.bmp", x, y);
		}
		else if (this->wildCard == 5) {
			displayBMP("d5.bmp", x, y);
		}
		else if (this->wildCard == 6) {
			displayBMP("d6.bmp", x, y);
		}
		else if (this->wildCard == 7) {
			displayBMP("d7.bmp", x, y);
		}
		else if (this->wildCard == 8) {
			displayBMP("d8.bmp", x, y);
		}
		else if (this->wildCard == 9) {
			displayBMP("d9.bmp", x, y);
		}
		else if (this->wildCard == 10) {
			displayBMP("d10.bmp", x, y);
		}
		else if (this->wildCard == 11) {
			displayBMP("d11.bmp", x, y);
		}
		else if (this->wildCard == 12) {
			displayBMP("d12.bmp", x, y);
		}
		else if (this->wildCard == 13) {
			displayBMP("d13.bmp", x, y);
		}
		else if (this->wildCard == 14) {
			displayBMP("d14.bmp", x, y);
		}
	}
	else if (color = 'b') {
		// spaids
		if (this->wildCard == 2) {
			displayBMP("c2.bmp", x, y);
		}
		else if (this->wildCard == 3) {
			displayBMP("c3.bmp", x, y);
		}
		else if (this->wildCard == 4) {
			displayBMP("c4.bmp", x, y);
		}
		else if (this->wildCard == 5) {
			displayBMP("c5.bmp", x, y);
		}
		else if (this->wildCard == 6) {
			displayBMP("c6.bmp", x, y);
		}
		else if (this->wildCard == 7) {
			displayBMP("c7.bmp", x, y);
		}
		else if (this->wildCard == 8) {
			displayBMP("c8.bmp", x, y);
		}
		else if (this->wildCard == 9) {
			displayBMP("c9.bmp", x, y);
		}
		else if (this->wildCard == 10) {
			displayBMP("c10.bmp", x, y);
		}
		else if (this->wildCard == 11) {
			displayBMP("c11.bmp", x, y);
		}
		else if (this->wildCard == 12) {
			displayBMP("c12.bmp", x, y);
		}
		else if (this->wildCard == 13) {
			displayBMP("c13.bmp", x, y);
		}
		else if (this->wildCard == 14) {
			displayBMP("c14.bmp", x, y);
		}
	}
	
	gout << setPos(x, 115)  << "Wild Card" << endg;

}



int CardPlayer::computeWildCardScore() {
	int score{};

	for (int i = 0; i < noCards; i++) {
		if (this->wildCard == 2) {
			score = 2;
		}
		else if (this->wildCard == 3) {
			score = 3;
		}
		else if (this->wildCard == 4) {
			score = 4;
		}
		else if (this->wildCard == 5) {
			score = 5;
		}
		else if (this->wildCard == 6) {
			score = 6;
		}
		else if (this->wildCard == 7) {
			score = 7;
		}
		else if (this->wildCard == 8) {
			score = 8;
		}
		else if (this->wildCard == 9) {
			score = 9;
		}
		else if (this->wildCard == 10) {
			score = 10;
		}
		else if (this->wildCard == 11) {
			score = 10;
		}
		else if (this->wildCard == 12) {
			score = 10;
		}
		else if (this->wildCard == 13) {
			score = 10;
		}
		else if (this->wildCard == 14) {
			score = 11;
		}
	}

	return score;

}

void CardPlayer::sort()
{

	int n = 0;
	int k = 0;
	int sm_index = 0;
	int smallest = 0;
	int temp1 = 0;
	int temp2 = 0;

	for (k = 0; k < noCards - 1; k++)	       // size-1 = number of passes
	{
		smallest = hand[k];
		sm_index = k;

		for (n = k + 1; n < noCards; n++)    // size = # elem. to look at
		{
			if (hand[n] < smallest)
			{
				smallest = hand[n];
				sm_index = n;
			}
		}

		if (smallest < hand[k])
		{
			temp1 = hand[k];
			hand[k] = hand[sm_index];
			hand[sm_index] = temp1;
		}
	}

}


void CardPlayer::displayHand(int x, int y) {
	


	gout << setPos(150, 109) << "Player 1";

	gout << setPos(250, 109) << "Dealer";


	if (this->color == 'r') {

	
		for (int i = 0; i < noCards; i++) {
			if (i != 0) {
				y += 20;
			}
			if (hand[i] == 2) {
				displayBMP("d2.bmp", x, y);
			}
			else if (hand[i] == 3) {
				displayBMP("d3.bmp", x, y);
			}
			else if (hand[i] == 4) {
				displayBMP("d4.bmp", x, y);
			}
			else if (hand[i] == 5) {
				displayBMP("d5.bmp", x, y);
			}
			else if (hand[i] == 6) {
				displayBMP("d6.bmp", x, y);
			}
			else if (hand[i] == 7) {
				displayBMP("d7.bmp", x, y);
			}
			else if (hand[i] == 8) {
				displayBMP("d8.bmp", x, y);
			}
			else if (hand[i] == 9) {
				displayBMP("d9.bmp", x, y);
			}
			else if (hand[i] == 10) {
				displayBMP("d10.bmp", x, y);
			}
			else if (hand[i] == 11) {
				displayBMP("d11.bmp", x, y);
			}
			else if (hand[i] == 12) {
				displayBMP("d12.bmp", x, y);
			}
			else if (hand[i] == 13) {
				displayBMP("d13.bmp", x, y);
			}
			else if (hand[i] == 14) {
				displayBMP("d14.bmp", x, y);
			}




		}
	}else if (this->color == 'b') {
		for (int i = 0; i < noCards; i++) {
			if (i != 0) {
				y += 20;
			}
			if (hand[i] == 2) {
				displayBMP("c2.bmp", x, y);
			}
			else if (hand[i] == 3) {
				displayBMP("c3.bmp", x, y);
			}
			else if (hand[i] == 4) {
				displayBMP("c4.bmp", x, y);
			}
			else if (hand[i] == 5) {
				displayBMP("c5.bmp", x, y);
			}
			else if (hand[i] == 6) {
				displayBMP("c6.bmp", x, y);
			}
			else if (hand[i] == 7) {
				displayBMP("c7.bmp", x, y);
			}
			else if (hand[i] == 8) {
				displayBMP("c8.bmp", x, y);
			}
			else if (hand[i] == 9) {
				displayBMP("c9.bmp", x, y);
			}
			else if (hand[i] == 10) {
				displayBMP("c10.bmp", x, y);
			}
			else if (hand[i] == 11) {
				displayBMP("c11.bmp", x, y);
			}
			else if (hand[i] == 12) {
				displayBMP("c12.bmp", x, y);
			}
			else if (hand[i] == 13) {
				displayBMP("c13.bmp", x, y);
			}
			else if (hand[i] == 14) {
				displayBMP("c14.bmp", x, y);
			}

		}
	}
}


int CardPlayer::computeScore() {

	int score{};
	for (int i = 0; i < noCards; i++) {
		if (hand[i] == 2) {
			score += 2;
		}
		else if (hand[i] == 3) {
			score += 3;
		}
		else if (hand[i] == 4) {
			score += 4;
		}
		else if (hand[i] == 5) {
			score += 5;
		}
		else if (hand[i] == 6) {
			score += 6;
		}
		else if (hand[i] == 7) {
			score += 7;
		}
		else if (hand[i] == 8) {
			score += 8;
		}
		else if (hand[i] == 9) {
			score += 9;
		}
		else if (hand[i] == 10) {
			score += 10;
		}
		else if (hand[i] == 11) {
			score += 10;
		}
		else if (hand[i] == 12) {
			score += 10;
		}
		else if (hand[i] == 13) {
			score += 10;
		}
		else if (hand[i] == 14) {
			score += 11;
		}
	}

	return score;
}


int CardPlayer::binarySearch(int value){
	//Variable Declaration/Initialization
	int low = 0;
	int high = 0;
	int middle = 0;
	bool found = false;
	int index = -1;

	//Initialize low/high
	low = 0;
	high = noCards - 1;

	while ((low <= high) && (!found))
	{
		middle = (low + high) / 2;

		if (hand[middle] == value)
			found = true;
		else if (value > hand[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}

	if (!found)
	{
		index = -1;
	}
	else
	{
		index = middle;
	}
	return(index);

}


int CardPlayer::accumulateWinnings(bool win, bool tie) {
	if (tie != true) {
		if (win == true) {
			this->winnings += this->wager;
		}
		else {
			this->winnings -= this->wager;
		}
	}


	return this->winnings;
}


int CardPlayer::getTotalWinnings() {
	return this->winnings;
}