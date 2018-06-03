#ifndef SPREADSHEETMODEL_H_
#define SPREADSHEETMODEL_H_

#include "subject.h"
#include <iostream>
#include <string_view>

class SpreadsheetModel : public Subject
{
public:
	void changeCellValue(std::string_view column, const int row, const double value)
	{
		std::cout << "Cell [" << column << ", " << row << "] = " << value << std::endl;
		// Change value of spreadsheet cell, and then notify
		notifyAllObservers();
	}
};

#endif /* SPREADSHEETMODEL_H_ */
