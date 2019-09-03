#include "FBullCowGame.h"
#include "FGlobalVariables.h"
FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GeCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	MyMaxTries = NUMBER_OF_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuess(FString guess)
{
	return EWordStatus::OK;
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
	std::cout << BullCowCount.Bulls << std::endl;

	std::cout << BullCowCount.Cows << std::endl;

	return BullCowCount;
}
