#include "../../headers/questions/QuestionsRepository.h"

#include <iostream>

#include "../../headers/helpers/Constants.h"

QuestionsRepository::QuestionsRepository() {
	this->_capacity = INITIAL_CAPACITY;
	this->_size = 0;
	this->_questions = new Question * [this->_capacity];
}

QuestionsRepository::QuestionsRepository(const QuestionsRepository& repo) : _size(repo.size()), _capacity(repo._capacity) {
	this->copyDynamicMemory(repo);
}

QuestionsRepository::~QuestionsRepository() {
	freeDynamic();
	this->_size = 0;
	this->_capacity = 0;
}

QuestionsRepository& QuestionsRepository::operator=(const QuestionsRepository& other) {
	if (this != &other) {
		freeDynamic();
		copyDynamicMemory(other);
		this->_size = other.size();
		this->_capacity = other._capacity;

	}

	return *this;
}


void QuestionsRepository::copyDynamicMemory(const QuestionsRepository& repo) {
	this->_questions = new Question * [repo._capacity];
	for (size_t i = 0; i < repo.size(); i++) {
		this->_questions[i] = repo._questions[i]->clone();
	}
}

void QuestionsRepository::freeDynamic() {
	for (size_t i = 0; i < this->_size; i++) {
		delete this->_questions[i];
	}

	delete[] this->_questions;
	this->_questions = nullptr;


}

void QuestionsRepository::addQuestion(const Question* question) {
	if (this->_size == this->_capacity) {
		this->resize(this->_capacity * 2);
	}

	this->_questions[this->_size] = question->clone();
	this->_size++;
}


const Question& QuestionsRepository::operator[](size_t index) const {
	return *this->_questions[index];
}

size_t QuestionsRepository::size() const {
	return this->_size;
}


void QuestionsRepository::resize(size_t newCap) {
	Question** temp = new Question * [newCap];

	for (size_t i = 0; i < this->size(); i++) {
		temp[i] = this->_questions[i];
	}
	delete[] this->_questions;
	this->_questions = temp;
}

void QuestionsRepository::writeToBinaryFile(std::ofstream& ofs) const {

	ofs.write((const char*)&this->_size, sizeof(this->_size));

	for (size_t i = 0; i < this->size(); i++) {
		this->_questions[i]->writeToBinaryFile(ofs);
	}

}

void QuestionsRepository::add(const Question* question) {
	if (this->_size == this->_capacity) {
		resize(this->_capacity * 2);
	}

	this->_questions[this->_size] = question->clone();
	this->_size++;
}


void QuestionsRepository::readFromBinaryFile(std::ifstream& ifs) {

	freeDynamic();
	this->_questions = new Question * [this->_capacity];

	size_t size = 0;
	ifs.read((char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++) {
		QuestionType questionType;
		ifs.read((char*)&questionType, sizeof(questionType));

		Question* question = QuestionFactory::createQuestion(questionType);

		if (!question) {
			std::cout << "Error while reading from file" << std::endl;
			return;
		}

		question->readFromBinaryFile(ifs);
		this->add(question);

	}

}

