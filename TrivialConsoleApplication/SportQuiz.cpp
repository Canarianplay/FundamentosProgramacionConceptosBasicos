#include "SportQuiz.h"


//Constructor
SportQuiz::SportQuiz()
{
	addQuestion(Question("Quien gano la ultima liga espanola de futbol? ", "real madrid"));
	addQuestion(Question("Quien es el mejor jugador del mundo? ", "messi"));
	addQuestion(Question("En que quipo de formula 1 esta actualmente fernando alonso ", "aston martin"));
	addQuestion(Question("Quien gano el ultimo rolland garros ? ", "nadal"));
	addQuestion(Question("El equipo con mejores jugadores en la NBA en 1993", "chicago bulls"));
};

//Destructor
SportQuiz::~SportQuiz() {};

void SportQuiz::printGameResult()
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