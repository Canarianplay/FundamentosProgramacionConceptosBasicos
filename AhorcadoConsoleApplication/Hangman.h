#ifndef HANGMAN_HPP
#define HANGMAN_HPP


using namespace std;

#include <string>
#include <vector>
#include "GameElement.h"

//Clase que representa el ahorcado
class Hangman : public GameElement
{
private:

	int numGuess;

public:

	Hangman();
	~Hangman();

	void draw() const override;

	void AddGuess();

	bool isGameOver();

	int getNumGuessed();
};
#endif // !HANGMAN_HPP
