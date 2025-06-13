#include "../../headers/services/QuizService.h"
#include "../../headers/Context.h"
#include "../../headers/commands/Command.h"

Quiz* QuizService::getQuizById(Context& ctx, int id) {

	for (size_t i = 0; i < ctx.quizzes.size(); i++) {
		if (ctx.quizzes[i].id() == id) {
			return &ctx.quizzes[i];
		}
	}

	return nullptr;
}

void QuizService::printPendingQuizzes(const Context& ctx) {

	if (ctx.quizzes.size() == 0) {
		std::cout << NoQuizzes << std::endl;
	}

	for (size_t i = 0; i < ctx.quizzes.size(); i++) {
		if (ctx.quizzes[i].active() && !ctx.quizzes[i].approved()) {
			User* user = ctx.users.findUser(ctx.quizzes[i].creator());

			std::cout << "[" << ctx.quizzes[i].id() << "] " << ctx.quizzes[i].name() << " by " << user->getUsername();
		}
	}
}

void QuizService::printUserQuizzes(const Vector<MyString>& data, const MyString& message, bool isNewLined) {
	if (data.size() == 0) {
		return;
	}

	std::cout << message;

	if (isNewLined) {
		std::cout << std::endl;
	}

	if (data.size() == 0) {
		std::cout << NoDataToDisplay << std::endl;
	}

	for (size_t i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";

		if (isNewLined) {
			std::cout << std::endl;
		}
	}

}

void QuizService::addQuiz(Context& ctx) {
	Quiz* quiz = new Quiz(ctx.currentUserId, ctx.nextQuizId);
	ctx.nextQuizId++;

	quiz->read();


	ctx.quizzes.push_back(*quiz);
	writeObjectToBinaryFile(quizzesFile, *quiz);

	delete quiz;

}


int QuizService::getQuizLikes(const Context& ctx, int quizId) {

	int likes = 0;

	for (size_t i = 0; i < ctx.likedQuizzes.size(); i++) {
		if (quizId == ctx.likedQuizzes[i].getQuizId() && ctx.likedQuizzes[i].isActive()) {
			likes++;
		}
	}

	return likes;

}

MyString QuizService::getQuizCreatorName(const Context& ctx, const Quiz& quiz) {
	User* user = ctx.users.findUser(quiz.creator());

	return user->getUsername();
}


void QuizService::printQuizzesInfo(const Context& ctx, const Vector<Quiz>& quizzes) {

	for (size_t i = 0; i < quizzes.size(); i++) {
		std::cout << quizzes[i].id() << " | " << quizzes[i].name() << " | " << getQuizCreatorName(ctx, quizzes[i])
			<< " | " << quizzes[i].questionsCount() << " Questions | " << getQuizLikes(ctx, quizzes[i].id()) << " Likes" << std::endl;
	}
}

bool QuizService::isQuizLiked(const Context& ctx, const Quiz* quiz) {

	for (size_t i = 0; i < ctx.likedQuizzes.size(); i++) {
		if (ctx.likedQuizzes[i].getQuizId() == quiz->id() && ctx.likedQuizzes[i].getUserId() == ctx.currentUserId && ctx.likedQuizzes[i].isActive()) {
			return true;
		}
	}

	return false;

}


void QuizService::likeQuiz(Context& ctx, const Quiz* quiz) {
	UserQuiz* like = findLike(ctx, quiz);
	if (like != nullptr) {
		UserQuiz oldLike(*like);

		like->changeActive();

		updateObjectInBinaryFile(likedQuizzesFile, oldLike, *like);

	}
	else {
		UserQuiz newLike(ctx.currentUserId, quiz->id());

		ctx.likedQuizzes.push_back(newLike);

		writeObjectToBinaryFile(likedQuizzesFile, newLike);
	}

}

UserQuiz* QuizService::findLike(Context& ctx, const Quiz* quiz) {
	UserQuiz* like = nullptr;

	for (size_t i = 0; i < ctx.likedQuizzes.size(); i++) {
		if (ctx.likedQuizzes[i].getQuizId() == quiz->id() && ctx.likedQuizzes[i].getUserId() == ctx.currentUserId && ctx.likedQuizzes[i].isActive()) {
			like = &ctx.likedQuizzes[i];
			break;
		}
	}

	return like;
}


void QuizService::unlikeQuiz(Context& ctx, const Quiz* quiz) {
	UserQuiz* like = findLike(ctx, quiz);

	UserQuiz oldLike(*like);
	like->changeActive();
	updateObjectInBinaryFile(likedQuizzesFile, oldLike, *like);
}

void QuizService::addQuizToFavourite(Context& ctx, const Quiz* quiz){
	UserQuiz* favourite = findFavouriteQuiz(ctx, quiz);
	if (favourite != nullptr) {
		UserQuiz oldFav(*favourite);

		favourite->changeActive();

		updateObjectInBinaryFile(favouriteQuizzesFile, oldFav, *favourite);

	}
	else {
		UserQuiz newFavourite(ctx.currentUserId, quiz->id());

		ctx.favouriteQuizzes.push_back(newFavourite);

		writeObjectToBinaryFile(favouriteQuizzesFile, newFavourite);
	}
}

UserQuiz* QuizService::findFavouriteQuiz(Context& ctx, const Quiz* quiz){
	UserQuiz* favourite = nullptr;

	for (size_t i = 0; i < ctx.favouriteQuizzes.size(); i++) {
		if (ctx.favouriteQuizzes[i].getQuizId() == quiz->id() && ctx.favouriteQuizzes[i].getUserId() == ctx.currentUserId && ctx.favouriteQuizzes[i].isActive()) {
			favourite = &ctx.favouriteQuizzes[i];
			break;
		}
	}

	return favourite;
}

bool QuizService::isQuizAddedToFavourite(const Context& ctx, const Quiz* quiz){
	for (size_t i = 0; i < ctx.favouriteQuizzes.size(); i++) {
		if (ctx.favouriteQuizzes[i].getQuizId() == quiz->id() && ctx.favouriteQuizzes[i].getUserId() == ctx.currentUserId && ctx.favouriteQuizzes[i].isActive()) {
			return true;
		}
	}

	return false;
}

void QuizService::removeFromFavourite(Context& ctx, const Quiz* quiz){
	UserQuiz* fav = findLike(ctx, quiz);

	UserQuiz oldFav(*fav);
	fav->changeActive();
	updateObjectInBinaryFile(likedQuizzesFile, oldFav, *fav);
}







