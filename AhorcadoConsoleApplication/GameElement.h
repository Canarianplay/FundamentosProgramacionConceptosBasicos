#ifndef GAMEELEMENT_HPP
#define GAMEELEMENT_HPP

#include <string>
#include <iostream>
#include "Drawable.h"

using namespace std;

//clase base o clase padre o super clase que reprensenta un elemento del juego
class GameElement : public Drawable
{
protected:

	string representation;

public:

	GameElement(const string& represent);
	~GameElement();

	void draw() const override;
};

#endif // !GAMEELEMENT_HPP
