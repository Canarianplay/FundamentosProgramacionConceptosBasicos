#include "HistoryQuiz.h"


//Constructor
HistoryQuiz::HistoryQuiz()
{

	addQuestion(Question("Quien gano la segunda guerra mundial?  ", "aliados"));
	addQuestion(Question("Quien descubiro la penicilina? ", "fleming"));
	addQuestion(Question("Que paso en 1936 en espana ? ", "guerra civil"));
	addQuestion(Question("Quienes fueron los reyes que ayudaron al descubrimiento de america? ", "reyes catolicos"));
	addQuestion(Question("Quien fue el dictador de italia ?", "mussolini"));
}

//Destructor
HistoryQuiz::~HistoryQuiz() {};

void HistoryQuiz::printGameResult()
{
	try
	{
		if (score == 3)
		{
			cout << "Felicidades acabas de ganar el platanito azul" << endl;
		}
		else
		{
			throw runtime_error("Mira ver si estudiamos un poquito mas platanito");
		}
	}
	catch (const exception& ex)
	{
		cerr << "Error:" << ex.what() << endl;
	}
}