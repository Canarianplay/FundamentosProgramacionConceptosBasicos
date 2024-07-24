/*¡Ahorcado!
Crea un juego de ahorcado en consola donde el programa elija una palabra
y luego permita al usuario adivinar letra por letra hasta que adivine la palabra completa o se equivoque demasiadas veces.
Imprima una imagen del ahorcado después de cada intento fallido para hacerlo más divertido.*/

/*Upgrade(POO): Uso de los operadores new y delete. Creación de la nueva estructura del proyecto
*/


#include "HangmanGame.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
	try 
	{
		//Conjunto de palabras de nuestro juego
		vector<string> words = { "programacion","informatica","harrypotter","canario","platanito" };

		//Elegimos la palabra con la que vamos a jugar
		srand(time(nullptr));
		int n = rand() % words.size();

		//Palabra con la que iniciaremos el juego
		string randomWord = words[n];

		//Creamos el juego del Ahorcado (Llamada al constructor del Objeto)
		HangmanGame* game =  new HangmanGame(randomWord, 6);

		//Iniciamos el juego.
		game->play();

		//Liberamos la memoria usada
		delete game;
	}
	catch (const exception& ex) 
	{
		cerr << "Error: " << ex.what() << endl;
		return 1;
	}

	return 0;
}

