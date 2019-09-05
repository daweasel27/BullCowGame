#include "FBullCowGame.h"
#include "FGlobalVariables.h"
FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GeCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return GameIsWon; }

void FBullCowGame::Reset()
{
	MyMaxTries = NUMBER_OF_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	GameIsWon = false;
}

void FBullCowGame::SetGameWon(bool GameWon)
{
	GameIsWon = GameWon;
}

EWordStatus FBullCowGame::CheckGuess(FString guess)
{
	for (size_t i = 0; i < guess.length(); i++)
	{
		if (!islower(guess[i])) {
			return EWordStatus::NOT_LOWERCASE;
		}
		for (size_t j = 0; j < guess.length(); j++)
		{
			if (i == j) continue;

			if (guess[i] == guess[j]) {
				return EWordStatus::NOT_ISOGRAM;
			}

		}
	}
	if (GetHiddenWordLength() != guess.length()) {
		return EWordStatus::WRONG_LENGTH;
	}
	else {
		return EWordStatus::OK;
	}
}

BullCowCount FBullCowGame::CheckGuessValidity(FString guess)
{
	MyCurrentTry++;
	bool IsValid = true;
	BullCowCount BullCowCount;

	for (int32 i = 0; i < guess.length(); i++)
	{
		if (MyHiddenWord[i] == guess[i]) 
		{
			BullCowCount.Bulls++;
		}
		else {
			for (int32 y = 0; y < GetHiddenWordLength(); y++)
			{
				if (y == i) continue;
				if (MyHiddenWord[i] == guess[y]) 
				{
					BullCowCount.Cows++;
					break;
				}
			}
		}
	}		

	if (BullCowCount.Bulls == WORD_LENGHT) {
		SetGameWon(true);
	}
	else {
		SetGameWon(false);
	}
	return BullCowCount;
}
