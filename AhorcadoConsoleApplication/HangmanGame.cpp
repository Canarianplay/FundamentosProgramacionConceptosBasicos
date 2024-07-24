#include "HangmanGame.h"

bool HangmanGame::isGameFinished()
{
	return guessed == wordToGuess.getWord() || hangman.isGameOver();
}

void HangmanGame::printGameState()
{
	cout << "Palabra: " << guessed << endl;
	cout << "Numero de intentos restantes: " << maxGuesses - hangman.getNumGuessed() << endl;
	hangman.draw();
}

void HangmanGame::checkLetter(char letter)
{
	try
	{
		if (!isalpha(letter))
		{
			throw invalid_argument("Caracter invalida!!...Solo se permiten letras");
		}

		if (wordToGuess.contains(letter))
		{
			for (int i = 0; i <= wordToGuess.getWord().length(); i++)
			{
				if (wordToGuess.getWord()[i] == letter)
				{
					guessed[i] = letter;
				}
			}
		}
		else
		{
			hangman.AddGuess();
			cout << "La letra es incorrecta" << endl;
		}
	}
	catch (const exception& ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
}

void HangmanGame::printGameResult()
{
	if (!hangman.isGameOver())
	{
		cout << "Ganaste pequeño platano, la palabra era: " << wordToGuess.getWord() << endl;
	}
	else
	{
		cout << "Perdites pequeño platano, la palabra era: " << wordToGuess.getWord() << endl;
	}
}


HangmanGame::HangmanGame(const string& word, int maxguesses) : wordToGuess(word), guessed(word.length(), '_'), maxGuesses(maxguesses) {};
HangmanGame::~HangmanGame() {};

void HangmanGame::play()
{
	while (!isGameFinished())
	{
		printGameState();
		char letter;
		cout << "Introduzca una letra" << endl;
		cin >> letter;
		checkLetter(letter);
	}

	printGameResult();
}