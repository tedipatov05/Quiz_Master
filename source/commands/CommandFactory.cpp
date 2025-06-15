#include "../../headers/commands/CommandFactory.h"


Command* CommandFactory::generateCommand(const MyString& buffer, Context& ctx) {
	Vector<MyString> data = Command::split(buffer, " ");
	MyString cmd = data[0].toLower();

	if (cmd == "login") {
		return new LoginCommand(buffer, ctx);
	}
	else if (cmd == "logout"){
		return new LogoutCommand(buffer, ctx);
	}
	else if (cmd == "pending"){
		return new PendingQuizzesCommand(buffer, ctx);
	}
	else if (cmd == "approve-quiz"){
		return new ApproveQuizCommand(buffer, ctx);
	}
	else if (cmd == "reject-quiz"){
		return new RejectQuizCommand(buffer, ctx);
	}
	else if (cmd == "view-reports"){
		return new ViewReportsCommand(buffer, ctx);
	}
	else if (cmd == "remove-quiz"){
		return new RemoveQuizCommand(buffer, ctx);
	}
	else if (cmd == "ban"){
		return new BanUserCommand(buffer, ctx);
	}
	else if (cmd == "sign-up"){
		return new SignUpCommand(buffer, ctx);
	}
	else if (cmd == "view-profile"){
		return new ViewProfileCommand(buffer, ctx);
	}
	else if (cmd == "view-challenges"){
		return new ChallengesCommand(buffer, ctx);
	}
	else if (cmd == "view-finished-challenges"){
		return new ViewFinishedChallengesCommand(buffer, ctx);
	}
	else if (cmd == "view"){
		return new ViewUserCommand(buffer, ctx);
	}
	else if (cmd == "messages"){
		return new MessagesCommand(buffer, ctx);
	}
	else if (cmd == "create-quiz"){
		return new CreateQuizCommand(buffer, ctx);
	}
	else if (cmd == "quizzes" && data.size() == 1){
		return new ViewQuizzesCommand(buffer, ctx);
	}
	else if (cmd == "quizzes" && data.size() == 2){
		return new ViewUserQuizzesCommand(buffer, ctx);
	}
	else if (cmd == "like-quiz") {
		return new LikeQuizCommand(buffer, ctx);
	}
	else if (cmd == "unlike-quiz"){
		return new UnlikeQuizCommand(buffer, ctx);
	}
	else if (cmd == "add-to-favs"){
		return new AddToFavouriteCommand(buffer, ctx);
	}
	else if (cmd == "remove-from-favs"){
		return new RemoveFromFavouriteCommand(buffer, ctx);
	}
	else if (cmd == "start-quiz"){
		return new StartQuizCommand(buffer, ctx);
	}
	else if (cmd == "save-quiz"){
		return new SaveQuizCommand(buffer, ctx);
	}
	else if (cmd == "report-quiz"){
		return new ReportQuizCommand(buffer, ctx);
	}
	else{
		return nullptr;
	}

}

