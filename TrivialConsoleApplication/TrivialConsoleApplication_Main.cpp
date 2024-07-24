/*¡Juego de preguntas y respuestas!
Crea un programa que haga preguntas sobre un tema específico (por ejemplo, historia, geografía, cine, etc.) y permita al usuario ingresar sus respuestas.
Luego, imprima una puntuación al final basada en cuántas respuestas correctas proporcionó el usuario.*/

/*Upgrade(POO): Uso de los operadores new y delete. Creación de la nueva estructura del proyecto
*/


/*TODO para ustedes mis platanitos:
	1. Si no lo hiciste en la clase anterior, completa este código con diferentes y más temas de los que hacer preguntas (Si los conceptos que aprendiste mi rey)
	2. Si tu observas mas posibles errores que puedan surgir durante la ejecución del código sientete libre de incluir cualquier tratamiento para ello
*/

#include "SportQuiz.h"
#include "HistoryQuiz.h"

#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdexcept> //Necesario para las excepciones estandar

using namespace std;


//Funcion principal
int main()
{
	try 
	{
		srand(time(nullptr));
		char continuar;

		do
		{
			//Empieza el juego
			cout << "Bienvenido al juego del platanito, cuanto mas aciertes más puntos obtendras" << endl;

			cout << "Elige entre las siguientes cartas: azul, rojo, verde, amarillo" << endl;
			string cartaStr;
			cin >> cartaStr;
			transform(cartaStr.begin(), cartaStr.end(), cartaStr.begin(), ::tolower);
			std::cin.ignore();

			Game* game = nullptr;

			if (cartaStr == "azul")
			{
				cout << "El tema será DEPORTES!!!" << endl;
				game = new SportQuiz();
			}
			else if (cartaStr == "rojo")
			{
				cout << "El tema será HISTORIA!!!" << endl;
				game = new HistoryQuiz();
			}
			else
			{
				throw invalid_argument("Opción no valida... prueba de nuevo");
			}

			if (game)
			{
				game->playGame();
				game->printGameResult();
				delete game;
			}


			cout << "Desea continuar ? (S/N) " << endl;
			std::cin >> continuar;

		} while (continuar != 'N');
	}
	catch (const std::exception& ex) 
	{
		cerr << "Error:" << ex.what() << endl;
	}

	return  0;
}