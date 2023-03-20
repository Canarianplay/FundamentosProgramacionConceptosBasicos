/*¡Ahorcado! 
Crea un juego de ahorcado en consola donde el programa elija una palabra 
y luego permita al usuario adivinar letra por letra hasta que adivine la palabra completa o se equivoque demasiadas veces. 
Imprima una imagen del ahorcado después de cada intento fallido para hacerlo más divertido.*/

#include <iostream>
#include <string>
#include<vector>
using namespace std;

//Funcion para imprimir una imagen del ahorcado (TODO: Te invito a que jugues con esta funcion)
void print_hangman(int n) {
    vector<string> hangman = {
      "  +---+",
      "  |   |",
      "      |",
      "      |",
      "      |",
      "      |",
      "========="
    };

    if (n >= 1) hangman[2] = "  |   o";
    if (n >= 2) hangman[3] = "  |   |";
    if (n >= 3) hangman[3] = "  |  /|";
    if (n >= 4) hangman[3] = "  |  /|\\";
    if (n >= 5) hangman[4] = "  |  /";
    if (n == 6) hangman[4] = "  |  / \\";




    for (string line : hangman) {
        cout << line << endl;
    }
}


int main()
{
    //Conjunto de palabras de nuestro juego
    vector<string> words = { "programacion","informatica","harrypotter","canario","platanito" };

    //Elegimos la palabra con la que vamos a jugar
    srand(time(nullptr));
    int n = rand() % words.size() + 1;
    
    //Palabra con la que iniciaremos el juego
    string playword = words[n];

    //Variables para el juego
    string guessed(playword.length(), '_');
    int num_guesses = 0;
    int num_guessesmax = 6;

    //Algoritmo para jugar hasta que el jugador adivine la palabra o cometa deemasiados errores
    while (num_guesses < num_guessesmax && guessed != playword)
    {
        //Imprimir palabra escondida y num intentos
        cout << "Palabra: " << guessed << endl;
        cout << "Numero de intentos restantes: " << num_guessesmax - num_guesses << endl;

        //Pedir al usuario que adivine una letra
        char letter;
        cout << "Introduzca una letra" << endl;
        cin >> letter;

        //Comprobar si la letra esta en la palabra (Algoritmo de búsqueda simple)
        bool found = false;
        for (int i = 0; i < playword.length(); i++)
        {
            if (playword[i] == letter)
            {
                guessed[i] = letter;
                found = true;
            }
        }

        //Error (la letra no existe)
        if(!found)
        {
            num_guesses++;
            cout << "La letra es incorrecta" << endl;
            print_hangman(num_guesses);
        }
    }

    //Imprimir resultado
    if (num_guesses == num_guessesmax)
    {
        cout << "Perdites pequeño platano, la palabra era: " << playword << endl;

    }
    else
    {
        cout << "Ganaste pequeño platano, la palabra era: " << playword << endl;
    }
}

