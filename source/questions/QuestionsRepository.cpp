#include "../../headers/questions/QuestionsRepository.h"
#include "../../headers/helpers/Constants.h"

QuestionsRepository::QuestionsRepository(){
	this->_capacity = INITIAL_CAPACITY;
	this->_size = 0;
	this->_questions = new Question*[this->_capacity];
}

QuestionsRepository::QuestionsRepository(const QuestionsRepository& repo) : _size(repo.size()), _capacity(repo._capacity){
	this->copyDynamicMemory(repo);
}

QuestionsRepository::~QuestionsRepository(){
	freeDynamic();
	this->_size = 0;
	this->_capacity = 0;
}


void QuestionsRepository::copyDynamicMemory(const QuestionsRepository& repo){
	this->_questions = new Question * [repo._capacity];
	for (size_t i = 0; i < repo.size(); i++){
		this->_questions[i] = repo._questions[i]->clone();
	}
}

void QuestionsRepository::freeDynamic() {
	for (size_t i = 0; i < this->_size; i++){
		delete this->_questions[i];
	}

	delete[] this->_questions;
	this->_questions = nullptr;

	
}
