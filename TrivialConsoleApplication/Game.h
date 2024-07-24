#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

//Interfaz para el juego
class Game
{
public:

	virtual void playGame() = 0;
	virtual ~Game() {}

	virtual void printGameResult() = 0;

};

#endif // !GAME_HPP
