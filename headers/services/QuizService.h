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

};

