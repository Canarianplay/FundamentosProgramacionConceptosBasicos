#pragma once
#ifndef QUIZ_HPP
#define QUIZ_HPP

#include "Game.h"
#include "Question.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Quiz : public Game
{
protected:
	int score;
	vector<Question> questions;

public:

	//Constructor
	Quiz();

	//Destructor
	virtual ~Quiz();

	//Añadir question (Add)
	void addQuestion(const Question& question);

	//Jugamos
	void playGame() override;
};
#endif // !QUIZ_HPP

