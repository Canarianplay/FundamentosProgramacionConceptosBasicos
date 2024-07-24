#pragma once
#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Question
{
private:

	string question;
	string answer;

public:

	//Constructor
	Question(const string& q, const string& a);

	//Destructor
	~Question();

	//Obtencion de la pregunta (question) (método get)
	const string& getQuestion();

	//Obtencion de la respuesta (answer) (método get)
	const string& getAnswer();

	//check de la respuesta (answer)
	bool checkAnswer(const string& userAnswer);
};
#endif // !QESTION_HPP
