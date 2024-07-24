#pragma once
#ifndef SPORTQUIZ_HPP
#define SPORTQUIZ_HPP


#include "Quiz.h"
#include <stdexcept>

using namespace std;

//Clase derivada para un tema especifico (Deporte) (herencia)
class SportQuiz : public Quiz
{
public:

	//Constructor
	SportQuiz();

	//Destructor
	~SportQuiz();


	void printGameResult() override;
};
#endif // !SPORTQUIZ_HPP

