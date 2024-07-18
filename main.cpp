// Card game program using classes

#include <iostream>
#include "graph1.h"
#include "CardPlayer.h"
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;
int main()
{
	//Variable Declaration/Initialization
	int noCards = 0;
	int wagerAmt = 0;
	char color;
	CardPlayer player1;
	CardPlayer dealer;

	char repeat;

	srand(time(0));
	//Display Graphics
	displayGraphics();
	//Prompt for the suit color
	do {
		cout << "Enter the suit color (r for red suits, b for black suits): ";
		cin >> color;
		if (color != 'r' && color != 'b') {
			cout << "Please enter r or b!" << endl;
		}
	} while (color != 'r' && color != 'b');

	//Set the color
	if (color == 'r')
	{
		player1.setColorV(color);
		dealer.setColorV('b');
	} else{
		player1.setColorV('b');
		dealer.setColorV('r');

	}

	do {


		cout << "Enter the number of cards to deal to each player (>= 5 but <= 10): ";
		cin >> noCards;
		player1.setNoCards(noCards);
		dealer.setNoCards(noCards);

		cout << "Enter the wager <>=5 but <= 100: ";
		cin >> wagerAmt;
		player1.setWager(wagerAmt);

		player1.deal();
		dealer.deal();

		dealer.displayHand(250, 115);
		player1.displayHand(150, 115);

		std::this_thread::sleep_for(std::chrono::seconds(3));

		player1.sort();
		dealer.sort();

		dealer.displayHand(250, 115);
		player1.displayHand(150, 115);


		int playerScore = player1.computeScore();
		int dealerScore = dealer.computeScore();
		bool playerWon = false;
		bool tie = false;
		if (playerScore > dealerScore) {
			playerWon = true;
		}

		if (playerScore == dealerScore) {
			tie = true;
		}

		gout << setPos(150, 410) << "Score: " << playerScore << endg;
		gout << setPos(250, 410) << "Score: " << dealerScore << endg;

		if (tie != true) {
			if (playerWon == true) {
				gout << setPos(150, 425) << "You Win This Amount: " << player1.getWager() << endg;


			}
			else if (playerWon == false) {
				gout << setPos(150, 425) << "You Lose This Amount: " << player1.getWager() << endg;

			}
		}
		else {
			gout << setPos(150, 440) << "It's A Tie!"<< endg;

		}


		gout << setPos(150, 440) << "Accumulated Winnings (-Losses): " << player1.accumulateWinnings(playerWon, tie) << endg;

		char wildC;
		do {
			cout << "Do you want to play the Wild Card Round (Double or Nothing)?: (y/n): ";
			cin >> wildC;
		} while (toupper(wildC) != 'Y' && toupper(wildC) != 'N');

		if (wildC == 'y') {
			clearText();
			player1.genWildCard();
			dealer.genWildCard();
			player1.displayWildCard(150, 5);
			dealer.displayWildCard(250, 5);

			std::this_thread::sleep_for(std::chrono::seconds(3));


			playerScore += player1.computeWildCardScore();
			dealerScore += dealer.computeWildCardScore();

			int i = player1.binarySearch(player1.getWildCard());

			// means its found
			if (i != -1) {
				playerScore += 10;
			}

			i = dealer.binarySearch(dealer.getWildCard());
			if (i != -1) {
				dealerScore += 10;
			}



			playerWon = false;
			tie = false;

			if (playerScore > dealerScore) {
				playerWon = true;
			}

			if (playerScore == dealerScore) {
				tie = true;
			}

			gout << setPos(150, 410) << "Score: " << playerScore << endg;
			gout << setPos(250, 410) << "Score: " << dealerScore << endg;

			if (tie != true) {
				if (playerWon == true) {
					gout << setPos(150, 425) << "You Win This Amount: " << player1.getWager() << endg;


				}
				else if (playerWon == false) {
					gout << setPos(150, 425) << "You Lose This Amount: " << player1.getWager() << endg;

				}
			} else {
				gout << setPos(150, 440) << "It's A Tie!" << endg;

			}

			gout << setPos(150, 440) << "Accumulated Winnings (-Losses): " << player1.accumulateWinnings(playerWon, tie) << endg;


		}


		cout << "Repeat? (y/n): ";
		cin >> repeat;

		clearGraphics();
	}while (toupper(repeat) == 'Y');




}
