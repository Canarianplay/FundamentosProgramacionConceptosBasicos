#include "WordToGuess.h"

//Constructor
WordToGuess::WordToGuess(const string& w) : GameElement(""), word(w) {};
//Destructor
WordToGuess::~WordToGuess() {};

bool WordToGuess::contains(char letter) const
{
	return word.find(letter) != string::npos;
}

string WordToGuess::getWord() const {
	return word;
}