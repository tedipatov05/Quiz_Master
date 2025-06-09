#include "../../headers/questions/Question.h"

#include <iostream>

Question::Question(const MyString& description, int points) : _desription(description), _points(points){

}



int Question::start() const{
	this->print(std::cout);

	MyString answer;

	while (true){
		try {
			std::cin >> answer;
			int res = this->checkAnswer(answer);
			return res;

		}
		catch (std::invalid_argument e){
			std::cout << e.what() << std::endl;
			std::cout << "Enter your answer here: ";
		}
	}


}

int Question::getPoints() const{
	return this->_points;
}

