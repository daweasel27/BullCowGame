#include "FGlobalVariables.h"
#include "main.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame BCGame;

int main() 
{
	bool playAgain = false;
	do {
		printIntro();
		playGame();
		playAgain = askToPlayAgain();
	} while (playAgain);
	
	return 0;
}

void playGame()
{
	BCGame.Reset();

	FText Guess = "";
	FText ErrorMessageNoGuess = "There was no Guess, please input text!";
	for (int32 i = 0; i < BCGame.GetMaxTries(); i++) {
		Guess = getGuess();
		if (!Guess.empty()) {
			BCGame.CheckGuessValidity(Guess);
			printText(Guess);
		}
		else {
			printText(ErrorMessageNoGuess);
		}
		std::cout << std::endl;
	}

	//While
	/*
	int tries = 0;
	while (tries < NUMBER_OF_TRIES) {
		tries++;
		printGuess(getGuess());
		std::cout << endl;
	}
	*/
}
;

FText getGuess() {
	FText Guess = "";

	std::cout << "Try " << BCGame.GeCurrentTry() << " guess: ";
	std::getline(std::cin, Guess);
	
	return Guess;
}

void printText(FText Guess) {
	std::cout << Guess << std::endl;
}

void printIntro() {
	std::cout << "Welcome to bows and cows.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram i'm thinking of?\n";
}

bool askToPlayAgain() {
	FText response = "";
	while (response[0] != 'y' || response[0] != 'Y' || response[0] != 'N' || response[0] != 'n') {
		std::cout << "Do you want to play again?Y/N\n";
		std::getline(std::cin, response);
		if (response[0] == 'y' || response[0] == 'Y') {
			return true;
		}
		else if (response[0] == 'n' || response[0] == 'N') {
			return false;
		}
	}
	return false; 

}
