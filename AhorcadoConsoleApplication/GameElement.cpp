#include "GameElement.h"


GameElement::GameElement(const string& represent) : representation(represent) {};

GameElement::~GameElement() {};

void GameElement::draw() const
{
	cout << representation << endl;
}