/*¡Juego de preguntas y respuestas!
Crea un programa que haga preguntas sobre un tema específico (por ejemplo, historia, geografía, cine, etc.) y permita al usuario ingresar sus respuestas.
Luego, imprima una puntuación al final basada en cuántas respuestas correctas proporcionó el usuario.*/

/*Upgrade(POO): Crearemos una clase Question para representar una pregunta con su respuesta y un clase Quiz para manejar todo el juego.
	Posteriormente agregaremos herencia creando un clase derivada de Quiz para diferentes temas*/


/*TODO para ustedes mis platanitos:

  1. Completa las dos clases derivadas que faltan
  2. Modifica el código para que sea posible jugar con estas nuevas clases creadas

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

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
			string lowerUserAnswer = userAnswer;

			transform(lowerUserAnswer.begin(), lowerUserAnswer.end(), lowerUserAnswer.begin(), ::tolower);

			return userAnswer == answer;
		}
};



//Clase base que representa el juego
class Quiz
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
		void play()
		{
			for (size_t i = 0; i < 3; i++)
			{
				int randomIndex = rand() % questions.size();
				Question& currentQuestion = questions[randomIndex];

				cout << currentQuestion.getQuestion() << endl;
				string userAnswer;
				std::getline(std::cin, userAnswer);
				transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);

				if(currentQuestion.checkAnswer(userAnswer))
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

			printGameResult();
		}

		
		virtual void printGameResult() const = 0;
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


		void printGameResult() const override 
		{
			if(score == 3)
			{
				cout << "Felicidades acabas de ganar el platanito azul" << endl;
			}
			else 
			{
				cout << "Mira ver si estudiamos un poquito mas platanito " << endl;
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

		void printGameResult() const override
		{
			if (score == 3)
			{
				cout << "Felicidades acabas de ganar el platanito rojo" << endl;
			}
			else
			{
				cout << "Mira ver si estudiamos un poquito mas platanito " << endl;
			}
		}

};

//Funcion principal
int main()
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
		transform(cartaStr.begin(),cartaStr.end(), cartaStr.begin(), ::tolower);
		std::cin.ignore();

		Quiz* quiz = nullptr;

		if (cartaStr == "azul")
		{
			cout << "El tema será DEPORTES!!!" << endl;
			quiz = new SportQuiz();
		}
		else if (cartaStr == "rojo") 
		{
			cout << "El tema será HISTORIA!!!" << endl;
			quiz = new HistoryQuiz();
		}
		else 
		{
			cout << "No es tan difícil elegir entre 4 cartas enumeradas del 1 al 4" << endl;
		}

		quiz->play();
		delete quiz;

		cout << "Desea continuar ? (S/N) " << endl;
		std::cin >> continuar;

	} while (continuar != 'N');
}