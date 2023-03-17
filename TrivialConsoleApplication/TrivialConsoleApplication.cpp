/*¡Juego de preguntas y respuestas! 
Crea un programa que haga preguntas sobre un tema específico (por ejemplo, historia, geografía, cine, etc.) y permita al usuario ingresar sus respuestas. 
Luego, imprima una puntuación al final basada en cuántas respuestas correctas proporcionó el usuario.*/

/*ToDo futuras: Podemos añadir que cada vez que salga una pregunta esta se elimine del vector y asi no salga repetida*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum Color 
{
	AZUL = 1,
	ROJO,
	VERDE,
	AMARILLO
};

int main()
{
	//Variables "generales"
	char continuar;

	//Empieza el juego
	cout << "Bienvenido al juego del platanito, cuanto mas aciertes más puntos obtendras" << endl;

	do 
	{	
		//Variables
		int score = 0;
		string respuesta;
		Color carta;
		string cartaStr;

		//Preguntar al usuario que tema quiere tratar
		cout << "Elige entre las siguientes cartas: azul, rojo, verde, amarillo" << endl;
		cin >> cartaStr;
		std::cin.ignore();

		transform(cartaStr.begin(), cartaStr.end(), cartaStr.begin(), ::tolower);

		if (cartaStr == "azul")
		{
			carta = AZUL;
		}
		else if (cartaStr == "rojo")
		{
			carta = ROJO;
		}
		else if (cartaStr == "verde")
		{
			carta = VERDE;
		}
		else if (cartaStr == "amarillo") 
		{
			carta = AMARILLO;
		}

		switch (carta)
		{
		case AZUL:
			cout << "El tema a tratar es deportes" << endl;

			//Calcular que pregunta saldrá
			std::srand(time(nullptr));

			for (int i = 0; i < 3; i++)
			{
				vector<string> preguntas = { "Quien gano la ultima liga espanola de futbol? ",
											 "Quien es el mejor jugador del mundo? ",
											 "En que quipo de formula 1 esta actualmente fernando alonso ",
											 "Quien gano el ultimo rolland garros ? ",
											 "El equipo con mejores jugadores en la NBA en 1993" 
				};

				
				int pregunta_aleatoria = rand() % preguntas.size();
				string pregunta = preguntas[pregunta_aleatoria];

				cout << pregunta << endl;
				std::getline(std::cin, respuesta);
				transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::tolower);

			
				//Hacer un validador simple
				if(pregunta == preguntas[0])
				{
					if (respuesta == "real madrid")
					{
						score++;
					}
				}
				else if(pregunta == preguntas[1])
				{
					if (respuesta == "messi")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[2])
				{
					if (respuesta == "aston martin")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[3])
				{
					if (respuesta == "nadal")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[4])
				{
					if (respuesta == "chicago bulls")
					{
						score++;
					}
				}
			}
			break;
		case ROJO:
			cout << "El tema a tratar es historia" << endl;

			//Calcular que pregunta saldrá
			std::srand(time(nullptr));

			for (int i = 0; i < 3; i++)
			{
				vector<string> preguntas = { "Quien gano la segunda guerra mundial? ",
											 "Quien descubiro la penicilina? ",
											 "Que paso en 1936 en espana ?  ",
											 "Quienes fueron los reyes que ayudaron al descubrimiento de america?",
											 "Quien fue el dictador de italia ? "
				};
				
				
				int pregunta_aleatoria = rand() % preguntas.size();
				string pregunta = preguntas[pregunta_aleatoria];

				cout << pregunta << endl;
				std::getline(std::cin, respuesta);
				transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::tolower);

				//Hacer un validador simple
				if (pregunta == preguntas[0])
				{
					if (respuesta == "aliados")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[1])
				{
					if (respuesta == "fleming")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[2])
				{
					if (respuesta == "guerra civil")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[3])
				{
					if (respuesta == "reyes catolicos")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[4])
				{
					if (respuesta == "mussolini")
					{
						score++;
					}
				}
			}
			break;
		case VERDE:
			cout << "El tema a tratar es cine" << endl;

			//Calcular que pregunta saldrá
			std::srand(time(nullptr));

			for (int i = 0; i < 3; i++)
			{
				vector<string> preguntas = { "Que actriz gano el ultimo oscar ? ",
											 "Como se llama el mayor villano de todos los tiempo ? ",
											 "Que pelicula tiene mas oscars ? ",
											 "Que superheroe de marvel es rojo y dorado ? ",
											 "Como se llama el bxeador itloamericano más famoso del cine ? "
				};
				
				
				int pregunta_aleatoria = rand() % preguntas.size();
				string pregunta = preguntas[pregunta_aleatoria];

				cout << pregunta << endl;
				std::getline(std::cin, respuesta);
				transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::tolower);

				//Hacer un validador simple
				if (pregunta == preguntas[0])
				{
					if (respuesta == "jessica chastain")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[1])
				{
					if (respuesta == "darth vader")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[2])
				{
					if (respuesta == "titanic")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[3])
				{
					if (respuesta == "iron man")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[4])
				{
					if (respuesta == "rocky balboa")
					{
						score++;
					}
				}
			}
			break;
		case AMARILLO:
			cout << "El tema a tratar es politica" << endl;

			//Calcular que pregunta saldrá
			std::srand(time(nullptr));

			for (int i = 0; i < 3; i++)
			{
				vector<string> preguntas = { "Quien es actualmente el presidente de espana?",
											 "Cuantos poderes hay en espana? ",
											 "Que partido es moradito ? ",
											 "Que dos partidos hay en EEUU ?",
											 "Que cargo tiene el gobernante de Japon ? "
				};

				
				int pregunta_aleatoria = rand() % preguntas.size();
				string pregunta = preguntas[pregunta_aleatoria];

				cout << pregunta << endl;
				std::getline(std::cin, respuesta);
				transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::tolower);

				//Hacer un validador simple
				if (pregunta == preguntas[0])
				{
					if (respuesta == "pedro sanchez")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[1])
				{
					if (respuesta == "3")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[2])
				{
					if (respuesta == "podemos")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[3])
				{
					if (respuesta == "democratas y republicanos")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[4])
				{
					if (respuesta == "primer ministro")
					{
						score++;
					}
				}
			}
			break;
		default:
			cout << "No es tan dificil elegir entre 4 cartas enumeradas del 1 al 4 " << endl;
			break;
		}

		if (score == 3)
		{
			cout << "Felicidades acabas de ganar ... " << endl;

			switch (carta)
			{
			case AZUL:
				cout << " el platanito azul " << endl;
				break;
			case ROJO:
				cout << " el platanito rojo " << endl;
				break;
			case AMARILLO:
				cout << " el platanito amarillo " << endl;
				break;
			case VERDE:
				cout << " el platanito verde " << endl;
				break;
			default:
				break;
			}
			cout << endl;
			cout << "Desea continuar ? (S/N) " << endl;
			std::cin >> continuar;
		}
		else
		{
			cout << "Mira ver si estudiamos un poquito mas platanito " << endl;
			cout << endl;
			cout << "Desea continuar ? (S/N) " << endl;
			std::cin >> continuar;
		}

	} while (continuar != 'N');

	
}

