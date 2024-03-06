/*¡Ahorcado!
Crea un juego de ahorcado en consola donde el programa elija una palabra
y luego permita al usuario adivinar letra por letra hasta que adivine la palabra completa o se equivoque demasiadas veces.
Imprima una imagen del ahorcado después de cada intento fallido para hacerlo más divertido.*/


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


//Interfaz para el polimorfismo
class Drawable
{
public:
	virtual void draw()const = 0;
	virtual ~Drawable() {};
};


//clase base o clase padre o super clase que reprensenta un elemento del juego
class GameElement : public Drawable
{
protected:

	string representation;

public:

	GameElement(const string& represent) : representation(represent) {};
	~GameElement() {};

	void draw() const override
	{
		cout << representation << endl;
	}
};

//Clase para la palabra que tenemos que adivinar
class WordToGuess : public GameElement
{
private:

	string word;

public:

	//Constructor
	WordToGuess(const string& w) : GameElement(""), word(w) {};
	//Destructor
	~WordToGuess() {};

	bool contains(char letter) const
	{
		return word.find(letter) != string::npos;
	}

	string getWord() const {
		return word;
	}
};

//Clase que representa el ahorcado
class Hangman : public GameElement
{
private:

	int numGuess;

public:

	Hangman() : GameElement(""), numGuess(0) {};
	~Hangman() {};

	void draw() const override
	{
		vector<string> hangman = {
		  "  +---+",
		  "  |   |",
		  "      |",
		  "      |",
		  "      |",
		  "      |",
		  "========="
		};

		if (numGuess >= 1) hangman[2] = "  |   o";
		if (numGuess >= 2) hangman[3] = "  |   |";
		if (numGuess >= 3) hangman[3] = "  |  /|";
		if (numGuess >= 4) hangman[3] = "  |  /|\\";
		if (numGuess >= 5) hangman[4] = "  |  /";
		if (numGuess == 6) hangman[4] = "  |  / \\";




		for (string line : hangman) {
			cout << line << endl;
		}
	}

	void AddGuess()
	{
		numGuess++;
	}

	bool isGameOver()
	{
		return numGuess >= 6;
	}

	int getNumGuessed() {
		return numGuess;
	}
};

//Clase que representa el juego del Ahorcado
class HangmanGame
{
private:

	WordToGuess wordToGuess;
	string guessed;
	Hangman hangman;
	int maxGuesses;

private:

	bool isGameFinished()
	{
		return guessed == wordToGuess.getWord() || hangman.isGameOver();
	}

	void printGameState()
	{
		cout << "Palabra: " << guessed << endl;
		cout << "Numero de intentos restantes: " << maxGuesses - hangman.getNumGuessed() << endl;
		hangman.draw();
	}

	void checkLetter(char letter)
	{
		try
		{
			if (!isalpha(letter)) 
			{
				throw invalid_argument("Caracter invalida!!...Solo se permiten letras");
			}

			if (wordToGuess.contains(letter))
			{
				for (int i = 0; i <= wordToGuess.getWord().length(); i++)
				{
					if (wordToGuess.getWord()[i] == letter)
					{
						guessed[i] = letter;
					}
				}
			}
			else
			{
				hangman.AddGuess();
				cout << "La letra es incorrecta" << endl;
			}
		}
		catch (const exception& ex)
		{
			cerr << "Error: " << ex.what() << endl;
		}
	}

	void printGameResult()
	{
		if (!hangman.isGameOver())
		{
			cout << "Ganaste pequeño platano, la palabra era: " << wordToGuess.getWord() << endl;
		}
		else
		{
			cout << "Perdites pequeño platano, la palabra era: " << wordToGuess.getWord() << endl;
		}
	}

public:

	HangmanGame(const string& word, int maxguesses) : wordToGuess(word), guessed(word.length(), '_'), maxGuesses(maxguesses) {};
	~HangmanGame() {};

	void play()
	{
		while (!isGameFinished())
		{
			printGameState();
			char letter;
			cout << "Introduzca una letra" << endl;
			cin >> letter;
			checkLetter(letter);
		}

		printGameResult();
	}
};

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
		HangmanGame game(randomWord, 6);

		//Iniciamos el juego.
		game.play();
	}
	catch (const exception& ex) 
	{
		cerr << "Error: " << ex.what() << endl;
		return 1;
	}

	return 0;
}

