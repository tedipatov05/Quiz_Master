#include "../../headers/commands/ViewReportsCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/ReportService.h"

ViewReportsCommand::ViewReportsCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void ViewReportsCommand::execute(){

	try{
		Validate::checkPermission(ctx, UserType::Admin);
	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	ReportService::printReports(ctx);

}

