#ifndef WORD_TO_GUESS_HPP
#define WORD_TO_GUESS_HPP

#include <string>
#include "GameElement.h"

using namespace std;
//Clase para la palabra que tenemos que adivinar
class WordToGuess : public GameElement
{
private:

	string word;

public:

	//Constructor
	WordToGuess(const string& w);
	//Destructor
	~WordToGuess();

	bool contains(char letter) const;

	string getWord() const;
};

#endif // !WORD_TO_GUESS_HP