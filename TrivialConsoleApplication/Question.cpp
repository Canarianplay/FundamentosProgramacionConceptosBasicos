#include "Question.h"


//Constructor
Question::Question(const string& q, const string& a) : question(q), answer(a) {};

//Destructor
Question::~Question() {};

//Obtencion de la pregunta (question) (método get)
const string& Question::getQuestion()
{
	return question;
}

//Obtencion de la respuesta (answer) (método get)
const string& Question::getAnswer()
{
	return answer;
}

//check de la respuesta (answer)
bool Question::checkAnswer(const string& userAnswer)
{
	//Metemos tratamiento de errores
	string lowerUserAnswer = "";
	try
	{
		lowerUserAnswer = userAnswer;
		transform(lowerUserAnswer.begin(), lowerUserAnswer.end(), lowerUserAnswer.begin(), ::tolower);

		if (userAnswer == answer)
		{
			return true;
		}
		else
		{
			throw invalid_argument("Respuesta incorrecta");
		}
	}
	catch (const exception& ex)
	{
		cerr << "Error:" << ex.what() << endl;
		return false;
	}


	return lowerUserAnswer == answer;
}