#pragma once
#include "FIncludes.h"

using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EWordStatus
{
	OK,
	NOT_ISOGRAM
};

enum EResetStatus
{
	NO_HIDDEN_WORD,
	OK
};

class FBullCowGame {
public: 
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GeCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	void Reset();
	EWordStatus CheckGuess(FString);
	BullCowCount CheckGuessValidity(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};