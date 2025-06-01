#pragma once

class Question;

enum class QuestionType {
	TrueOrFalse,
	ShortAnswer,
	SingleChoice,
	MatchingPairs,
	MultipleChoice
};

class QuestionFactory{

public:
	static Question* createQuestion(QuestionType type);

};

