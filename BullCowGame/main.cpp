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
	while (!BCGame.IsGameWon() && BCGame.GeCurrentTry() <= BCGame.GetMaxTries()) {
		Guess = getGuess();
		if (!Guess.empty()) {
			BullCowCount BullCowCount = BCGame.CheckGuessValidity(Guess);
			std::cout << "Bulls. " << BullCowCount.Bulls << " Cows. " << BullCowCount.Cows << std::endl;
		}
		else {
			printText(ErrorMessageNoGuess);
		}
		std::cout << std::endl;
		
	}

	PrintGameSummary();
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

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "Game was won!" << std::endl;
	}
	else {
		std::cout << "Better luck next time!" << std::endl;
	}
}

FText getGuess() {
	EWordStatus status;
	FText Guess = "";
	do {

		std::cout << "Try " << BCGame.GeCurrentTry() << " guess: ";
		std::getline(std::cin, Guess);

		status = BCGame.CheckGuess(Guess);
		switch (status) {
		case EWordStatus::NOT_ISOGRAM:
			std::cout << "Please enter a valid isogram" << std::endl;
			break;
		case EWordStatus::NOT_LOWERCASE:
			std::cout << "Please enter words with only lowercase characters" << std::endl;
			break;
		case EWordStatus::WRONG_LENGTH:
			std::cout << "Please enter word with " << BCGame.GetHiddenWordLength() << " letters" << std::endl;
			break;
		case EWordStatus::OK:
			BCGame.SetGameWon(true);
			break;
		default:
			break;
		}
	} while (status != EWordStatus::OK);
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
		std::cout << "Do you want to play again?Y/N - ";
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
