#pragma once

class Question;

enum class QuestionType {
	TrueOrFalse,
	ShortAnswer,
	SingleChoice,
	MatchingPairs,
	MultipleChoice,
	Unknown
};

class QuestionFactory{

public:
	static Question* createQuestion(QuestionType type);

};

