/*¡Juego de preguntas y respuestas!
Crea un programa que haga preguntas sobre un tema específico (por ejemplo, historia, geografía, cine, etc.) y permita al usuario ingresar sus respuestas.
Luego, imprima una puntuación al final basada en cuántas respuestas correctas proporcionó el usuario.*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

enum Color
{
	AZUL = 1,
	ROJO,
	VERDE,
	AMARILLO
};


//Variable global
char continuar;

//Declaración: Funcion para mostrar el mensaje de selección de la carta
void mostrarMensajeTematicaCarta(Color carta);

//Declaracion: Funcion para obtener la respuesta del usuario
string getUserResponse();
//Declaracon: Funcion para jugar la ronda de preguntas
void PlayRound(Color carta, int& score);

//Declaracion: Funcion para validar si el jugador gano o no
bool winValidator(Color carte, int score);

//Declaracion: Funcion para convertir el color de la carta
void stringTOEnumConverter(Color& carta);

//Declaracion: Funcion 2.0 para validar la respuesta
bool validarRespuesta(const map<string, string>& preguntaResp, const string& pregunta, const string& respuesta, int& score);

int main()
{

	//Empieza el juego
	cout << "Bienvenido al juego del platanito, cuanto mas aciertes más puntos obtendras" << endl;

	do
	{
		//Variables locales
		int score = 0;
		Color carta;

		stringTOEnumConverter(carta);

		PlayRound(carta, score);


		winValidator(carta, score);
		cout << endl;
		cout << "Desea continuar ? (S/N) " << endl;
		std::cin >> continuar;

	} while (continuar != 'N');
}

//Implementacion:  Funcion para mostrar el mensaje de selección de la carta
void mostrarMensajeTematicaCarta(Color carta)
{
	switch (carta)
	{
	case AZUL:
		cout << "El tema a tratar es deportes" << endl;
		break;
	case ROJO:
		cout << "El tema a tratar es historia" << endl;
		break;
	case VERDE:
		cout << "El tema a tratar es cine" << endl;
		break;
	case AMARILLO:
		cout << "El tema a tratar es política" << endl;
		break;
	default:
		cout << "No es tan difícil elegir entre 4 cartas enumeradas del 1 al 4" << endl;
		break;
	}

}

//Implementacion: Funcion para obtener la respuesta del usuario
string getUserResponse()
{
	//Variable local
	string response = "";
	std::getline(std::cin, response);
	transform(response.begin(), response.end(), response.begin(), ::tolower);
	return response;

}

//Implementacion: Funcion 2.0 para validar la respuesta
bool validarRespuesta(const map<string, string>& preguntaResp, const string& pregunta, const string& respuesta, int& score)
{
	auto it = preguntaResp.find(pregunta);

	if (it != preguntaResp.end())
	{
		if (respuesta == it->second)
		{
			score++;
			return true;
		}
	}
	return false;
}

//Implementacion: Funcion para jugar la ronda de preguntas
void PlayRound(Color carta, int& score)
{
	map<string, string> preguntaRespuesta;

	switch (carta)
	{
	case AZUL:
		mostrarMensajeTematicaCarta(carta);

		preguntaRespuesta = { 
			{"Quien gano la ultima liga espanola de futbol? ", "real madrid"},
			{"Quien es el mejor jugador del mundo? ", "messi" },
			{"En que quipo de formula 1 esta actualmente fernando alonso ", "aston martin"},
			{"Quien gano el ultimo rolland garros ? ", "nadal"},
			{"El equipo con mejores jugadores en la NBA en 1993", "chicago bulls"}
		};
		break;
	case ROJO:
		mostrarMensajeTematicaCarta(carta);

		preguntaRespuesta = {
			{"Quien gano la segunda guerra mundial?  ", "aliados"},
			{"Quien descubiro la penicilina? ", "fleming" },
			{"Que paso en 1936 en espana ? ", "guerra civil"},
			{"Quienes fueron los reyes que ayudaron al descubrimiento de america? ", "reyes catolicos"},
			{"Quien fue el dictador de italia ?", "mussolini"}
		};
		break;
	case VERDE:
		mostrarMensajeTematicaCarta(carta);

		preguntaRespuesta = {
			{"Que actriz gano el ultimo oscar ?  ", "jessica chastain"},
			{"Como se llama el mayor villano de todos los tiempo ? ", "darth vader" },
			{"Que pelicula tiene mas oscars ? ", "titanic"},
			{"Que superheroe de marvel es rojo y dorado ? ", "iron man"},
			{"Como se llama el bxeador itloamericano más famoso del cine ?", "rocky balboa"}
		};
		break;
	case AMARILLO:
		mostrarMensajeTematicaCarta(carta);

		preguntaRespuesta = {
			{"Quien es actualmente el presidente de espana? ", "pedro sanchez"},
			{"Cuantos poderes hay en espana? ", "3" },
			{"Que partido es moradito ? ", "podemos"},
			{"Que dos partidos hay en EEUU ? ", "democratas y republicanos"},
			{"Que cargo tiene el gobernante de Japon ?", "primer ministro"}
		};

		break;
	default:
		cout << "No es tan dificil elegir entre 4 cartas enumeradas del 1 al 4 " << endl;
		break;
	}

	for (int i = 0; i < 3; i++)
	{
		auto it = preguntaRespuesta.begin();
		advance(it, rand() % preguntaRespuesta.size());
		string pregunta = it->first;

		cout << pregunta << endl;
		string respuesta = getUserResponse();

		validarRespuesta(preguntaRespuesta, pregunta, respuesta, score);

		preguntaRespuesta.erase(pregunta);
		
	}
}

//Implementacion: Funcion para validar si el jugador gano o no
bool winValidator(Color carta, int score)
{
	if (score == 3)
	{
		cout << "Felicidades acabas de ganar ... ";

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

		return true;
	}
	else
	{
		cout << "Mira ver si estudiamos un poquito mas platanito " << endl;
		return false;
	}
}

//Implementacion: Funcion para convertir el color de la carta
void stringTOEnumConverter(Color& carta)
{
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
}