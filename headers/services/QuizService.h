#pragma once
#include "../quizes/Quiz.h"
#include "../Context.h"

class QuizService{

public:

	static Quiz* getQuizById(Context& ctx, int id);

};

