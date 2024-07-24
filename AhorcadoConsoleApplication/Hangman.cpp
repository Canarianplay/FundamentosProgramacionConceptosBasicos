#include "Hangman.h"

Hangman::Hangman() : GameElement(""), numGuess(0) {};
Hangman::~Hangman() {};

void Hangman::draw() const
{
	vector<string> hangman = {
	  "  +---+",
	  "  |   |",
	  "      |",
	  "      |",
	  "      |",
	  "      |",
	  "========="
	};

	if (numGuess >= 1) hangman[2] = "  |   o";
	if (numGuess >= 2) hangman[3] = "  |   |";
	if (numGuess >= 3) hangman[3] = "  |  /|";
	if (numGuess >= 4) hangman[3] = "  |  /|\\";
	if (numGuess >= 5) hangman[4] = "  |  /";
	if (numGuess == 6) hangman[4] = "  |  / \\";


	for (string line : hangman) {
		cout << line << endl;
	}
}

void Hangman::AddGuess()
{
	numGuess++;
}

bool Hangman::isGameOver()
{
	return numGuess >= 6;
}

int Hangman::getNumGuessed() {
	return numGuess;
}