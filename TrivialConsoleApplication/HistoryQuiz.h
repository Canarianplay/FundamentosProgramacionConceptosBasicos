#pragma once
#ifndef HISTORY_QUIZ
#define HISTORY_QUIZ

#include "Quiz.h"
#include <stdexcept>

using namespace std;

//Clase dereivdada para un tema especifico (Historia) (herencia)
class HistoryQuiz : public Quiz
{

public:

	//Constructor
	HistoryQuiz();

	//Destructor
	~HistoryQuiz();

	void printGameResult() override;

};
#endif // !HISTORY_QUIZ

