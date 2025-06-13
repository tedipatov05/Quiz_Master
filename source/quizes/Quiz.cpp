#include "../../headers/quizes/Quiz.h"
#include <iomanip>
#include "../../headers/helpers/Utils.h"
#include <iostream>

#include "../../headers/helpers/SystemMessages.h"
#include "../../headers/quizes/QuizAttempt.h"

Quiz::Quiz(int creatorId, int quizId) : creatorId(creatorId), isApproved(false), quizId(quizId), isActive(true) {

}

void Quiz::read() {
	std::cout << EnterQuizTitle;
	std::cin >> this->quizName;
	std::cout << EnterQuestionsCount;
	size_t questionsCount = 0;
	std::cin >> questionsCount;
	std::cin.ignore();

	for (size_t i = 0; i < questionsCount; i++) {
		MyString type;
		std::cout << "Enter question " << i + 1 << " type (T/F, SC, MC, ShA, MP): ";
		std::cin >> type;

		if (type.isEmpty()){
			std::cout << InvalidFormat << std::endl;
			return;
		}

		Question* question = QuestionFactory::createQuestion(fromStringToQuestionType(type));
		question->read();
		std::cin.ignore();

		this->maxPoints += question->getPoints();

		this->_questionsRepo.addQuestion(question);
		std::cout << "\n";

	}


	std::cout << "Quiz '" << quizName << "' with ID " << quizId << " sent for admin approval!" << std::endl;

}

void Quiz::approveQuiz() {
	this->isApproved = true;
}


void Quiz::saveInTextFile(std::ofstream& ofs, const User* creator) const {

	MyString quizTitle = this->quizName;
	quizTitle += " - ";
	quizTitle += toString(_questionsRepo.size());
	quizTitle += " Questions";

	MyString author = "By " + creator->getFirstName() + " " + creator->getLastName() + " @" + creator->getUsername();


	writeCenteredRow(ofs, quizTitle);
	writeCenteredRow(ofs, author);
	std::cout << std::endl;

	for (size_t i = 0; i < _questionsRepo.size(); i++) {
		ofs << (i + 1) << ") ";
		_questionsRepo[i].print(ofs);

		ofs << std::endl;
	}



}

void Quiz::writeToBinaryFile(std::ofstream& ofs) const {

	ofs.write((const char*)&this->quizId, sizeof(this->quizId));
	ofs.write((const char*)&this->creatorId, sizeof(this->creatorId));
	ofs.write((const char*)&this->maxPoints, sizeof(this->maxPoints));
	this->quizName.writeToBinaryFile(ofs);

	this->_questionsRepo.writeToBinaryFile(ofs);

	ofs.write((const char*)&this->isApproved, sizeof(this->isApproved));
	ofs.write((const char*)&this->isActive, sizeof(this->isActive));
}

void Quiz::print(std::ostream& os) const {

	for (size_t i = 0; i < _questionsRepo.size(); i++) {
		os << (i + 1) << ") ";
		_questionsRepo[i].print(os);

		os << std::endl;
	}

}

void Quiz::readFromBinaryFile(std::ifstream& ifs) {

	ifs.read((char*)&this->quizId, sizeof(this->quizId));
	ifs.read((char*)&this->creatorId, sizeof(this->creatorId));
	ifs.read((char*)&this->maxPoints, sizeof(this->maxPoints));
	this->quizName.readFromBinaryFile(ifs);

	this->_questionsRepo.readFromBinaryFile(ifs);

	ifs.read((char*)&this->isApproved, sizeof(this->isApproved));
	ifs.read((char*)&this->isActive, sizeof(this->isActive));

}

QuizAttempt Quiz::start(QuizMode mode, bool isShuffle, int userId) {

	if (!this->isActive || !this->isApproved){
		throw std::invalid_argument(QuizUnavailable.data());
	}

	int result = 0;
	Vector<int> nums = Vector<int>();
	for (size_t i = 0; i < this->_questionsRepo.size(); i++) {
		nums.push_back(i);
	}


	if (isShuffle) {
		shuffle(nums);
	}


	for (size_t i = 0; i < this->_questionsRepo.size(); i++) {
		result += this->_questionsRepo[nums[i]].start();

		if (mode == QuizMode::Test) {
			this->_questionsRepo[nums[i]].printCorrectAnswer(std::cout);
		}
	}

	std::cout << "Your quiz score is " << result << "/" << this->maxPoints << std::endl;

	if (mode == QuizMode::Test){
		std::cout << TestModeInfo << std::endl;
	}

	result = mode == QuizMode::Test ? 0 : result;
	return QuizAttempt(mode, userId, this->quizId, result);

}

void Quiz::writeCenteredRow(std::ostream& ofs, const MyString& line) const {

	ofs << std::setw((LINE_SIZE + line.size()) / 2) << line << "\n";


}

void Quiz::shuffle(Vector<int>& numbers)
{
	int n = numbers.size();
	for (int i = n - 1; i > 0; --i) {
		int j = rand() % (i + 1);  
		std::swap(numbers[i], numbers[j]);
	}
}

int Quiz::questionsCount() const{
	return (int)_questionsRepo.size();
}


int Quiz::id() const{
	return this->quizId;
}

bool Quiz::approved() const{
	return isApproved;
}

bool Quiz::active() const{
	return isActive;
}

int Quiz::creator() const{
	return this->creatorId;
}

void Quiz::reject(){
	this->isActive = false;
	this->isApproved = false;
}

MyString Quiz::name() const{
	return this->quizName;
}


bool operator==(const Quiz& lhs, const Quiz& rhs){
	return lhs.id() == rhs.id();
}













