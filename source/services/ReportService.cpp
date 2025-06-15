#include "../../headers/services/ReportService.h"

void ReportService::printReports(const Context& ctx){

	if (ctx.reports.size() == 0){
		std::cout << NoDataToDisplay << std::endl;
		return;
	}

	for (size_t i = 0; i < ctx.reports.size(); i++){
		ctx.reports[i].print(std::cout);
	}
}
