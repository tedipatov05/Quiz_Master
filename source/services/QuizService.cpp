#include "../../headers/services/QuizService.h"
#include "../../headers/Context.h"
#include "../../headers/commands/Command.h"

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

void QuizService::printUserQuizzes(const Vector<MyString>& data, const MyString& message, bool isNewLined){
	if (data.size() == 0){
		return;
	}

	std::cout << message;

	if (isNewLined){
		std::cout << std::endl;
	}

	if (data.size() == 0){
		std::cout << NoDataToDisplay << std::endl;
	}

	for (size_t i = 0; i < data.size(); i++){
		std::cout << data[i] << " ";

		if (isNewLined){
			std::cout << std::endl;
		}
	}

}

void QuizService::addQuiz(Context& ctx){
	Quiz* quiz = new Quiz(ctx.currentUserId, ctx.nextQuizId);
	ctx.nextQuizId++;

	quiz->read();


	ctx.quizzes.push_back(*quiz);
	writeObjectToBinaryFile(quizzesFile, *quiz);

	delete quiz;

}


int QuizService::getQuizLikes(const Context& ctx, int quizId){

	int likes = 0;

	for (size_t i = 0; i < ctx.likedQuizzes.size(); i++){
		if (quizId == ctx.likedQuizzes[i].getQuizId()){
			likes++;
		}
	}

	return likes;
	
}

MyString QuizService::getQuizCreatorName(const Context& ctx, const Quiz& quiz){
	User* user = ctx.users.findUser(quiz.creator());

	return user->getUsername();
}


void QuizService::printQuizzesInfo(const Context& ctx, const Vector<Quiz>& quizzes){

	for (size_t i = 0; i < quizzes.size(); i++){
		std::cout << quizzes[i].id() << " | " << quizzes[i].name() << " | " << getQuizCreatorName(ctx, quizzes[i])
			<< " | " << quizzes[i].questionsCount() << " Questions | " << getQuizLikes(ctx, quizzes[i].id()) << " Likes" << std::endl;
	}
}


