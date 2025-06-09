#pragma once
#include "Question.h"
class QuestionsRepository
{
public:

	QuestionsRepository();
	QuestionsRepository(const QuestionsRepository& repo);
	QuestionsRepository& operator=(const QuestionsRepository& other);
	~QuestionsRepository();

	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;


	void addQuestion(const Question* question);
	const Question& operator[](size_t index) const;

	size_t size() const;

private:

	Question** _questions;
	size_t _size;
	size_t _capacity;

	void copyDynamicMemory(const QuestionsRepository& repo);
	void freeDynamic();
	void resize(size_t newCap);
	void add(const Question* question);

};

