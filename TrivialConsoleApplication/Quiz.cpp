#include "Quiz.h"

//Constructor
Quiz::Quiz() : score(0) {};

//Destructor
Quiz::~Quiz() {};

//Añadir question (Add)
void Quiz::addQuestion(const Question& question)
{
	questions.push_back(question);
}

//Jugamos
void Quiz::playGame()
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
		catch (const out_of_range& ex)
		{
			cerr << "Error:" << ex.what() << endl;
		}
	}
}