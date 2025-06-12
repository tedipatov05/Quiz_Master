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

void QuizService::printPendingQuizzes(const Context& ctx){

	if (ctx.quizzes.size() == 0){
		std::cout << NoQuizzes << std::endl;
	}

	for (size_t i = 0; i < ctx.quizzes.size(); i++){
		if (ctx.quizzes[i].active() && !ctx.quizzes[i].approved()){
			User* user = ctx.users.findUser(ctx.quizzes[i].creator());

			std::cout << "[" << ctx.quizzes[i].id() << "] " << ctx.quizzes[i].name() << " by " << user->getUsername();
		}
	}
}

