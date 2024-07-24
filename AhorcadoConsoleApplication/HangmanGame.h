#ifndef HANGMAN_GAME_HPP
#define HANGMAN_GAME_HPP

#include "Hangman.h"
#include "WordToGuess.h"

using namespace std;

//Clase que representa el juego del Ahorcado
class HangmanGame
{
private:

	WordToGuess wordToGuess;
	string guessed;
	Hangman hangman;
	int maxGuesses;

private:

	bool isGameFinished();

	void printGameState();

	void checkLetter(char letter);

	void printGameResult();

public:

	HangmanGame(const string& word, int maxguesses);
	~HangmanGame();

	void play();
};
#endif // !HANGMAN_GAME_HPP
