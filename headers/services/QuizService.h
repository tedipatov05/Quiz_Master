#pragma once
#include "../quizes/Quiz.h"
#include "../Context.h"

class QuizService{

public:

	static Quiz* getQuizById(Context& ctx, int id);
	static void printPendingQuizzes(const Context& ctx);
	static void printUserQuizzes(const Vector<MyString>& data, const MyString& message, bool isNewLined);
	static void addQuiz(Context& ctx);
	static int getQuizLikes(const Context& ctx, int quizId);
	static void printQuizzesInfo(const Context& ctx, const Vector<Quiz>& quizzes);
	static MyString getQuizCreatorName(const Context& ctx, const Quiz& quiz);


	static void likeQuiz(Context& ctx, const Quiz* quiz);
	static bool isQuizLiked(const Context& ctx, const Quiz* quiz);
	static void unlikeQuiz(Context& ctx, const Quiz* quiz);
	static UserQuiz* findLike(Context& ctx, const Quiz* quiz);

	static void addQuizToFavourite(Context& ctx, const Quiz* quiz);
	static bool isQuizAddedToFavourite(const Context& ctx, const Quiz* quiz);
	static void removeFromFavourite(Context& ctx, const Quiz* quiz);
	static UserQuiz* findFavouriteQuiz(Context& ctx, const Quiz* quiz);
	static void startQuiz(Context& ctx, User* user,  int id, QuizMode mode, bool isShuffle);
	static void saveQuizInTextFile(const Quiz* quiz, const User* creator,  const MyString& filename);

	static void rejectQuiz(Context& ctx, Quiz* quiz, const MyString& reason);

	static void reportQuiz(Context& ctx, const Quiz* quiz, MyString reason, const MyString& creator, const MyString& reporter);

	//static QuizAttempt* isTriedAlready()
};

