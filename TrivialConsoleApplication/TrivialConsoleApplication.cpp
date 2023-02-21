/*¡Juego de preguntas y respuestas! 
Crea un programa que haga preguntas sobre un tema específico (por ejemplo, historia, geografía, cine, etc.) y permita al usuario ingresar sus respuestas. 
Luego, imprima una puntuación al final basada en cuántas respuestas correctas proporcionó el usuario.*/


/*ToDo: 1. Tenemos que arreglar que se puedan usar espacios en los string y que no tenga encuenta las mayus y minus
		2. Mirar porque la aleatoriedad repite siempre la primera 
		3. Mirar ERROR out of range */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
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
		char carta;

		//Preguntar al usuario que tema quiere tratar
		cout << "Elige entre las siguientes cartas: 1, 2, 3, 4" << endl;
		cin >> carta;

		switch (carta)
		{
		case '1':
			cout << "El tema a tratar es deportes" << endl;

			for (int i = 0; i < 3; i++)
			{
				vector<string> preguntas = { "Quien gano la ultima liga espanola de futbol? ",
											 "Quien es el mejor jugador del mundo? ",
											 "En que quipo de formula 1 esta actualmente fernando alonso ",
											 "Quien gano el ultimo rolland garros ? ",
											 "El equipo con mejores jugadores en la NBA en 1993" 
				};

				//Calcular que pregunta saldrá
				srand(time(nullptr));
				int pregunta_aleatoria = rand() % 5 + 2;
				string pregunta = preguntas[pregunta_aleatoria];

				cout << pregunta << endl;
				cin >> respuesta;

				//Hacer un validador simple
				if(pregunta == preguntas[0])
				{
					if (respuesta == "realmadrid")
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
					if (respuesta == "astonmartin")
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
					if (respuesta == "")
					{
						score++;
					}
				}
			}
			break;
		case '2':
			cout << "El tema a tratar es historia" << endl;

			for (int i = 0; i < 3; i++)
			{
				vector<string> preguntas = { "Quien gano la segunda guerra mundial? ",
											 "Quien descubiro la penicilina? ",
											 "Que paso en 1936 en espana ?  ",
											 "Quienes fueron los reyes que ayudaron al descubrimiento de america?",
											 "Quien fue el dictador de italia ? "
				};
				
				//Calcular que pregunta saldrá
				srand(time(nullptr));
				int pregunta_aleatoria = rand() % 5 + 1;
				string pregunta = preguntas[pregunta_aleatoria];

				cout << pregunta << endl;
				cin >> respuesta;

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
					if (respuesta == "Fleming")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[2])
				{
					if (respuesta == "guerracivil")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[3])
				{
					if (respuesta == "reyescatolicos")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[4])
				{
					if (respuesta == "Mussolini")
					{
						score++;
					}
				}
			}
			break;
		case '3':
			cout << "El tema a tratar es cine" << endl;

			for (int i = 0; i < 3; i++)
			{
				vector<string> preguntas = { "Que actriz gano el ultimo oscar ? ",
											 "Como se llama el mayor villano de todos los tiempo ? ",
											 "Que pelicula tiene mas oscars ? ",
											 "Que superheroe de marvel es rojo y dorado ? ",
											 "Como se llama el bxeador itloamericano más famoso del cine ? "
				};
				
				//Calcular que pregunta saldrá
				srand(time(nullptr));
				int pregunta_aleatoria = rand() % 5 + 1;
				string pregunta = preguntas[pregunta_aleatoria];

				cout << pregunta << endl;
				cin >> respuesta;

				//Hacer un validador simple
				if (pregunta == preguntas[0])
				{
					if (respuesta == "jessicachastain")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[1])
				{
					if (respuesta == "darthvader")
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
					if (respuesta == "ironman")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[4])
				{
					if (respuesta == "rockybalboa")
					{
						score++;
					}
				}
			}
			break;
		case '4':
			cout << "El tema a tratar es politica" << endl;

			for (int i = 0; i < 3; i++)
			{
				vector<string> preguntas = { "Quien es actualmente el presidente de espana?",
											 "Cuantos poderes hay en espana? ",
											 "Que partido es moradito ? ",
											 "Que dos partidos hay en EEUU ?",
											 "Que cargo tiene el gobernante de Japon ? "
				};

				//Calcular que pregunta saldrá
				srand(time(nullptr));
				int pregunta_aleatoria = rand() % 5 + 1;
				string pregunta = preguntas[pregunta_aleatoria];

				cout << pregunta << endl;
				cin >> respuesta;

				//Hacer un validador simple
				if (pregunta == preguntas[0])
				{
					if (respuesta == "pedrosanchez")
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
					if (respuesta == "democratasyrepublicanos")
					{
						score++;
					}
				}
				else if (pregunta == preguntas[4])
				{
					if (respuesta == "primerministro")
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
			case '1':
				cout << " el platanito azul " << endl;
				break;
			case '2':
				cout << " el platanito rojo " << endl;
				break;
			case '3':
				cout << " el platanito amarillo " << endl;
				break;
			case '4':
				cout << " el platanito rosado " << endl;
				break;
			default:
				break;
			}
			cout << endl;
			cout << "Desea continuar ? (S/N) " << endl;
			cin >> continuar;
		}
		else
		{
			cout << "Mira ver si estudiamos un poquito más mi niño " << endl;
			cout << endl;
			cout << "Desea continuar ? (S/N) " << endl;
			cin >> continuar;
		}

	} while (continuar != 'N');

	
}

