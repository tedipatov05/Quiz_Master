#include "../../headers/services/QuizService.h"
#include "../../headers/Context.h"
#include "../../headers/helpers/FileHelper.hpp"
#include "../../headers/services/MessageService.h"

Quiz* QuizService::getQuizById(Context& ctx, int id) {

	for (size_t i = 0; i < ctx.quizzes.size(); i++) {
		if (ctx.quizzes[i].id() == id) {
			return &ctx.quizzes[i];
		}
	}

	return nullptr;
}

void QuizService::printPendingQuizzes(const Context& ctx) {

	bool empty = true;
	for (size_t i = 0; i < ctx.quizzes.size(); i++) {
		if (ctx.quizzes[i].active() && !ctx.quizzes[i].approved()) {
			empty = false;
			User* user = ctx.users.findUser(ctx.quizzes[i].creator());
			std::cout << "   ";
			std::cout << "[id " << ctx.quizzes[i].id() << "] " << ctx.quizzes[i].name() << " by " << user->getUsername() << std::endl;
		}
	}

	if (empty){
		std::cout << NoDataToDisplay << std::endl;
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
	std::cout << std::endl;
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

	bool empty = true;

	for (size_t i = 0; i < quizzes.size(); i++) {
		if (quizzes[i].approved()){
			empty = false;
			std::cout << "    ";
			std::cout << quizzes[i].id() << " | " << quizzes[i].name() << " | " << getQuizCreatorName(ctx, quizzes[i])
				<< " | " << quizzes[i].questionsCount() << " Questions | " << getQuizLikes(ctx, quizzes[i].id()) << " Likes" << std::endl;
		}
	}

	if (empty){
		std::cout << NoDataToDisplay << std::endl;
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
	UserQuiz* fav = findFavouriteQuiz(ctx, quiz);

	UserQuiz oldFav(*fav);
	fav->changeActive();
	updateObjectInBinaryFile(favouriteQuizzesFile, oldFav, *fav);
}

void QuizService::startQuiz(Context& ctx, User* user,  int id, QuizMode mode, bool isShuffle){
	if (mode == QuizMode::Unknown){
		throw std::invalid_argument(InvalidFormat.data());
	}

	Quiz* quiz = getQuizById(ctx, id);

	if (quiz == nullptr){
		throw std::invalid_argument(QuizNoExists.data());
	}
	if (quiz->creator() == ctx.currentUserId){
		throw std::invalid_argument(NotStartYourOwnQuiz.data());
	}


	QuizAttempt attempt = quiz->start(mode, isShuffle, ctx.currentUserId);
	ctx.quizAttempts.push_back(attempt);
	writeObjectToBinaryFile(quizAttemptsFile, attempt);

	user->increasePoints(attempt.getPoints());
	ctx.areUsersChanged = true;
	
}

void QuizService::saveQuizInTextFile(const Quiz* quiz, const User* creator, const MyString& filename){

	std::ofstream ofs(filename.data());
	if (!ofs.is_open()){
		throw std::invalid_argument(FileNotOpened.data());
	}

	quiz->saveInTextFile(ofs, creator);
}

void QuizService::reportQuiz(Context& ctx, const Quiz* quiz, MyString reason, const MyString& creator, const MyString& reporter){

	Report report(reporter, creator, quiz->id(), reason);

	ctx.reports.push_back(report);

	writeObjectToBinaryFile(reportsFile, report);

	
}


void QuizService::rejectQuiz(Context& ctx, Quiz* quiz, const MyString& reason){

	Quiz oldQuiz(*quiz);
	quiz->reject();
	updateObjectInBinaryFile(quizzesFile, oldQuiz, *quiz);
	//MyString reason = getReasonFromBuffer(data);
	MessageService::sendMessage(ctx, quiz->creator(), reason);
}








