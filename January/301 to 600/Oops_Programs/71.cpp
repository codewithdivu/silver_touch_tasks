#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Question {
public:
    string text;
    int correctOption;

    Question(const string& q, int correct) : text(q), correctOption(correct) {}
};

class Quiz {
private:
    vector<Question> questions;

public:
    void addQuestion(const Question& question) {
        questions.push_back(question);
    }

    void startQuiz() const {
        int score = 0;

        for (const auto& question : questions) {
            cout << question.text << endl;
            
            int userSelection = rand() % 4 + 1;
            
            if (userSelection == question.correctOption) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Incorrect. Correct option: " << question.correctOption << endl;
            }
        }

        cout << "Quiz completed. Score: " << score << "/" << questions.size() << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Question q1("What is the capital of France?", 3);
    Question q2("Which planet is known as the Red Planet?", 2);
    Question q3("What is the largest mammal on Earth?", 4);

    Quiz quiz;
    quiz.addQuestion(q1);
    quiz.addQuestion(q2);
    quiz.addQuestion(q3);

    quiz.startQuiz();

    return 0;
}
