#include "../../headers/questions/QuestionFactory.h"

#include "../../headers/questions/MatchingPairsQuestions.h"
#include "../../headers/questions/MultipleChoiceQuestion.h"
#include "../../headers/questions/ShortAnswerQuestion.h"
#include "../../headers/questions/SingleChoiceQuestion.h"
#include "../../headers/questions/TrueOrFlaseQuestion.h"

Question* QuestionFactory::createQuestion(QuestionType type){
	switch (type){
		case QuestionType::ShortAnswer:
			return new ShortAnswerQuestion();
		case QuestionType::MatchingPairs:
			return new MatchingPairsQuestion();
		case QuestionType::SingleChoice:
			return new SingleChoiceQuestion();
		case QuestionType::TrueOrFalse:
			return new TrueOrFalseQuestion();
		case QuestionType::MultipleChoice:
			return new MultipleChoiceQuestion();

		default:
			return nullptr;

	}
}
