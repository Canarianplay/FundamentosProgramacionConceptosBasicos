/*¡Juego de preguntas y respuestas!
Crea un programa que haga preguntas sobre un tema específico (por ejemplo, historia, geografía, cine, etc.) y permita al usuario ingresar sus respuestas.
Luego, imprima una puntuación al final basada en cuántas respuestas correctas proporcionó el usuario.*/

/*Upgrade(POO): Este codigo contedrán la aplicación del polimorfismo y encapsulamiento de datos
 *              asi como el uso de un tratamiento de errores adecuado
*/


/*TODO para ustedes mis platanitos:
	1. Si no lo hiciste en la clase anterior, completa este código con diferentes y más temas de los que hacer preguntas (Si los conepctos que aprendiste mi rey)
	2. Si tu observas mas posibles errores que peudan surgir durante la ejecución del código sientete libre de incluir cualquier tratamiento para ello
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdexcept> //Necesario para las excepciones estandar

using namespace std;

//Interfaz para el juego
class Game 
{
	public:

		virtual void playGame() = 0;
		virtual ~Game() {}

		virtual void printGameResult() = 0;
		
};

// Clase base que representa una pregunta con su respuesta
class Question 
{
	private:

		string question;
		string answer;

	public:

		//Constructor
		Question(const string& q, const string& a) : question(q), answer(a) {};

		//Destructor
		~Question() {};

		//Obtencion de la pregunta (question) (método get)
		const string& getQuestion() 
		{
			return question;
		}

		//Obtencion de la respuesta (answer) (método get)
		const string& getAnswer()
		{
			return answer;
		}

		//check de la respuesta (answer)
		bool checkAnswer(const string& userAnswer)
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
};



//Clase base que representa el juego
class Quiz : public Game
{
	protected:
		int score;
		vector<Question> questions;

	public:

		//Constructor
		Quiz() : score(0) {};

		//Destructor
		~Quiz() {};

		//Añadir question (Add)
		void addQuestion(const Question& question)
		{
			questions.push_back(question);
		}

		//Jugamos
		void playGame() override
		{
			for (size_t i = 0; i < 3; i++)
			{
				try 
				{
					int randomIndex = rand() % questions.size();
					Question& currentQuestion = questions[randomIndex];

					cout << currentQuestion.getQuestion() << endl;
					string userAnswer;
					std::getline(std::cin, userAnswer);
					transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);

					if (currentQuestion.checkAnswer(userAnswer))
					{
						cout << "Respuesta correcta." << endl;
						score++;
					}
					else
					{
						cout << "Respuesta incorrecta. La respuesta correcta era: " << currentQuestion.getAnswer() << endl;
					}

					questions.erase(questions.begin() + randomIndex);
				}
				catch(const out_of_range& ex)
				{
					cerr << "Error:" << ex.what() << endl;
				}
			}
		}
};


//Clase derivada para un tema especifico (Deporte) (herencia)
class SportQuiz : public Quiz
{
	public:

		//Constructor
		SportQuiz() 
		{
			addQuestion(Question("Quien gano la ultima liga espanola de futbol? ", "real madrid"));
			addQuestion(Question("Quien es el mejor jugador del mundo? ", "messi"));
			addQuestion(Question("En que quipo de formula 1 esta actualmente fernando alonso ", "aston martin"));
			addQuestion(Question("Quien gano el ultimo rolland garros ? ", "nadal"));
			addQuestion(Question("El equipo con mejores jugadores en la NBA en 1993", "chicago bulls"));
		};

		//Destructor
		~SportQuiz() {};


		void printGameResult() override 
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
};

//Clase dereivdada para un tema especifico (Historia) (herencia)
class HistoryQuiz : public Quiz
{

	public:

		//Constructor
		HistoryQuiz()
		{

			addQuestion(Question("Quien gano la segunda guerra mundial?  ", "aliados"));
			addQuestion(Question("Quien descubiro la penicilina? ", "fleming"));
			addQuestion(Question("Que paso en 1936 en espana ? ", "guerra civil"));
			addQuestion(Question("Quienes fueron los reyes que ayudaron al descubrimiento de america? ", "reyes catolicos"));
			addQuestion(Question("Quien fue el dictador de italia ?", "mussolini"));
		}

		//Destructor
		~HistoryQuiz() {};

		void printGameResult() override
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

};

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