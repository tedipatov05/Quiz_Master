#include "../../headers/services/QuizService.h"
#include "../../headers/Context.h"

Quiz* QuizService::getQuizById(Context& ctx, int id){

	for (size_t i = 0; i < ctx.quizzes.size(); i++){
		if (ctx.quizzes[i].id() == id){
			return &ctx.quizzes[i];
		}
	}

	return nullptr;
}
